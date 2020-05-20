# Template for OpenGL apps using sfml, glad, and glm

### To use:
- Update CMakeLists.txt with project name and description
- Update targets in src/CMakeLists.txt with the new project name
- Rename src/app to src/<project>
- Update README.md

### To build:
- `mkdir build && cd ./build`
- `cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release`
- `cmake --build .`
