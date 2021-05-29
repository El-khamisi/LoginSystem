cmake_minimum_required(VERSION 3.16)

project(LoginSystem)

set(CMAKE_CXX_STANDARD 20)



set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(LoginSystem  main.cpp  src/User.h src/User.cpp src/Dataset.h src/Dataset.cpp main.cpp)