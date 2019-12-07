#include "ErrorHandler.hpp"

#include <iostream>

#include <GLFW/glfw3.h>

namespace Elcarim {
	ErrorHandler* ErrorHandler::s_instance = nullptr;

	ErrorHandler::ErrorHandler() {
		glfwSetErrorCallback([](int error, const char* description) {
			std::cerr << "Error " << error << ":\n" << description << "\n\n";
		});
	}
	void ErrorHandler::write(const std::string& errorMessage) {
		std::cerr << errorMessage;
	}
	ErrorHandler::~ErrorHandler() {
		glfwSetErrorCallback(nullptr);
		s_instance = nullptr;
	}
	ErrorHandler* ErrorHandler::getInstance() {
		if (!s_instance) {
			s_instance = new ErrorHandler();
		}
		return s_instance;
	}
}
