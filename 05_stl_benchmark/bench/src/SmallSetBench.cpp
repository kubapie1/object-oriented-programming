#include "Small.h"
#include "BenchIncludes.h"
#include <set>

void SmallSetEmpty(State& state)
{
    auto N = state.range(0);
    Small small{};
    small.randomize();

    std::set<Small> mySet{small};
    for(auto _ : state)
    {
        auto value = mySet.empty();
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(SmallSetEmpty)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void SmallSetSize(State& state)
{
    auto N = state.range(0);
    Small small{};
    small.randomize();
    std::set<Small> mySet{small};

    for(auto _ : state)
    {
        auto value = mySet.size();
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(SmallSetSize)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void SmallSetMaxSize(State& state)
{
    auto N = state.range(0);
    Small small{};
    small.randomize();
    std::set<Small> mySet{small};

    for(auto _ : state)
    {
        auto value = mySet.max_size();
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(SmallSetMaxSize)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void SmallSetClear(State& state)
{
    auto N = state.range(0);
    Small small{};
    small.randomize();
    std::set<Small> mySet{small};

    for(auto _ : state)
    {
        mySet.clear();
    }
    state.SetComplexityN(N);
}

BENCHMARK(SmallSetClear)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void SmallSetInsert(State& state)
{
    auto N = state.range(0);
    Small small{};
    small.randomize();
    std::set<Small> mySet{};

    for(auto _ : state)
    {
        auto value = mySet.insert(small);
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(SmallSetInsert)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void SmallSetErase(State& state)
{
    auto N = state.range(0);
    Small small{};
    small.randomize();
    std::set<Small> mySet{small};

        for (auto _ : state)
        {
            if(!mySet.empty())
            {
                auto value = mySet.erase(mySet.cbegin());
                DoNotOptimize(value);
            }
        }
    state.SetComplexityN(N);
}

BENCHMARK(SmallSetErase)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void SmallSetSwap(State& state)
{
    auto N = state.range(0);
    Small small{};
    small.randomize();

    Small small1{};
    small1.randomize();

    std::set<Small> mySet{small};
    std::set<Small> mySet2{small1};

    for (auto _ : state)
    {
        mySet.swap(mySet2);
    }
    state.SetComplexityN(N);
}

BENCHMARK(SmallSetSwap)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void SmallSetCount(State& state)
{
    auto N = state.range(0);
    Small small{};
    small.randomize();

    std::set<Small> mySet{small};


    for (auto _ : state)
    {
        auto value = mySet.count(small);
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(SmallSetCount)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();


void SmallSetFind(State& state)
{
    auto N = state.range(0);
    Small small{};
    small.randomize();

    std::set<Small> mySet{small};


    for (auto _ : state)
    {
        auto value = mySet.find(small);
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(SmallSetFind)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void SmallSetEqualRange(State& state)
{
    auto N = state.range(0);
    Small small{};
    Small small1{};
    Small small2{};

    small.randomize();
    small1.randomize();
    small2.randomize();


    std::set<Small> mySet{small, small1, small2};


    for (auto _ : state)
    {
        auto value = mySet.equal_range(small1);
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(SmallSetEqualRange)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void SmallSetLowerBound(State& state)
{
    auto N = state.range(0);
    Small small{};
    Small small1{};
    Small small2{};

    small.randomize();
    small1.randomize();
    small2.randomize();


    std::set<Small> mySet{small, small1, small2};


    for (auto _ : state)
    {
        auto value = mySet.lower_bound(small);
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(SmallSetLowerBound)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void SmallSetUpperBound(State& state)
{
    auto N = state.range(0);
    Small small{};
    Small small1{};
    Small small2{};

    small.randomize();
    small1.randomize();
    small2.randomize();


    std::set<Small> mySet{small, small1, small2};


    for (auto _ : state)
    {
        auto value = mySet.upper_bound(small1);
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(SmallSetUpperBound)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();
