add_subdirectory(/usr/src/gtest ${PROJECT_BINARY_DIR}/gtest)

include(CTest)

add_executable(test_asd test_asd.cpp)
target_link_libraries(test_asd
    gtest gtest_main)

add_test(test_asd test_asd)

# set(TEST_BINARY ${PROJECT_NAME}_test)

# add_executable(${TEST_BINARY} test_tools.cpp)

# target_link_libraries(${TEST_BINARY}
#     tools
#     gtest gtest_main
# )

# add_test(
#     NAME ${TEST_BINARY}
#     COMMAND ${EXECUTABLE_OUTPUT_PATH}/${TEST_BINARY})