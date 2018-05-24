#pragma once
#include "s00nya_defs.h"
#include <vector>
#include <map>
#include <string>

namespace s00nya
{

	class Window;
	class Timer;
	class Input;
	class InputManager;
	class Resources;
	class Renderer;

	class Shader;
	class Scene;

	class S00NYA_API Game2D
	{
	protected:
		Window* window;
		Timer* timer;
		Input* input;
		InputManager* inputManager;
		Resources* resource;
		Renderer* renderer;

	private:
		std::vector<Scene> m_scenes;
		std::map<std::string, Shader*> m_shaders;

	public:
		Game2D(const Character* title = "s00nya Game", const Integer& width = 800, const Integer& height = 600);
		virtual ~Game2D();

	private:
		Game2D(const Game2D& game) = delete;
		Game2D& operator=(const Game2D& game) = delete;

	public:
		void Start();

	private:
		void Tick();			// Call once in a second
		void FixedUpdate();		// Call 60 times a second
		void Update();			// Call as frequent as possible OR Vsync-ed

	public:
		static Input& GetInput();
		static Timer& GetTimer();
		static InputManager& GetInputManager();
		static Resources& GetResourceManager();

	protected:
		static const Float fps; // Frames per second
	
	private:
		static Game2D* instance;
	};

}