cmake_minimum_required(VERSION 3.15)

project(
  sudoManager
  VERSION 0.1
  DESCRIPTION
    "A simple restaurant management system run entirely by the only Bluey"
  LANGUAGES CXX)



if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR "In-source builds are not allowed,please make new directory")
endif()

add_subdirectory(bin)

set(SOURCE_FILES bin/bluey.cpp src/Item.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC include/sudoManager)



target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)