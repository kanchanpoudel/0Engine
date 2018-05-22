#pragma once
#include "s00nya_defs.h"

namespace s00nya
{

	class Locator;

	class S00NYA_API Timer
	{
	private:
		Float m_lastFrameTime;
	
	private:
		Timer();

	private:
		Timer(const Timer& timer) = delete;
		Timer& operator=(const Timer& timer) = delete;

	public:
		void Update();
		Float DeltaTime() const;
		
		static Float ElaspedTime();

		friend class Locator;
	};

}
