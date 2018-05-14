# Solution : s00nya.sln
cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

##################### Variables ############################
############################################################

# Solution
set(SOLUTION_NAME Game)

# Add projects to the solution
add_subdirectory (Dependencies/GLEW) # including GLEW into the Solution
add_subdirectory (Dependencies/GLFW) # including GLFW into the Solution
add_subdirectory (0Engine) # including 0Engine into the Solution
add_subdirectory (Game) # including Game into the Solution