#include "Input/input_manager.h"

namespace s00nya
{

	InputManager::InputManager(Input* system):
		m_system(system)
	{
	}

	Boolean InputManager::AddKeyMap(const std::string& name, const std::vector<Keys>& keyMaps)
	{
		if (keyMaps.empty()) 
			return false;

		for (auto& keymap : m_keyMaps)
			if (keymap.first == name)
				return false;

		m_keyMaps.push_back(std::make_pair(name, keyMaps));
		return true;
	}

	Boolean InputManager::RemoveKeyMaps(const std::string& name)
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

	Boolean InputManager::KeyMapPressed(const std::string& name)
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

	Boolean InputManager::KeyMapHeld(const std::string& name)
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

