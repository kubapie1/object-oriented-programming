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

BENCHMARK(mediumLessOperator);

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

BENCHMARK(mediumEqualOperator);

void mediumHash( State& state )
{
    Medium medium1{};
    medium1.randomize();

    for(auto _ : state)
    {
        std::hash<Medium>{}(medium1);
    }
}

BENCHMARK(mediumHash);