#pragma once
#include <string>

#ifdef ENGINE_DEBUG

namespace s00nya
{
	namespace Debug
	{
		static std::string __loggingData("");
		void AddLog(const std::string& log);
		void Log();
	}
}

#else

namespace s00nya
{
	namespace Debug
	{
		void AddLog(const std::string& log);
		void Log();
	}
}

#endif