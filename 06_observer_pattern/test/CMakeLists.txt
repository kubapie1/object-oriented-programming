set(TEST_HEADERS include/TestIncludes.h)
set(TEST_SOURCES src/DummyTest.cpp src/DisplacementTest.cpp)

add_executable(06_observer_pattern_test ${TEST_HEADERS} ${TEST_SOURCES})
target_include_directories(06_observer_pattern_test PUBLIC include)
target_link_libraries(06_observer_pattern_test 06_observer_pattern_lib gtest gtest_main pthread)
