cmake_minimum_required(VERSION 3.15)

project(sudoManager)
<<<<<<< HEAD
add_library(${PROJECT_NAME} SHARED Item.cpp)
=======
add_library(${PROJECT_NAME} SHARED Menu.cpp Item.cpp)
>>>>>>> 0d81c17c2fef8a0782f394a0e58a00013f916ac2

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
