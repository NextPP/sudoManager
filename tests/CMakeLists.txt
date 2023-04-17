# BUILD_TESTING variable is created by include(CTest) It is set to ON by default
if(BUILD_TESTING)
  add_executable(test_bluey test_bluey.cpp)

  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

  target_link_libraries(test_bluey PRIVATE GTest::gtest_main sudoManager)

  include(GoogleTest)
  # Finds all the Google tests associated with the executable
  gtest_discover_tests(test_bluey)
endif()
