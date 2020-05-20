set(SRCS
  app/GameLoop.cpp)

add_library(engine ${SRCS} ${HEADER_LIST})
target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(engine PUBLIC cxx_std_17)

include(${CMAKE_BINARY_DIR}/conan/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)
target_link_libraries(engine PRIVATE glad CONAN_PKG::sfml CONAN_PKG::glm)

add_executable(app main.cpp)
target_compile_features(app PRIVATE cxx_std_17)
target_link_libraries(app PRIVATE engine)

# Symlink resources to build dir
# @TODO: make this more portable at some point in time
set (source "${CMAKE_SOURCE_DIR}/resources")
set (destination "${CMAKE_BINARY_DIR}/resources")
add_custom_command(
 TARGET ${PROJECT_NAME} POST_BUILD
 COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination} 
 DEPENDS ${destination}
 COMMENT "symbolic link resources folder from ${source} => ${destination}"
)
