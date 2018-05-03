#include "Debugger\console_logger.h"
#include <iostream>

#ifdef ENGINE_DEBUG 

namespace s00nya
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

namespace s00nya
{
	void Debug::AddLog(const std::string& log){}
	void Debug::Log(){}
}

#endif