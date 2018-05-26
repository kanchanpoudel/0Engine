#include "Utility\event_manager.h"
#include "Utility\events.h"

namespace s00nya
{

	void EventManager::Push(Events enum_event, const std::string& event)
	{
		switch (enum_event)
		{
		case Events::BEHAVIOUR:
			m_behaviourEvents.push_back(event);
			break;

		case Events::PHYSICS:
			m_physicsEvents.push_back(event);
			break;

		case Events::RENDERER:
			m_rendererEvents.push_back(event);
			break;

		case Events::SYSTEM:
			m_systemEvents.push_back(event);
			break;

		case Events::USER:
			m_userEvents.push_back(event);
			break;

		default:
			break;
		}
	}

	std::string EventManager::Receive(Events enum_event)
	{
		std::string first;
		switch (enum_event)
		{
		case Events::BEHAVIOUR:
			first = m_behaviourEvents.front();
			m_behaviourEvents.pop_front();
			return first;

		case Events::PHYSICS:
			first = m_physicsEvents.front();
			m_physicsEvents.pop_front();
			return first;

		case Events::RENDERER:
			first = m_rendererEvents.front();
			m_rendererEvents.pop_front();
			return first;

		case Events::SYSTEM:
			first = m_systemEvents.front();
			m_systemEvents.pop_front();
			return first;

		case Events::USER:
			first = m_userEvents.front();
			m_userEvents.pop_front();
			return first;

		default:
			return NULL;
		}
	}

}