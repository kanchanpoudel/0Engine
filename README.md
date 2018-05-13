# 0Engine
This is a 2D game engine

## Running Using Visual Studio
- Run the solution file `s00nya.sln` to open the project using Visual Studio in Windows

## Dependencies
- [GLFW](http://www.glfw.org/)
- [GLEW](http://glew.sourceforge.net/)

*Note that dependencies for Win32 application are included in `Dependencies/lib`*
*All the headers files that are needed for Dependencies are included in `Dependencies/include`*

## Solution Structure for VS users
- `./s00nya/bin/` should contain all the binaries and executables
- `./s00nya/bin/intermediates/$(ProjectName)` should contain all the logs, debug and release information and intermediate files

- `./s00nya/0Engine/` is the project directory for the Game Engine
- All other directories in the root directory except (`bin`, `0Engine` and `Dependencies`)are seperate projects used for example game projects
- `./s00nya/0Engine` : This project files should output game engine static C++ library which is then used by the example projects
- `./s00nya/Game` : This is example game project which uses the `Lie Game Engine` static C++ library

## 0Engine Directory Structure
- `Headers` should contain all the directories that contain the header files for all the definations used in Game Engine
- `Headers/s00nya.h` should contain all the definations that are needed for the other game projects, this header file is used in game projects
- `Game` should contain all the files necessary for wrapping the game engine in a single wrapper class named `s00nya`
- `Debugger` should contain everything necessary for debugging game engine and not game
- `Graphics` should contain everything necessary related with graphics and OpenGL calls
- `Input` should handle all Keyboard, Mouse, Joystick events and should have callbacks as necessary
- `Maths` : All graphics and physics mathematics
...
*Other directories will and should be added as necessary*


## Basic Usage of 0Engine and Object usage documentation


The game can be constructed following ways

```cpp
#include "s00nya.h"                      // Inlcude the header file for game engine

using namespace s00nya;          // All classes and methods are wrapped inside s00nya namespace


// Lie class should be derived and methods should be filled as required
class ExampleGame : public Game2D
{
	void OnConstruction() override
	{
        // Setting up window e.g. window resize and setting up fullscreen, window icon and cursor
        // All the game objects construction should be done here
	}

	void FixedUpdate() override
	{
        // This function is called 60 times in a second
        // Usually physics are done here
        // Other time related updates can be done here
	}

	void Update() override
	{
        // This function is called as many times as possible in a second unless VSync is enabled
        // All the input and other updates should be done here
	}

    void ~Game2D() override
    {
        // All the memory allocation in the OnConstruction() function should be freed here
    }
};

int main()
{
    // Construct game from derived class
	ExampleGame* game = new ExampleGame;

    /*
		Constructs the window for game and calls OnConstruction() method
        arguments to be passed are {window_title}, {width}, {height}
        */
	game->Construct("Example Game", 800, 600);

    // Displays the window
    // Runs the game until closed
	game->Start();
	
    delete game;
	return 0;
}
```


## Game2D Class

**Members that can be accessed**

- `window` : For accessing *Window* class
- `timer` : For accessing *Timer* class
- `input` : For accessing *Input* class


## Window Class

**Methods that can be accessed**

- `void Close()` : Shuts down the game
- `void Resize(const int& width, const int& height)` : Changes window resolution, width and height can be set as *WINDOW_AUTO_WIDTH* and - *WINDOW_AUTO_HEIGHT* for setting resolution to match that of monitor
- `void ToggleFullscreen()` : When window is created by default mode is windowed
- `void ChangeCursor(const char* path)` : Sets the window cursor, **function subject to change**
- `void SetIcon(const char* path)` : Sets the window icon, **function subject to change**
- `void DisableCursor()` : Cursor is totally disabled, virtual cursor will be present that can't get outside of the window
- `void HideCursor()` : Hides the cursor when the cursor position resides inside of the window
- `void EnableCursor()` : Resets cursor property set by *DisableCursor()* and *EnableCursor()* methods

**Note that other classes and function will be added when and as required**


## Timer Class

**Methods that can be accessed**

- `float ElaspedTime()` : Returns the time spend from which the Program started in seconds
- `float DeltaTime()` : Returns the time between last and current frame in seconds


## Input Class

**Methods that can be accessed**

- `bool Pressed(const Keys& key || const Buttons& button)` : Returns true if the key / button is pressed
- `bool Held(const Keys& key || const Buttons& button)` : Returns true if the key / button is held
- `bool Repeated(const Keys& key)` : Return true if the key press is repeated
- `bool Combined(const Keys& hold, const Keys& press)` : Returns true if the first key is held and second is pressed (e.g. [Ctrl] + [C])
- `bool Combined(const Keys& hold1, const Keys& hold2, const Keys& press)` : Return true if the first two keys are held and last one is pressed
- `const float& CursorPositionX()` : Returns the current X position of the cursor
- `const float& CursorPositionY()` : Returns the current Y position of the cursor
- `const float& HorizontalAxis()` : Returns the cursor offset in X position Ranges (-1.0f, 1.0f)
- `const float& VerticalAxis()` : Returns the cursor offset in Y position Ranges (-1.0f, 1.0f)
- `const float& ScrollHorizontalAxis()` : Returns the number of scroll turns made horizontally
- `const float& ScrollVerticalAxis()` : Returns the number of scroll turns made vertically
- `const char* GetName(const Keys& key || const Buttons& button)` : Returns the name of given key / button 