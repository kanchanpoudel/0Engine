#include "Utility\event_manager.h"
#include "Utility\events.h"

namespace s00nya
{

	void EventManager::Push(const Events& enumEvent, const std::string& event)
	{
		switch (enumEvent)
		{
		case Events::BEHAVIOUR: m_behaviourEvents.push_back(event); return;
		case Events::PHYSICS:	m_physicsEvents.push_back(event);	return;
		case Events::RENDERER:	m_rendererEvents.push_back(event);	return;
		case Events::SYSTEM:	m_systemEvents.push_back(event);	return;
		case Events::USER:		m_userEvents.push_back(event);		return;
		}
	}

	Boolean EventManager::Receive(const Events& enumEvent, std::string& outEvent)
	{
		switch (enumEvent)
		{
		case Events::SYSTEM:
			if (m_systemEvents.empty()) return false;
			outEvent = m_systemEvents.front();
			m_systemEvents.pop_front();
			return true;

		case Events::BEHAVIOUR:
			if (m_behaviourEvents.empty()) return false;
			outEvent = m_behaviourEvents.front();
			m_behaviourEvents.pop_front();
			return true;

		case Events::PHYSICS:
			if (m_physicsEvents.empty()) return false;
			outEvent = m_physicsEvents.front();
			m_physicsEvents.pop_front();
			return true;

		case Events::RENDERER:
			if (m_rendererEvents.empty()) return false;
			outEvent = m_rendererEvents.front();
			m_rendererEvents.pop_front();
			return true;

		case Events::USER:
			if (m_userEvents.empty()) return false;
			outEvent = m_userEvents.front();
			m_userEvents.pop_front();
			return true;

		default:
			return NULL;
		}
	}

}