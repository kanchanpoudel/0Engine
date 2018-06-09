# 0Engine
**0Engine** is a 2D Game Engine / Framework developed using OpenGL as a graphics API


## Contents
- [Running Using Visual Studio in Windows](#running-using-visual-studio-in-windows)
- [Dependencies](#dependencies)
- [Directory Structure](#directory-structure)
- [Directory Structure for 0Engine](#directory-structure-for-0engine)
- [Building the project](#building-the-project)
- [Components of the 0Engine](#components-of-the-0engine)

## Running Using Visual Studio in Windows
- Run the solution file `s00nya.sln` to open the project using Visual Studio
- Right Click the **Game** project and click on **Set as Start Up Project**
- Press **[F5]** or click the **Local Windows Debugger** button to run the project


## Dependencies
- [GLFW](http://www.glfw.org/)
- [GLEW](http://glew.sourceforge.net/)
- [stb](https://github.com/nothings/stb)

*Note that all the dependencies are readily avaible, so it is not required for installing them separately*


## Directory Structure
- Root directory consists of the directories : `0Engine`, `Dependencies` and other directories
- All the compiled / build files are (or should be) inside of the directory `bin` in the root directory
- All other directories in the root directories except above mentioned are Example game projects made using the **0Engine**
- `Dependencies` directory contains all the projects that **0Engine** depends on
- `0Engine` directory contains the source code for the **0Engine**


## Directory Structure for 0Engine
Directories and files inside of `0Engine` directory ::
- `Debugger`    : Logger class and OpenGL debugger
- `Game`        : Wrapper for the whole framework and Locator of all required servies
- `GameObject`  : Base classes for Game Objects, Cameras, Lights, etc
- `Graphics`    : GPU buffers, Renderer, Materials, Shaders, Sprites and Window
- `Input`       : Input systems and Input Manager
- `Math`        : Vectors, Matrices, Transformation, Dimensions and other mathematics
- `Physics`     : Kinematics, Collision and Collision Resolution
- `Utility`     : Events Manager, Resources Manager, Timer and other utilities

Directories inside of the `Headers` directory contain decalrations of all the classes / functions that are defined in above mentioned directories

*Note that **s00nya.h** file inside of `0Engine/Headers/` should include all the header files whose API are to be exposed to the game developers*


## Building the project
- All dependencies should be compiled to static libraries
- `0Engine` contents depend on `Dependencies` and should be compiled to static / dyanamic library according to the macro defined in `0Engine/Headers/s00nya_defs.h`
- Other game projects depend on `0Engine` and should be linked with the `0Engine` library
- Game should output to executables


## Components of the 0Engine
|                                       |                               |                                  |                                   |
| :---:                                 |   :---:                       |   :---:                          |    :---:                          |
|[Game2D](#game2d)                      |[Locator](#locator)            |[Window](#window)                 |[Debug](#debug)                    |
|[Timer](#timer)                        |[Input](#input)                |[Input Manager](#input-manager)   |[Event Manager](#event-manager)    |
|[Resources](#resources)                |[Renderer](#renderer)          |[Vertex](#vertex)                 |[Vertex Buffer](#vertex-buffer)    |
|[Vertex Buffer 2D](#vertex-buffer-2d)  |[Shader](#shader)              |[Raw Image](#raw-image)           |[Sprite](#sprite)                  |
|[Scene](#scene)                        |[Game Object](#game-object)    |[Camera](#camera)                 |[Material](#material)              |
|[Vector2](#vector2)                    |[Vector3](#vector3)            |[Vector4](#vector4)               |[Matrix3](#matrix3)                |
|[Matrix4](#matrix4)                    |[Transform 2D](#transform-2d)  |[Dimension](#dimension)           |[Collider 2D](#collider-2d)        |
|[Collision 2D](#collision-2d)          |[Rigid Body](#rigid-body)


## Game2D
**Information**
- `Game2D` is a wrapper class for different components of the **0Engine**
- Maintains relationships between all different components of the **0Engine**
- It contains [Locator](#locator), [Window](#window), [Timer](#timer), [Input](#input), [Input Manager](#input-manager), [Event Manager](#event-manager), [Resources](#resources), [Renderer](#renderer), [Shader](#shader)s and [Scene](#scene)s
- All the components are instanced using [Locator](#locator) class
- `Game2D` loads an active `Scene`, only one scene can be active at a time
- **Tick()**, **FixedUpdate()** and **Update()** method are called every second, 60 times a second and as fast as possible respectively in the game loop

**API**

```cpp 
Game2D(const Character* title, const Integer& width, const Integer& height, const Samples& sample)
```
- title = Title to be displayed in the window, defaults to "s00nya Game"
- width = Width of the window, defaults to 800
- height = Height of the window, defaults to 600
- sample =  Sample order for multisampling. Can be { NO_SAMPLE, SAMPLE_DOUBLE, SAMPLE_FOUR, SAMPLE_EIGHT } from `Samples`

---
```cpp
 void Start()
 ```
Begins the game loop

---
```cpp
static Input& GetInput()
```
Returns reference to [Input](#input)

---
```cpp
static Timer& GetTimer()
``` 
Returns reference to [Timer](#timer)

---
```cpp
static InputManager& GetInputManager()
```
Returns reference to [Input Manager](#input-manager) 

---
```cpp
static EventManager& GetEventManager()
```
Returns reference to [Event Manager](#event-manager) 

---
```cpp
static Resources& GetResourceManager()`
```
Returns reference to [Resources](#resources)

---
```cpp
static void ActivateScene(const PDUInteger& id)`
```
- id = ID of the [Scene](#scene)
- Activates the [Scene](#scene) with `id`

---
```cpp
static void ActivateNextScene()`
```
Activate [Scene](#scene) in next order 

---
```cpp
static PDUInteger PushScene(Scene* scene)`
```
- scene = pointer to [Scene](#scene)
- Adds given `scene` in the `Game2D`
- **[Scene](#scene) passed must be created in heap, memory is then maintained by this wrapper so cleaning is not required**

---
```cpp
static void PopSceneBack()`
```
Remove last placed [Scene](#scene)

---
```cpp
static void PopSceneFront()`
```
Remove first placed [Scene](#scene)

---
```cpp
static Scene& GetCurrentScene()`
```
Get reference to currently active [Scene](#scene)

---


[Go Up](#components-of-the-0engine)


## Locator
**Information**
- Locator is a singleton class
- It is used for creating instances of [Window](#window), [Timer](#timer), [Input](#input), [Input Manager](#input-manager), [Event Manager](#event-manager), [Resources](#resources), [Renderer](#renderer)
- It is used by [Game2D](#game2d)
- It returns pointer to these classes allocated in heap
- It is not responsible for cleaning the allocated memory, caller (in our case [Game2D](#game2d)) is reponsible for cleaning the allocated memory

**API**

This class is not intended to be used as a part of the Game development process

[Go Up](#components-of-the-0engine)


## Window
**Information**
- Window class maintains Window creation, resizing, destruction and other window related functions
- Window class automatically creates instance of [Debug](#debug) during window creation and shut down [Debug](#debug) during window destruction
- Window class is required for creation of [Input](#input) System
- [Timer](#timer) must be constructed after window construction because [Timer](#timer) depends on window class

**API**

```cpp
void Resize(const Integer& width, const Integer& height);
```
- width = Width of the window to be resized to
- height = Height of the window to be resized to

---
```cpp
void ToggleFullscreen();
```
- Toggles full screen mode
- On window construction, the window will be in windowed mode by default

---
```cpp
void ChangeCursor(const RawImage& image);
```
- image = [RawImage](#raw-image) that is to be placed as cursor within the window
- Changes the cursor within the window

---
```cpp
void SetIcon(const RawImage& image);
```
- image = [RawImage](#raw-image) that is to be placed as window icon
- Sets / Changes the window icon

---
```cpp
void DisableCursor() const;
```
Disables cursor and sets a virtual cursor in the middle of the window client area

---
```cpp
void HideCursor() const;
```
Hides cursor within the window

---
```cpp
void EnableCursor() const;
```
Resets cursor properties (Hidden / Disabled cursor)

---
```cpp
const Integer& Width() const;
```
Returns Width of the window

---
```cpp
const Integer& Height() const;
```
Returns Height of the window

---

[Go Up](#components-of-the-0engine)


## Debug
**Information**
- Debug lets the debug information to be displayed in console and file
- This class automatically finds and displays OpenGL errors & warnings
- It is automatically constructed during [Window](#window) creation and destroyed during [Window](#window) destruction

**API**

```cpp
static void Add(const std::string& logStr, Integer level)
```
- logStr = string data that is to be logged
- level = the level of the log. Can be { S00NYA_LOG_INFO, S00NYA_LOG_ERROR, S00NYA_LOG_WARNING } inside of `Debug`

---

[Go Up](#components-of-the-0engine)


## Timer
**Information**

This class records information about time and timing of the program

**API**

```cpp
Float DeltaTime() const;
```
Returns the time spent between 2 sucessive frame / game loop

---
```cpp
static Float ElaspedTime();
```
Returns the time spent after the program ran

---


[Go Up](#components-of-the-0engine)


## Input
**Information**
- This class maintains keyboard and mouse input
- This class is constructed using the [Window](#window) class

**API**

```cpp
Boolean Pressed(const Keys& key);
```
Returns `true` if the given `key` is pressed otherwise `false`

---
```cpp
Boolean Held(const Keys& key);
```
Returns `true` if the given `key` is held otherwise `false`

---
```cpp
Boolean Combined(const Keys& hold, const Keys& press);
```
Returns `true` if the `hold` is held and `press` is pressed otherwise `false`

---
```cpp
Boolean Combined(const Keys& hold1, const Keys& hold2, const Keys& press);
```
Returns `true` if the `hold1` and `hold2` is held and `press` is pressed otherwise `false`

---
```cpp
Boolean Pressed(const Buttons& button);
```
Returns `true` if the `button` Mouse button is pressed otherwise `false`

---
```cpp
Boolean Held(const Buttons& button);
```
Returns `true` if the `button` Mouse button is held otherwise `false`

---
```cpp
const Float& CursorPositionX();
```
Returns Horizontal position of the mouse cursor

---
```cpp
const Float& CursorPositionY();
```
Returns Vertical position of the mouse cursor

---
```cpp
const Float& HorizontalAxis();
```
- Returns horizontal offset when the mouse is moved
- Value lies between -1.0f to 1.0f

---
```cpp
const Float& VerticalAxis();
```
- Returns horizontal offset when the mouse is moved
- Value lies between -1.0f to 1.0f

---
```cpp
const Float& ScrollHorizontalAxis();
```
Returns the number of scroll wheels scrolled horizontally

---
```cpp
const Float& ScrollVerticalAxis();
```
Returns the number of scroll wheels scrolled vertically

---
```cpp
static const Character* GetName(const Keys& key);
```
Returns name of the given `key`

---
```cpp
static const Character* GetName(const Buttons& button);
```
Returns name of the mouse button `button`

---

[Go Up](#components-of-the-0engine)


## Input Manager
**Information**

**API**


[Go Up](#components-of-the-0engine)


## Event Manager
**Information**

**API**


[Go Up](#components-of-the-0engine)


## Resources
**Information**

**API**


[Go Up](#components-of-the-0engine)


## Renderer
**Information**

**API**


[Go Up](#components-of-the-0engine)


## Vertex
**Information**

**API**


[Go Up](#components-of-the-0engine)


## Vertex Buffer
**Information**

**API**


[Go Up](#components-of-the-0engine)


## Vertex Buffer 2D
**Information**

**API**


[Go Up](#components-of-the-0engine)


## Shader
**Information**

**API**


[Go Up](#components-of-the-0engine)


## Raw Image
**Information**

**API**


[Go Up](#components-of-the-0engine)


## Sprite
**Information**

**API**


[Go Up](#components-of-the-0engine)


## Scene
**Information**

**API**


[Go Up](#components-of-the-0engine)


## Game Object
**Information**

**API**


[Go Up](#components-of-the-0engine)


## Camera
**Information**

**API**


[Go Up](#components-of-the-0engine)


## Material
**Information**

**API**


[Go Up](#components-of-the-0engine)


## Vector2
**Information**

**API**


[Go Up](#components-of-the-0engine)


## Vector3
**Information**

**API**


[Go Up](#components-of-the-0engine)


## Vector4
**Information**

**API**


[Go Up](#components-of-the-0engine)


## Matrix3
**Information**

**API**


[Go Up](#components-of-the-0engine)


## Matrix4
**Information**

**API**


[Go Up](#components-of-the-0engine)


## Transform 2D
**Information**

**API**


[Go Up](#components-of-the-0engine)


## Dimension
**Information**

**API**


[Go Up](#components-of-the-0engine)


## Collider 2D
**Information**

**API**


[Go Up](#components-of-the-0engine)


## Collision 2D
**Information**

**API**


[Go Up](#components-of-the-0engine)


## Rigid Body
**Information**

**API**


[Go Up](#components-of-the-0engine)

