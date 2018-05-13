#include "Debugger\logger.h"
#include <chrono>
#include <iomanip>
#include <ctime>

#ifdef ENGINE_DEBUG 

namespace s00nya
{
	
	std::stringstream Debug::m_s_logs;
	std::fstream Debug::m_s_logFile;

	void Debug::Initialize()
	{
		Debug::m_s_logFile.open("./s00nyaLogs.log", std::ios::out | std::ios::binary);
		auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		std::tm time;
		localtime_s(&time, &now);
		std::stringstream timeStream;
		timeStream << "s00nya logs : [ " << std::put_time(&time, "%Y-%m-%d %X") << " ]" << "\n\n";
		m_s_logFile << timeStream.str();
	}

	void Debug::ShutDown()
	{
		auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		std::tm time;
		localtime_s(&time, &now);
		std::stringstream timeStream;
		timeStream << "\nProgram end time : [ " << std::put_time(&time, "%Y-%m-%d %X") << " ]";
		m_s_logFile << timeStream.str();
		Debug::m_s_logFile.close();
	}

	void Debug::Add(std::string logStr, int level)
	{
		switch (level)
		{
		case Debug::S00NYA_LOG_INFO:
			Debug::m_s_logs << "INFO :: " << logStr << '\n';
			return;
		case Debug::S00NYA_LOG_WARNING:
			Debug::m_s_logs << "WARNING :: " << logStr << '\n';
			return;
		case Debug::S00NYA_LOG_ERROR:
			Debug::m_s_logs << "ERROR :: " << logStr << '\n';
			return;
		default:
			Debug::m_s_logs << "UNSPECIFIED :: " << logStr << '\n';
		}
	}

	void Debug::Add(std::stringstream log, int level)
	{
		Debug::Add(log.str(), level);
	}

	void Debug::Log(bool logToConsole, bool logToFile)
	{
		if (logToConsole)
		{
			std::cout << Debug::m_s_logs.str();
		}
		if (logToFile)
		{
			m_s_logFile << Debug::m_s_logs.str();
		}
		Debug::m_s_logs.str(std::string());
	}

}

#else

namespace s00nya
{
	
	void Debug::Initialize() {}
	void Debug::ShutDown() {}
	void Debug::Add(std::string logStr, int level){}
	void Debug::Add(std::stringstream log, int level){}
	void Debug::Log(bool logToConsole, bool logToFile){}

}

#endif