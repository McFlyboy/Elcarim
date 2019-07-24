#pragma once

#include <string>

namespace Elcarim {
	namespace Util {
		class ErrorHandler {
		public:
			void write(const std::string& errorMessage);
			~ErrorHandler();
			static ErrorHandler* getInstance();
		private:
			static ErrorHandler* s_instance;

			ErrorHandler();
		};
	}
}
