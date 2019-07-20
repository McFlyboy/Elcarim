#include <exception>
#include <stdexcept>

#include "ErrorHandler.hpp"
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
		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
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
		glfwShowWindow(m_window);
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
	const bool Window::isFullscreen() const {
		return glfwGetWindowMonitor(m_window);
	}
	void Window::setFullscreen(bool fullscreen) {
		glfwSetWindowMonitor(m_window, fullscreen ? m_activeMonitor : nullptr, (m_monitorVideoMode->width - m_width) / 2, (m_monitorVideoMode->height - m_height) / 2, m_width, m_height, GLFW_DONT_CARE);
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
	Window::~Window() {
		delete m_keyboard;
		m_keyboard = nullptr;
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
	Window* Window::getInstance() {
		if (!s_instance) {
			try {
				s_instance = new Window();
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
