# BUILD_TESTING variable is created by include(CTest)
# It is set to ON by default
if (BUILD_TESTING)
    add_executable(test_bluey test_bluey.cpp)
    target_link_libraries(test_bluey PRIVATE GTest::gtest_main)

    add_executable(test_table test_table.cpp)
    target_link_libraries(test_table PRIVATE GTest::gtest_main table ${PROJECT_NAME})

    include(GoogleTest)
    # Finds all the Google tests associated with the executable
    gtest_discover_tests(test_bluey)
    gtest_discover_tests(test_table)

endif()
