cmake_minimum_required(VERSION 3.15)

project(sudoManager)

add_library(${PROJECT_NAME} SHARED Item.cpp TableSeat.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
