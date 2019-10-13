cmake_minimum_required(VERSION 3.13)
project(01_cmake)

include_directories(../googletest/googletest/include)

link_directories(../googletest/build/lib)

ADD_LIBRARY(utils src/Dummy.cpp src/Dummy.h src/Dummy.cpp test/test.cpp)

include_directories("${PROJECT_SOURCE_DIR}/utils")

add_executable(main src/main.cpp)

target_link_libraries(main utils)

add_executable(mainTest test/test.cpp)

target_link_libraries(mainTest gtest gtest_main pthread utils)