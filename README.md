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

## Locator

## Window

## Debug

## Timer

## Input

## Input Manager

## Event Manager

## Resources

## Renderer

## Vertex

## Vertex Buffer

## Vertex Buffer 2D

## Shader

## Raw Image

## Sprite

## Scene

## Game Object

## Camera

## Material

## Vector2

## Vector3

## Vector4

## Matrix3

## Matrix4

## Transform 2D

## Dimension

## Collider 2D

## Collision 2D

## Rigid Body
