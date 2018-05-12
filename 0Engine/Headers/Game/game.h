#pragma once

namespace s00nya
{

	class Window;
	class Timer;
	class Input;

	class Game2D
	{
	protected:
		Window* window;
		Timer* timer;
		Input* input;

	public:
		Game2D();
		virtual ~Game2D();

		void Construct(const char* title, const int& width, const int& height);
		void Start();

	private:
		void Tick();					// Call once in a second

	//Methods to Override
	protected:
		virtual void OnConstruction();  // Call to construct objects and set default values
		virtual void FixedUpdate();		// Call 60 times a second
		virtual void Update();			// Call as frequent as possible OR Vsync-ed

	protected:
		static const float fps; // Frames per second
	};

}