#pragma once

#include <string>

namespace Elcarim {
	class ErrorHandler {
	public:
		void write(const std::string& errorMessage);
		~ErrorHandler();
		ErrorHandler(const ErrorHandler&) = delete;
		void operator=(const ErrorHandler&) = delete;
		static ErrorHandler& getInstance();
	private:
		ErrorHandler();
	};
}
