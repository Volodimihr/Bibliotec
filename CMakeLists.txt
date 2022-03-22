# CMakeList.txt : CMake project for Bibliotec, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.15)

project (Bibliotec VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source to this project's executable.
add_executable (Bibliotec Struct.h Bibliotec.h Bibliotec.cpp Books.h Books.cpp Readers.h Readers.cpp)

# TODO: Add tests and install targets if needed.
