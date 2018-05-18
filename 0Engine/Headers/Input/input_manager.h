#pragma once
#include <vector>
#include <string>
#include <list>
#include <utility>
#include <array>
#include "Input\input.h"


namespace s00nya
{
	
	class InputManager
	{
	private:
		Input* m_system;
		std::list<std::pair<std::string, std::vector<Keys>>> m_keyMaps;

	public:
		InputManager();
		void SupplySystem(Input* system);

		bool AddKeyMap(const std::string& name, const std::vector<Keys>& keyMaps);
		bool RemoveKeyMaps(const std::string& name);

		bool KeyMapPressed(const std::string& name);
		bool KeyMapHeld(const std::string& name);
	};

}