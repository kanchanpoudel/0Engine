#pragma once

namespace s00nya
{

	class Window;

	class Timer
	{
	private:
		static float m_s_lastFrameTime;
	
	public:
		static float ElaspedTime();
		static float DeltaTime();

	private:
		static void Update(); // Updated when window is updated

		friend class Window;
	};

}
