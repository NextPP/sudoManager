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

# Ensures latest GTest Library
include(cmake/UpdateSubmodules.cmake)

# Enables BUILD_TESTING
include(CTest)

add_subdirectory(extern)
add_subdirectory(bin)