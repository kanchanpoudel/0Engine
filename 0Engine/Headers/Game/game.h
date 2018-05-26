#pragma once
#include "s00nya_defs.h"
#include <deque>
#include <map>
#include <string>

namespace s00nya
{

	class Window;
	class Timer;
	class Input;
	class InputManager;
	class EventManager;
	class GameObject2D;
	class Resources;
	class Renderer;

	class Shader;
	class Scene;
	class GameObject2D;

	class S00NYA_API Game2D
	{
	protected:
		Window* window;
		Timer* timer;
		Input* input;
		InputManager* inputManager;
		EventManager* eventManager;
		Resources* resource;
		Renderer* renderer;

	private:
		PDUInteger m_activeScene;
		std::deque<Scene*> m_scenes;
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
		static EventManager& GetEventManager();
		static Resources& GetResourceManager();

		static void ActivateScene(const PDUInteger& id);
		static void ActivateNextScene();
		static PDUInteger PushScene(Scene* scene);
		static void PopSceneBack();
		static void PopSceneFront();
		static Scene& GetCurrentScene();
		
		static void AddGameObject2D(GameObject2D* object2D, const Character* name);
		static GameObject2D& GetObject2D(const Character* name);
		static void RemoveObject2D(const Character* name);

	protected:
		static const Float fps; // Frames per second
	
	private:
		static Game2D* instance;
	};

}