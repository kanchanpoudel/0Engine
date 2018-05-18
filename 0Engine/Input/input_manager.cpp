#include "Input/input_manager.h"

namespace s00nya
{

	InputManager::InputManager():
		m_system(nullptr)
	{
	}

	void InputManager::SupplySystem(Input* system)
	{
		m_system = system;
	}

	bool InputManager::AddKeyMap(const std::string& name, const std::vector<Keys>& keyMaps)
	{
		if (keyMaps.empty()) 
			return false;

		for (auto& keymap : m_keyMaps)
			if (keymap.first == name)
				return false;

		m_keyMaps.push_back(std::make_pair(name, keyMaps));
		return true;
	}

	bool InputManager::RemoveKeyMaps(const std::string & name)
	{
		for (auto& keymap : m_keyMaps)
		{
			if (keymap.first == name)
			{
				m_keyMaps.remove(keymap);
				return true;
			}
		}
		
		return false;
	}

	bool InputManager::KeyMapPressed(const std::string & name)
	{
		for (auto& keymap : m_keyMaps)
		{
			if (keymap.first == name)
			{
				for (auto& key : keymap.second)
				{
					if (m_system->Pressed(key))
						return true;
				}
			}
				
		}
		return false;
	}

	bool InputManager::KeyMapHeld(const std::string & name)
	{
		for (auto& keymap : m_keyMaps)
		{
			if (keymap.first == name)
			{
				for (auto& key : keymap.second)
				{
					if (m_system->Held(key))
						return true;
				}
			}
		}
		return false;
	}

}

