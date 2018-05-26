#pragma once
#include <deque>
#include <s00nya_defs.h>
#include <Utility/events.h>

namespace s00nya
{

	class Locator;

	class S00NYA_API EventManager
	{
	private:
		std::deque<std::string> m_behaviourEvents;
		std::deque<std::string> m_physicsEvents;
		std::deque<std::string> m_rendererEvents;
		std::deque<std::string> m_systemEvents;
		std::deque<std::string> m_userEvents;

	public:
		EventManager()
		{
		}

		void Push(Events enum_event,const std::string& event);
		std::string Receive(Events enum_event);

		friend class Locator;
	};

}