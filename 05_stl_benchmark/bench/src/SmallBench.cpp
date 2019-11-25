#include "Small.h"
#include "BenchIncludes.h"

// TODO: Add benchmarks for operator<. operator==, and hash

void smallLessOperator(State& state)
{
    Small small{};
    Small small1{};

    small.randomize();
    small1.randomize();

    for(auto _ : state)
    {
        auto result = small < small1;
        DoNotOptimize(result);
    }
}

BENCHMARK(smallLessOperator)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();


void smallEqualOperator(State& state)
{
    Small small{};
    Small small1{};
    small.randomize();
    small1.randomize();

    for( auto _ : state)
    {
        auto result = small == small1;
        DoNotOptimize(result);
    }
}

BENCHMARK(smallEqualOperator)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void smallHash( State& state )
{
    Small small1{'a'};

    for(auto _ : state) {
        auto hash = std::hash<Small>{}(small1);
        DoNotOptimize(hash);
    }
}

BENCHMARK(smallHash)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();