#include "Small.h"
#include "BenchIncludes.h"
#include <unordered_set>

void SmallUnorderedSetEmpty(State& state)
{
    auto N = state.range(0);
    Small small{};
    small.randomize();

    std::unordered_set<Small> mySet{small};
    for(auto _ : state)
    {
        auto value = mySet.empty();
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(SmallUnorderedSetEmpty)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void SmallUnorderedSetSize(State& state)
{
    auto N = state.range(0);
    Small small{};
    small.randomize();
    std::unordered_set<Small> mySet{small};

    for(auto _ : state)
    {
        auto value = mySet.size();
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(SmallUnorderedSetSize)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void SmallUnorderedSetMaxSize(State& state)
{
    auto N = state.range(0);
    Small small{};
    small.randomize();
    std::unordered_set<Small> mySet{small};

    for(auto _ : state)
    {
        auto value = mySet.max_size();
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(SmallUnorderedSetMaxSize)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void SmallUnorderedSetClear(State& state)
{
    auto N = state.range(0);
    Small small{};
    small.randomize();
    std::unordered_set<Small> mySet{small};

    for(auto _ : state)
    {
        mySet.clear();
    }
    state.SetComplexityN(N);
}

BENCHMARK(SmallUnorderedSetClear)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void SmallUnorderedSetInsert(State& state)
{
    auto N = state.range(0);
    Small small{};
    small.randomize();
    std::unordered_set<Small> mySet{};

    for(auto _ : state)
    {
        auto value = mySet.insert(small);
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(SmallUnorderedSetInsert)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void SmallUnorderedSetErase(State& state)
{
    auto N = state.range(0);
    Small small{};
    small.randomize();
    std::unordered_set<Small> mySet{small};

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

BENCHMARK(SmallUnorderedSetErase)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void SmallUnorderedSetSwap(State& state)
{
    auto N = state.range(0);
    Small small{};
    small.randomize();

    Small small1{};
    small1.randomize();

    std::unordered_set<Small> mySet{small};
    std::unordered_set<Small> mySet2{small1};

    for (auto _ : state)
    {
        mySet.swap(mySet2);
    }
    state.SetComplexityN(N);
}

BENCHMARK(SmallUnorderedSetSwap)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void SmallUnorderedSetCount(State& state)
{
    auto N = state.range(0);
    Small small{};
    small.randomize();

    std::unordered_set<Small> mySet{small};


    for (auto _ : state)
    {
        auto value = mySet.count(small);
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(SmallUnorderedSetCount)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();


void SmallUnorderedSetFind(State& state)
{
    auto N = state.range(0);
    Small small{};
    small.randomize();

    std::unordered_set<Small> mySet{small};


    for (auto _ : state)
    {
        auto value = mySet.find(small);
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(SmallUnorderedSetFind)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void SmallUnorderedSetEqualRange(State& state)
{
    auto N = state.range(0);
    Small small{};
    Small small1{};
    Small small2{};

    small.randomize();
    small1.randomize();
    small2.randomize();


    std::unordered_set<Small> mySet{small, small1, small2};


    for (auto _ : state)
    {
        auto value = mySet.equal_range(small1);
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(SmallUnorderedSetEqualRange)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void SmallUnorderedSetRehash(State& state)
{
    auto N = state.range(0);
    Small small{};
    Small small1{};
    Small small2{};

    small.randomize();
    small1.randomize();
    small2.randomize();

    std::unordered_set<Small> mySet{small, small1, small2};

    for (auto _ : state)
    {
        mySet.rehash(4);
    }
    state.SetComplexityN(N);
}

BENCHMARK(SmallUnorderedSetRehash)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void SmallUnorderedSetReserve(State& state)
{
    auto N = state.range(0);
    Small small{};
    Small small1{};
    Small small2{};

    small.randomize();
    small1.randomize();
    small2.randomize();

    std::unordered_set<Small> mySet{small, small1, small2};

    for (auto _ : state)
    {
        mySet.reserve(30);
    }
    state.SetComplexityN(N);

}

BENCHMARK(SmallUnorderedSetReserve)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();
