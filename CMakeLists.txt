cmake_minimum_required(VERSION 3.10)
set(CMAKE_GENERATOR "Unix Makefiles" CACHE INTERNAL "" FORCE)

# Set the project name
project(Retreat)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Vulkan
find_package(Vulkan REQUIRED)

# Recursively find all source files
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")

# Set the output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

# Add the executable with the specified name
add_executable(retreat ${SOURCES})

# Include directories
target_include_directories(retreat PRIVATE ${Vulkan_INCLUDE_DIRS})

# Link Vulkan library
target_link_libraries(retreat PRIVATE ${Vulkan_LIBRARIES})