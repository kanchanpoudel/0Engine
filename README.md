# Lie
This is a 2D game engine with a project code name **Lie**

## Running Using Visual Studio or CLion
- Run the solution file `Lie.sln` to open the project using Visual Studio in Windows
- Open the root directory `Lie` using CLion to open the project using CLion in Linux

## Dependencies
- [GLFW](http://www.glfw.org/)
- [GLEW](http://glew.sourceforge.net/)

*Note that dependencies for Win32 application are included in `Dependencies/lib` and for linux `Dependencies/linux/lib`*
*All the headers files that are needed for Dependencies are included in `Dependencies/include`*

## Solution Structure
- `./Lie/bin/$(ProjectName)/` should contain all the binaries and executables
- `./Lie/bin/intermediates/$(ProjectName)` should contain all the logs, debug and release information and intermediate files

- `./Lie/Lie/` is the project directory for the Game Engine
- All other directories in the root directory except (`bin`, `Lie` and `Dependencies`)are seperate projects used for example game projects
- `./Lie/Lie` : This project files should output game engine static C++ library which is then used by the example projects
- `./Lie/Game` is example game project which uses the `Lie Game Engine`
