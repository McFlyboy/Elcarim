#include <exception>
#include <stdexcept>

#include "ErrorHandler.hpp"
#include "Window.hpp"

namespace Elcarim {
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
		if (!(m_window = glfwCreateWindow(800, 600, "", nullptr, nullptr))) {
			throw std::runtime_error("Could not create the GLFW window\n");
		}
		glfwMakeContextCurrent(m_window);
		if (!glfwGetCurrentContext) {
			throw std::runtime_error("Failed to make context current for the window\n");
		}
		glfwShowWindow(m_window);
	}
	Window::~Window() {
		glfwDestroyWindow(m_window);
		glfwTerminate();
		m_activeMonitor = nullptr;
		s_instance = nullptr;
	}
	void Window::setNewInstanceSettings() {
		
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
