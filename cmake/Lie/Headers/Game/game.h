#pragma once

namespace Lie
{

	class Window;

	class Lie
	{
	protected:
		Window* window;

	public:
		Lie();
		virtual ~Lie();

		void Construct(const char* title, const int& width, const int& height);
		void Start();

	private:
		void Tick();					//Call once in a second

	//Methods to Override
	protected:
		virtual void FixedUpdate();		//Call 60 times a second
		virtual void Update();			//Call as frequent as possible OR Vsync-ed
	};

}