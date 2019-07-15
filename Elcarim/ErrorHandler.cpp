#include <iostream>

#include <GLFW/glfw3.h>

#include "ErrorHandler.hpp"

namespace Elcarim {
	ErrorHandler* ErrorHandler::s_instance = nullptr;

	ErrorHandler::ErrorHandler() {
		glfwSetErrorCallback([](int error, const char* description) {
			std::cerr << "Error " << error << ":\n" << description;
		});
	}
	void ErrorHandler::write(const std::string& errorMessage) {
		std::cerr << errorMessage;
	}
	ErrorHandler::~ErrorHandler() {
		glfwSetErrorCallback(nullptr);
		s_instance = nullptr;
	}
	ErrorHandler* ErrorHandler::createInstance() {
		if (!s_instance) {
			return s_instance = new ErrorHandler();
		}
		return nullptr;
	}
	ErrorHandler* ErrorHandler::getInstance() {
		return s_instance;
	}
}
