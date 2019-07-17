#pragma once

#include <string>

namespace Elcarim {
	class ErrorHandler {
	public:
		void write(const std::string& const errorMessage);
		~ErrorHandler();
		static ErrorHandler* getInstance();
	private:
		static ErrorHandler* s_instance;

		ErrorHandler();
	};
}
