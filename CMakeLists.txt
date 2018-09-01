cmake_minimum_required(VERSION 3.1)

# project settings

set(target Scanner)
project(${target} CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_AUTOMOC ON)

# dependencies

find_package(Qt5 REQUIRED COMPONENTS Multimedia)
find_package(OpenCV REQUIRED)

# output dir

set(output_dir bin)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${output_dir})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${output_dir})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${output_dir})

# snailsnap sources

set(source_dir src)

set(sources
	${source_dir}/main.cpp
	${source_dir}/camera.cpp)

set(headers
	${source_dir}/camera.hpp)

# target and required libs

add_executable(${target} ${sources} ${headers})
target_link_libraries(${target} Qt5::Multimedia ${OpenCV_LIBS})
