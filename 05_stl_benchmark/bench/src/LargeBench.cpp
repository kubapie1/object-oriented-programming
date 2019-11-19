#include "Large.h"
#include "BenchIncludes.h"

// TODO: Add benchmarks for operator<. operator==, and hash

void largeLessOperator(State& state)
{
    Large large{};
    Large large1{};
    large.randomize();
    large1.randomize();

    for(auto _ : state)
    {
        auto result = large < large1;
        DoNotOptimize(result);
    }
}

BENCHMARK(largeLessOperator);

void largeEqualOperator(State& state)
{
    Large large{};
    Large large1{};
    large.randomize();
    large1.randomize();

    for( auto _ : state)
    {
        auto result = large == large1;
        DoNotOptimize(result);
    }
}

BENCHMARK(largeEqualOperator);

void largeHash( State& state )
{
    Large large{};

    large.randomize();

    for(auto _ : state) {
        std::hash<Large>{}(large);
    }
}

BENCHMARK(largeHash);