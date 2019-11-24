#include "Medium.h"
#include "BenchIncludes.h"

// TODO: Add benchmarks for operator<. operator==, and hash

void mediumLessOperator(State& state)
{
    Medium medium{};
    Medium medium1{};
    medium.randomize();
    medium1.randomize();

    for(auto _ : state)
    {
        auto result = medium < medium1;
        DoNotOptimize(result);
    }
}

BENCHMARK(mediumLessOperator)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void mediumEqualOperator(State& state)
{
    Medium medium{};
    Medium medium1{};
    medium.randomize();
    medium1.randomize();

    for( auto _ : state)
    {
        auto result = medium == medium1;
        DoNotOptimize(result);
    }
}

BENCHMARK(mediumEqualOperator)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void mediumHash( State& state )
{
    Medium medium1{};
    medium1.randomize();

    for(auto _ : state)
    {
        auto hash = std::hash<Medium>{}(medium1);
        DoNotOptimize(hash);
    }
}

BENCHMARK(mediumHash)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();