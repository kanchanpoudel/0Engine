# Lie
This is a 2D game engine with a project code name **Lie**

## Running Using Visual Studio or CLion
- Run the solution file `Lie.sln` to open the project using Visual Studio in Windows
- Open the directory `Lie/cmake` using CLion to open the project using CLion in other OS

## Dependencies
- [GLFW](http://www.glfw.org/)
- [GLEW](http://glew.sourceforge.net/)

*Note that dependencies for Win32 application are included in `Dependencies/lib` and for unix `cmake/Dependencies/lib`*
*All the headers files that are needed for Dependencies are included in `Dependencies/include`*

## Solution Structure for VS users
- `./Lie/bin/$(ProjectName)/` should contain all the binaries and executables
- `./Lie/bin/intermediates/$(ProjectName)` should contain all the logs, debug and release information and intermediate files

- `./Lie/Lie/` is the project directory for the Game Engine
- All other directories in the root directory except (`bin`, `Lie` and `Dependencies`)are seperate projects used for example game projects
- `./Lie/Lie` : This project files should output game engine static C++ library which is then used by the example projects
- `./Lie/Game` : This is example game project which uses the `Lie Game Engine` static C++ library

## Workspace Structure for CMake users
 - `./Lie/cmake/cmake-build-debug` or `./Lie/cmake/cmake-build-release` should contain all the binary and executables
 - `./Lie/cmake/bin` should contain CMake built solution / projects / other CMake files
 - `./Lie/cmake/.idea` directory can be directly used via CLion IDE, `.idea` has been added to the `.gitignore`

## Lie Game Engine Directory Structure
- `Headers` should contain all the directories that contain the header files for all the definations used in Game Engine
- `Headers/lie.h` should contain all the definations that are needed for the other game projects, this header file is used in game projects
- `Game` should contain all the files necessary for wrapping the game engine in a single wrapper class named `Lie`
- `Debugger` should contain everything necessary for debugging game engine and not game
- `Graphics` should contain everything necessary related with graphics and OpenGL calls
- `Input` should handle all Keyboard, Mouse, Joystick events and should have callbacks as necessary
- `Maths` : All graphics and physics mathematics
...
*Other directories will and should be added as necessary*

