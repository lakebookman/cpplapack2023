cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Specify the build directory
set(BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR})

# Configure Doxygen
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/main)
configure_file(${SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)

# add source
add_subdirectory(${SOURCE_DIR})

# add tests
enable_testing()
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
