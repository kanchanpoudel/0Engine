#pragma once
#include <string>

#ifdef LIE_DEBUG

namespace Lie
{
	namespace Debug
	{
		static std::string __loggingData("");
		void AddLog(const std::string& log);
		void Log();
	}
}

#else

namespace Lie
{
	namespace Debug
	{
		void AddLog(const std::string& log);
		void Log();
	}
}

#endif