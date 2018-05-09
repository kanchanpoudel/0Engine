#pragma once

namespace s00nya
{

	class Window;

	class Timer
	{
	private:
		static float m_s_lastFrameTime;
	public:
		static void Initialize();
		static float ElaspedTime();
		static float DeltaTime();

	private:
		static void Update();

		friend class Window;
	};

}
