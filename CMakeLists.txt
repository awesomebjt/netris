# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Define the project name and language
project(netris C)

# Set C99 as the standard for the project
set(CMAKE_C_STANDARD 99)

# Define the path to the local raylib directory
set(RAYLIB_DIR "${CMAKE_SOURCE_DIR}/raylib")

# Add raylib include directories
include_directories(${RAYLIB_DIR}/include)

# Set raylib library directories (assuming compiled libraries are in `./raylib/src`)
link_directories(${RAYLIB_DIR}/lib)

# Add the source files for your project
set(SOURCES
        src/main.c  # Add your source files here
)

# Define the executable target
add_executable(netris ${SOURCES})

# Link raylib (assuming you are linking with the raylib static library or shared library)
# Adjust this based on the specific library files available in your ./raylib directory
target_link_libraries(netris raylib raygui m pthread)

# Set additional compiler flags if needed
target_compile_options(netris PRIVATE -Wall -Wextra)

# Optionally, you can add CMake configuration to use specific versions of GCC if needed
set(CMAKE_C_COMPILER "clang")

# Set output directories for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
