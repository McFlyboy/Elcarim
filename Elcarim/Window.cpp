#include <exception>
#include <stdexcept>
#include <string>

#include "ErrorHandler.hpp"
#include "ResourceLoader.hpp"
#include "Window.hpp"

namespace Elcarim {
	int Window::s_newInstanceWidth = 800;
	int Window::s_newInstanceHeight = 600;
	const char* Window::s_newInstanceTitle = "";
	bool Window::s_newInstanceFullscreen = false;
	Window* Window::s_instance = nullptr;

	Window::Window() {
		if (!glfwInit()) {
			throw std::runtime_error("Failed to initialize GLFW\n");
		}
		if (!(m_activeMonitor = glfwGetPrimaryMonitor())) {
			throw std::runtime_error("Could not find the primary monitor\n");
		}
		glfwWindowHint(GLFW_VISIBLE, false);
		glfwWindowHint(GLFW_RESIZABLE, false);
		glfwWindowHint(GLFW_FOCUS_ON_SHOW, true);
		if (!(m_window = glfwCreateWindow(s_newInstanceWidth, s_newInstanceHeight, s_newInstanceTitle, s_newInstanceFullscreen ? m_activeMonitor : nullptr, nullptr))) {
			throw std::runtime_error("Could not create the GLFW window\n");
		}
		glfwMakeContextCurrent(m_window);
		if (!glfwGetCurrentContext()) {
			throw std::runtime_error("Failed to make context current for the window\n");
		}
		glfwGetWindowSize(m_window, &m_width, &m_height);
		m_monitorVideoMode = glfwGetVideoMode(m_activeMonitor);
		center();
		getKeyboard();
		getMouse();
		getGamepad();
	}
	const int Window::getActiveMonitorWidth() {
		return m_monitorVideoMode->width;
	}
	const int Window::getActiveMonitorHeight() {
		return m_monitorVideoMode->height;
	}
	const int Window::getActiveMonitorRefreshRate() {
		return m_monitorVideoMode->refreshRate;
	}
	const bool Window::shouldClose() const {
		return glfwWindowShouldClose(m_window);
	}
	void Window::close() {
		glfwSetWindowShouldClose(m_window, true);
	}
	void Window::center() {
		glfwSetWindowPos(
			m_window,
			(m_monitorVideoMode->width - m_width) / 2,
			(m_monitorVideoMode->height - m_height) / 2
		);
	}
	void Window::show() {
		glfwShowWindow(m_window);
		m_focused = true;
	}
	void Window::setIconImages(const char* const smallx16, const char* const mediumx32, const char* const largex48) {
		const char* const filenames[3] = { smallx16, mediumx32, largex48 };
		std::string path = "window_icons/";
		GLFWimage icons[3];
		for (int i = 0; i < 3; ++i) {
			int colorComp = 0;
			icons[i].pixels = Util::ResourceLoader::loadImage(path + filenames[i], icons[i].width, icons[i].height, colorComp);
		}
		glfwSetWindowIcon(m_window, 3, icons);
		for (GLFWimage& icon : icons) {
			Util::ResourceLoader::freeImage(icon.pixels);
		}
	}
	const bool Window::isFocused() const {
		return m_focused;
	}
	const bool Window::isFullscreen() const {
		return glfwGetWindowMonitor(m_window);
	}
	void Window::setFullscreen(const bool fullscreen) {
		GLFWmonitor* monitor = m_activeMonitor;
		int xpos = 0;
		int ypos = 0;
		int width = m_monitorVideoMode->width;
		int height = m_monitorVideoMode->height;
		if (!fullscreen) {
			monitor = nullptr;
			xpos = (m_monitorVideoMode->width - m_width) / 2;
			ypos = (m_monitorVideoMode->height - m_height) / 2;
			width = m_width;
			height = m_height;
		}
		glfwSetWindowMonitor(m_window, monitor, xpos, ypos, width, height, GLFW_DONT_CARE);
	}
	void Window::setVSync(const bool vsync) {
		glfwSwapInterval(vsync);
	}
	void Window::update() {
		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}
	Input::Device::Keyboard* const Window::getKeyboard() {
		if (!m_keyboard) {
			m_keyboard = new Input::Device::Keyboard(m_window);
		}
		return m_keyboard;
	}
	Input::Device::Mouse* const Window::getMouse() {
		if (!m_mouse) {
			m_mouse = new Input::Device::Mouse(m_window);
		}
		return m_mouse;
	}
	Input::Device::Gamepad* const Window::getGamepad() {
		if (!m_gamepad) {
			m_gamepad = Input::Device::Gamepad::getInstance();
		}
		return m_gamepad;
	}
	Window::~Window() {
		delete m_keyboard;
		m_keyboard = nullptr;

		delete m_mouse;
		m_mouse = nullptr;

		delete m_gamepad;
		m_gamepad = nullptr;

		glfwSetWindowFocusCallback(m_window, nullptr);

		glfwDestroyWindow(m_window);
		m_window = nullptr;

		glfwTerminate();
		m_monitorVideoMode = nullptr;
		m_activeMonitor = nullptr;
		s_instance = nullptr;
	}
	void Window::setNewInstanceSettings(const int width, const int height, const char* const title, const bool fullscreen) {
		s_newInstanceWidth = width;
		s_newInstanceHeight = height;
		s_newInstanceTitle = title;
		s_newInstanceFullscreen = fullscreen;
	}
	Window* const Window::getInstance() {
		if (!s_instance) {
			try {
				s_instance = new Window();
				glfwSetWindowFocusCallback(s_instance->m_window, [](GLFWwindow* window, int focused) {
					s_instance->m_focused = focused;
					Input::Device::Gamepad* gamepad = s_instance->getGamepad();
					gamepad->setFocued(focused);
					if (!focused) {
						gamepad->resetAllAxisStates();
						gamepad->resetAllButtonStates();
					}
				});
				return s_instance;
			}
			catch (std::exception& e) {
				ErrorHandler::getInstance()->write(e.what());
				delete s_instance;
				s_instance = nullptr;
			}
		}
		return s_instance;
	}
}
