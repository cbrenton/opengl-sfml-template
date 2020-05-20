cmake_minimum_required(VERSION 3.16)
project(app
  VERSION 0.1
  DESCRIPTION "an OpenGL/SFML app"
  LANGUAGES C CXX)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  add_compile_options(-Wall -Wextra -pedantic -Werror)

  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
  set_property(GLOBAL PROPERTY CXX_STANDARD 17)

endif()

add_subdirectory(conan)
add_subdirectory(lib)
add_subdirectory(src)
