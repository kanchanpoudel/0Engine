#pragma once
#include "s00nya_defs.h"
#include <map>
#include <string>

namespace s00nya
{

	class Debug;
	class Window;
	class Timer;
	class Input;
	class InputManager;
	class Resources;
	class Shader;
	class Renderer;
	class GameObject2D;
	class Scene;
	class Locator;

	class S00NYA_API Locator
	{
	private:
		static Locator* instance;

	private:
		Locator();
		~Locator();

	public:
		Window* WindowService(const Character* title, const Integer& width, const Integer& height) const;
		Timer* TimerService() const;
		Input* InputService(const Window* window) const;
		InputManager* InputManagerService(Input* input) const;
		Resources* ResourceService() const;
		Shader* ShaderService(const Character* path) const;
		Renderer* RendererService() const;
		std::map<std::string, GameObject2D>& GetAllObjects2D(Scene* scene);

		static Locator& Get();
	};

}