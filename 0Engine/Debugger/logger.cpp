#include "Debugger/logger.h"
#include "GL/glew.h"
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

	void Debug::Add(const std::string& logStr, int level)
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

	void Debug::OpenGLErrorCallback(
		unsigned int source,
		unsigned int type,
		unsigned int id,
		unsigned int severity,
		int length,
		const char* message,
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
		std::stringstream strStream;
		strStream << "Source = [";
		switch (source)
		{
		case GL_DEBUG_SOURCE_API:             strStream << "API"; break;
		case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   strStream << "Window System"; break;
		case GL_DEBUG_SOURCE_SHADER_COMPILER: strStream << "Shader Compiler"; break;
		case GL_DEBUG_SOURCE_THIRD_PARTY:     strStream << "Third Party"; break;
		case GL_DEBUG_SOURCE_APPLICATION:     strStream << "Application"; break;
		case GL_DEBUG_SOURCE_OTHER:           strStream << "Other"; break;
		}

		// Get error type
		strStream << "] Type = [";
		switch (type)
		{
		case GL_DEBUG_TYPE_ERROR:               strStream << "Error"; break;
		case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: strStream << "Deprecated Behavior"; break;
		case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  strStream << "Undefined Behavior"; break;
		case GL_DEBUG_TYPE_PORTABILITY:         strStream << "Portability"; break;
		case GL_DEBUG_TYPE_PERFORMANCE:         strStream << "Performance"; break;
		case GL_DEBUG_TYPE_MARKER:              strStream << "Marker"; break;
		case GL_DEBUG_TYPE_PUSH_GROUP:          strStream << "Push Group"; break;
		case GL_DEBUG_TYPE_POP_GROUP:           strStream << "Pop Group"; break;
		case GL_DEBUG_TYPE_OTHER:               strStream << "Other"; break;
		}

		// Get error message and add to debug
		strStream << "] Message = [" << message << "]";
		Debug::Add(strStream.str(), level);
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