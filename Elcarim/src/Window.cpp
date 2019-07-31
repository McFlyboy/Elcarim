#include <exception>
#include <stdexcept>
#include <string>
#include <iostream>

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
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);
#endif
		glfwWindowHint(GLFW_VISIBLE, false);
		glfwWindowHint(GLFW_RESIZABLE, false);
		glfwWindowHint(GLFW_FOCUS_ON_SHOW, true);
		if (!(m_window = glfwCreateWindow(s_newInstanceWidth, s_newInstanceHeight, s_newInstanceTitle, s_newInstanceFullscreen ? m_activeMonitor : nullptr, nullptr))) {
			throw std::runtime_error("Could not create the GLFW window\n");
		}
		glfwSetWindowUserPointer(m_window, this);
		glfwSetWindowFocusCallback(m_window, [](GLFWwindow* window, int focused) {
			Window* instance = (Window*)glfwGetWindowUserPointer(window);
			instance->m_focused = focused;
			Input::Device::Gamepad* gamepad = instance->getGamepad();
			gamepad->setFocued(focused);
			if (!focused) {
				gamepad->resetAllAxisStates();
				gamepad->resetAllButtonStates();
			}
		});
		glfwGetWindowSize(m_window, &m_width, &m_height);
		m_monitorVideoMode = glfwGetVideoMode(m_activeMonitor);
		center();
		m_renderer = new Graphics::Renderer(m_window, m_width, m_height);
		m_keyboard = new Input::Device::Keyboard(m_window);
		m_mouse = new Input::Device::Mouse(m_window);
		m_gamepad = Input::Device::Gamepad::getInstance();
	}
	const int Window::getActiveMonitorWidth() const {
		return m_monitorVideoMode->width;
	}
	const int Window::getActiveMonitorHeight() const {
		return m_monitorVideoMode->height;
	}
	const int Window::getActiveMonitorRefreshRate() const {
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
			icons[i].pixels = Util::ResourceLoader::loadImage(path + filenames[i], icons[i].width, icons[i].height, colorComp, false);
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
		m_renderer->setViewPort(width, height);
	}
	void Window::update() {
		m_timer.updatePerSecCounters();
		glfwPollEvents();
		++m_timer.updateCount;
	}
	void Window::updateFrame() {
		m_renderer->swapBuffers();
		++m_timer.frameCount;
	}
	Graphics::Renderer* const Window::getRenderer() const {
		return m_renderer;
	}
	Input::Device::Keyboard* const Window::getKeyboard() const {
		return m_keyboard;
	}
	Input::Device::Mouse* const Window::getMouse() const {
		return m_mouse;
	}
	Input::Device::Gamepad* const Window::getGamepad() const {
		return m_gamepad;
	}
	const double Window::getTime() const {
		return m_timer.getTime();
	}
	const double Window::getDeltaTime() {
		return m_timer.getDeltaTime();
	}
	Window::~Window() {
		delete m_keyboard;
		m_keyboard = nullptr;

		delete m_mouse;
		m_mouse = nullptr;

		delete m_gamepad;
		m_gamepad = nullptr;

		delete m_renderer;
		m_renderer = nullptr;

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
			}
			catch (std::exception& e) {
				ErrorHandler::getInstance()->write(e.what());
				delete s_instance;
				s_instance = nullptr;
			}
		}
		return s_instance;
	}
	const double Window::InternalTimer::getTime() const {
		return glfwGetTime();
	}
	const double Window::InternalTimer::getDeltaTime() {
		double currentTime = getTime();
		double deltaTime = currentTime - previousTime;
		previousTime = currentTime;
		return deltaTime;
	}
	void Window::InternalTimer::updatePerSecCounters() {
		if (getTime() - lastSecondTime >= 1.0) {
			++lastSecondTime;
			fps = frameCount;
			frameCount = 0;
			ups = updateCount;
			updateCount = 0;
			std::cout << "FPS: " << fps << " - UPS: " << ups << std::endl;
		}
	}
}
