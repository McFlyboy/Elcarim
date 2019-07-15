#pragma once

#include <string>

namespace Elcarim {
	class ErrorHandler {
	public:
		void write(const std::string& errorMessage);
		~ErrorHandler();
		static ErrorHandler* createInstance();
		static ErrorHandler* getInstance();
	private:
		static ErrorHandler* s_instance;

		ErrorHandler();
	};
}
