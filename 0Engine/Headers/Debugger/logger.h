#pragma once
#include <fstream>
#include <string>
#include "s00nya_defs.h"

#ifdef ENGINE_DEBUG

namespace s00nya
{

	class Locator;

	class S00NYA_API Debug
	{
	private:
		static std::string m_s_logs;
		static std::fstream m_s_logFile;

		Debug() = delete;
		void operator=(const Debug& debug) = delete;
		Debug(const Debug& debug) = delete;
		
		static void Initialize();
		static void ShutDown();

	public:
		enum { S00NYA_LOG_INFO, S00NYA_LOG_ERROR, S00NYA_LOG_WARNING };

		static void Add(const std::string& logStr, Integer level);
		static void Log( Boolean logToFile = false);
		
	private:
		static void __stdcall OpenGLErrorCallback(
			UInteger source, 
			UInteger type,
			UInteger id,
			UInteger severity,
			Integer length,
			const Character* message,
			const void* userParam
		);

		friend class Locator;
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