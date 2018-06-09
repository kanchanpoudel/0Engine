#pragma once
#include "s00nya_defs.h"
#include <vector>
#include <string>

namespace s00nya
{

	class Debug;
	class Window;
	class Timer;
	class Input;
	class InputManager;
	class EventManager;
	class Resources;
	class Shader;
	class Renderer;
	class GameObject2D;
	class Scene;
	class Locator;

	/*
	 * Locator class loads / creates instance of all the classes that are required by the main Game
	 * These classes includes the classes that the user doesn't have direct access to
	 	and user should not be able to instanciate these classes
	 * Locator allocates all the classes in heap and returns the pointer to the respective classes
	 * Locator doesn't clean the memory allocated in heap, the caller is believed to do the cleaning
	*/

	class S00NYA_API Locator
	{
	private:
		static Locator* instance;

	private:
		Locator();	// Constructor is private because the class is singleton

	public:
		~Locator();

	public:
		// Methods that create instance of different classes
		Window* WindowService(const Character* title, const Integer& width, const Integer& height) const;
		Timer* TimerService() const;
		Input* InputService(const Window* window) const;
		InputManager* InputManagerService(Input* input) const;
		EventManager* EventManagerService() const;
		Resources* ResourceService() const;
		Shader* ShaderService(const Character* path) const;
		Renderer* RendererService(const Integer& frameWidth, const Integer& frameHeight, const Integer& displayWidth, const Integer& displayHeight) const;
		
		// Returns all of the GameObjects from the given scene
		std::vector<GameObject2D*>& GetAllObjects2D(Scene* scene);

		static Locator& Get();
	};

}