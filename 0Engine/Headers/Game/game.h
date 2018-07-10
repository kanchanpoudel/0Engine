#pragma once
#include "s00nya_defs.h"
#include <vector>
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
	class Camera;
	class Game2D;

	class S00NYA_API Game2D
	{
	public:
		enum class Samples : Integer { NO_SAMPLE = 1, SAMPLE_DOUBLE = 2, SAMPLE_FOUR = 4, SAMPLE_EIGHT = 8 };

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
		Game2D(const Character* title = "s00nya Game", const Integer& width = 800, const Integer& height = 600, const Samples& sample = Samples::NO_SAMPLE);
		virtual ~Game2D();

	private:
		Game2D(const Game2D& game) = delete;
		Game2D& operator=(const Game2D& game) = delete;

	public:
		static void Run(Game2D* app);

	private:
		void Tick();																				// Call once in a second
		void FixedUpdate(std::vector<GameObject2D*>& objects, std::vector<Camera*>& cameras);		// Call 60 times a second
		void Update(std::vector<GameObject2D*>& objects, std::vector<Camera*>& cameras);			// Call as frequent as possible OR Vsync-ed

	public:
		// These methods are intended to call from within the GameObject inherited class
		static Input& GetInput();
		static Timer& GetTimer();
		static InputManager& GetInputManager();
		static EventManager& GetEventManager();
		static Resources& GetResourceManager();

		// Scene Management
		static void ActivateScene(const PDUInteger& id);
		static void ActivateNextScene();
		static PDUInteger PushScene(Scene* scene);
		static void PopSceneBack();
		static void PopSceneFront();
		static Scene& GetCurrentScene();
		
		// GameObjects are added, returned or removed from the currently active scene
		static void AddGameObject2D(GameObject2D* object2D, const Character* name);
		static GameObject2D& GetObject2D(const Character* name);
		static void RemoveObject2D(const Character* name);

		// Cameras are added, returned or removed from the currently active scene
		static void AddCamera(Camera* camera, const Character* name);
		static Camera& GetCamera(const Character* name);
		static void RemoveCamera(const Character* name);

	protected:
		// Frames per second for FixedUpdate methods
		// Defaults to 60.0f
		static const Float fps;
	
	private:
		// this pointer is used in the static methods above
		static Game2D* instance; // pointer to this instance of Game2D class
	};

}