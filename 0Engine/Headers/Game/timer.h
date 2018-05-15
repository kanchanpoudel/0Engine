#pragma once

namespace s00nya
{

	class Timer
	{
	private:
		float m_lastFrameTime;
	
	public:
		Timer();

	private:
		Timer(const Timer& timer) = delete;
		Timer& operator=(const Timer& timer) = delete;

	public:
		void Update();
		float DeltaTime() const;
		
		static float ElaspedTime();
	};

}
