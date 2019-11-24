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

BENCHMARK(largeLessOperator)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

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

BENCHMARK(largeEqualOperator)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void largeHash( State& state )
{
    Large large{};

    large.randomize();

    for(auto _ : state) {
        auto hash = std::hash<Large>{}(large);
        DoNotOptimize(hash);
    }
}

BENCHMARK(largeHash)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();