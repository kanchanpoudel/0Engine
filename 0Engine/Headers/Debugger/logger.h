#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#ifdef ENGINE_DEBUG

namespace s00nya
{

	class Debug
	{
	private:
		static std::stringstream m_s_logs;
		static std::fstream m_s_logFile;

		Debug() = delete;
		void operator=(const Debug& debug) = delete;
		Debug(const Debug& debug) = delete;

	public:
		enum { S00NYA_LOG_INFO, S00NYA_LOG_ERROR, S00NYA_LOG_WARNING };

		static void Initialize();
		static void ShutDown();

		static void Add(std::string logStr, int level);
		static void Add(std::stringstream log, int level);
		static void Log(bool logToConsole = true, bool logToFile = false);
	};

}

#else

namespace s00nya
{
	
	class Debug
	{
	private:
		Debug() = delete;
		void operator=(const Debug& debug) = delete;
		Debug(const Debug& debug) = delete;

	public:
		enum { S00NYA_LOG_INFO, S00NYA_LOG_ERROR, S00NYA_LOG_WARNING };

		static void Initialize();
		static void ShutDown();

		static void Add(std::string logStr, int level);
		static void Add(std::stringstream log, int level);
		static void Log(bool logToConsole = true, bool logToFile = false);
	};

}

#endif