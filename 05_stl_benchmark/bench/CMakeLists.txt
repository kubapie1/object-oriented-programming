set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE  "-O3")
set(BENCH_HEADERS include/BenchIncludes.h)
set(BENCH_SOURCES src/DummyBench.cpp src/ExampleBench.cpp src/PauseAndResumeBench.cpp src/SmallBench.cpp src/MediumBench.cpp src/LargeBench.cpp
 src/SmallForwardListBench.cpp src/SmallSetBench.cpp src/SmallUnorderedSetBench.cpp src/MediumForwardListBench.cpp src/MediumSetBench.cpp src/MediumUnorderedSetBench.cpp src/LargeForwardListBench.cpp src/LargeSetBench.cpp src/LargeUnorderedSetBench.cpp)

#set(BENCH_SOURCES src/SmallBench.cpp src/MediumBench.cpp src/LargeBench.cpp)



add_executable(05_stl_benchmark_bench ${BENCH_HEADERS} ${BENCH_SOURCES})
target_include_directories(05_stl_benchmark_bench PUBLIC include)
target_link_libraries(05_stl_benchmark_bench 05_stl_benchmark_lib benchmark benchmark_main pthread)
