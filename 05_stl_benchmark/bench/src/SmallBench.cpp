#include "Small.h"
#include "BenchIncludes.h"

// TODO: Add benchmarks for operator<. operator==, and hash

void smallLessOperator(State& state)
{
    Small small{'a'};
    Small small1{'v'};

    for(auto _ : state)
    {
        auto result = small < small1;
        DoNotOptimize(result);
    }
}

BENCHMARK(smallLessOperator);

void smallEqualOperator(State& state)
{
    Small small{'c'};
    Small small1{'c'};

    for( auto _ : state)
    {
        auto result = small == small1;
        DoNotOptimize(result);
    }
}

BENCHMARK(smallEqualOperator);

void smallHash( State& state )
{
    Small small1{'a'};
    for(auto _ : state) {
        std::hash<Small>{}(small1);
    }
}

BENCHMARK(smallHash);