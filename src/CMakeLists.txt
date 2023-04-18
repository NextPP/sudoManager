cmake_minimum_required(VERSION 3.15)

project(sudoManager)
add_library(${PROJECT_NAME} SHARED Menu.cpp Item.cpp Bill.cpp Payment.cpp
                                   TableSeat.cpp Table.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
