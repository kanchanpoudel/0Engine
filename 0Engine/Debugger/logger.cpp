#include "Debugger/logger.h"
#include "GL/glew.h"
#include <sstream>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>

#ifdef ENGINE_DEBUG 

namespace s00nya
{
	
	std::string Debug::m_s_logs;
	std::fstream Debug::m_s_logFile;

	void Debug::Initialize()
	{
		// Prepare log file
		Debug::m_s_logFile.open("./s00nyaLogs.log", std::ios::out | std::ios::binary);
		auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		std::tm time;
		localtime_s(&time, &now);
		std::stringstream timeStream;
		timeStream << "s00nya logs : [ " << std::put_time(&time, "%Y-%m-%d %X") << " ]" << "\n\n";
		m_s_logFile << timeStream.str();

		// Prepare OpenGL DEBUG
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		glDebugMessageCallback(Debug::OpenGLErrorCallback, nullptr);
		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
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

	void Debug::Add(const std::string& logStr, Integer level)
	{
		switch (level)
		{
		case Debug::S00NYA_LOG_INFO:
			Debug::m_s_logs += ("INFO :: " + logStr + '\n');
			return;
		case Debug::S00NYA_LOG_WARNING:
			Debug::m_s_logs += ("WARNING :: " + logStr + '\n');
			return;
		case Debug::S00NYA_LOG_ERROR:
			Debug::m_s_logs += ("ERROR :: " + logStr + '\n');
			return;
		default:
			Debug::m_s_logs += ("UNSPECIFIED :: " + logStr + '\n');
		}
	}

	void Debug::Log(Boolean logToConsole, Boolean logToFile)
	{
		if (logToConsole)
		{
			std::cout << Debug::m_s_logs;
		}
		if (logToFile)
		{
			m_s_logFile << Debug::m_s_logs;
		}
		Debug::m_s_logs.clear();
	}

	void Debug::OpenGLErrorCallback(
		UInteger source,
		UInteger type,
		UInteger id,
		UInteger severity,
		Integer length,
		const Character* message,
		const void* userParam
	)
	{
		// Check error level
		int level(Debug::S00NYA_LOG_INFO);
		if (severity == GL_DEBUG_SEVERITY_HIGH || severity == GL_DEBUG_SEVERITY_MEDIUM)
			level = Debug::S00NYA_LOG_ERROR;
		else if (severity == GL_DEBUG_SEVERITY_LOW)
			level = Debug::S00NYA_LOG_WARNING;

		// Get error source
		std::string str("Source = [");
		switch (source)
		{
		case GL_DEBUG_SOURCE_API:             str += "API"; break;
		case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   str += "Window System"; break;
		case GL_DEBUG_SOURCE_SHADER_COMPILER: str += "Shader Compiler"; break;
		case GL_DEBUG_SOURCE_THIRD_PARTY:     str += "Third Party"; break;
		case GL_DEBUG_SOURCE_APPLICATION:     str += "Application"; break;
		case GL_DEBUG_SOURCE_OTHER:           str += "Other"; break;
		}

		// Get error type
		str += "] Type = [";
		switch (type)
		{
		case GL_DEBUG_TYPE_ERROR:               str += "Error"; break;
		case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: str += "Deprecated Behavior"; break;
		case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  str += "Undefined Behavior"; break;
		case GL_DEBUG_TYPE_PORTABILITY:         str += "Portability"; break;
		case GL_DEBUG_TYPE_PERFORMANCE:         str += "Performance"; break;
		case GL_DEBUG_TYPE_MARKER:              str += "Marker"; break;
		case GL_DEBUG_TYPE_PUSH_GROUP:          str += "Push Group"; break;
		case GL_DEBUG_TYPE_POP_GROUP:           str += "Pop Group"; break;
		case GL_DEBUG_TYPE_OTHER:               str += "Other"; break;
		}

		// Get error message and add to debug
		str += ("] Message = [" + std::string(message) + "]");
		Debug::Add(str, level);
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