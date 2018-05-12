#pragma once

namespace s00nya
{

	class Timer
	{
	private:
		float m_lastFrameTime;
	
	public:
		Timer();

		void Update();
		float DeltaTime() const;
		
		static float ElaspedTime();
	};

}
