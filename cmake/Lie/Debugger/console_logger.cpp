#include "Debugger\console_logger.h"
#include <iostream>

#ifdef LIE_DEBUG 

namespace Lie
{
	void Debug::AddLog(const std::string& log)
	{
		__loggingData += '\n' + log;
	}
	void Debug::Log()
	{
		std::cout << __loggingData;
		__loggingData = "";
	}
}

#else

namespace Lie
{
	void Debug::AddLog(const std::string& log){}
	void Debug::Log(){}
}

#endif