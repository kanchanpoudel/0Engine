#pragma once
#include <vector>
#include <string>
#include <list>
#include <utility>
#include "Input/input.h"
#include "s00nya_defs.h"

namespace s00nya
{

	class Locator;
	
	class S00NYA_API InputManager
	{
	private:
		Input* m_system;
		std::list<std::pair<std::string, std::vector<Keys>>> m_keyMaps;

	private:
		InputManager(Input* system);

	public:
		Boolean AddKeyMap(const std::string& name, const std::vector<Keys>& keyMaps);
		Boolean RemoveKeyMaps(const std::string& name);

		Boolean KeyMapPressed(const std::string& name);
		Boolean KeyMapHeld(const std::string& name);

		friend class Locator;
	};

}