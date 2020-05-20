include (conan.cmake)
conan_cmake_run(CONANFILE conanfile.txt
  BASIC_SETUP CMAKE_TARGETS
  BUILD missing)
