cmake_minimum_required(VERSION 3.15)

add_executable(bluey bluey.cpp)
target_compile_features(bluey PRIVATE cxx_std_20)

target_link_libraries(bluey sudoManager)
