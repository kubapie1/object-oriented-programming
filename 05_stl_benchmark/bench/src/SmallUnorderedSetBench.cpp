#include "Small.h"
#include "BenchIncludes.h"
#include <unordered_set>

void SmallUnorderedSetEmpty(State& state)
{
    auto N = state.range(0);

    Small small{};
    std::unordered_set<Small> mySet{};

    for(long i = 0; i < N; i++){
        small.randomize();
        mySet.insert(small);
    }

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
    std::unordered_set<Small> mySet{};

    for(long i = 0; i < N; i++){
        small.randomize();
        mySet.insert(small);
    }

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
    std::unordered_set<Small> mySet{};

    for(long i = 0; i < N; i++){
        small.randomize();
        mySet.insert(small);
    }

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
    std::unordered_set<Small> mySet{};


    for(auto _ : state)
    {
        state.PauseTiming();
        for(long i = 0; i < N; i++){
            small.randomize();
            mySet.insert(small);
        }
        state.ResumeTiming();
        mySet.clear();
    }
    state.SetComplexityN(N);
}

BENCHMARK(SmallUnorderedSetClear)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void SmallUnorderedSetInsert(State& state)
{
    auto N = state.range(0);
    Small small{};
    std::unordered_set<Small> mySet{};

    for(auto _ : state)
    {
        state.PauseTiming();
        mySet.clear();
        for(long i = 0; i < N; i++){
            small.randomize();
            mySet.insert(small);
        }
        state.ResumeTiming();
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
    std::unordered_set<Small> mySet{};

    for(long i = 0; i < N; i++){
        small.randomize();
        mySet.insert(small);
    }

    for (auto _ : state)
    {
        state.PauseTiming();
        mySet.insert(small);
        state.ResumeTiming();

        auto value = mySet.erase(mySet.cbegin());
        DoNotOptimize(value);

    }
    state.SetComplexityN(N);
}

BENCHMARK(SmallUnorderedSetErase)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void SmallUnorderedSetSwap(State& state)
{
    auto N = state.range(0);
    Small small{};


    Small small1{};


    std::unordered_set<Small> mySet{};
    std::unordered_set<Small> mySet2{};

    for(long i = 0; i < N; i++){
        small.randomize();
        small1.randomize();
        mySet.insert(small);
        mySet2.insert(small1);
    }

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
    std::unordered_set<Small> mySet{};

    for(long i = 0; i < N; i++){
        small.randomize();
        mySet.insert(small);
    }


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

    std::unordered_set<Small> mySet{};

    for(long i = 0; i < N; i++){
        small.randomize();
        mySet.insert(small);
    }

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
    std::unordered_set<Small> mySet{};

    for(long i = 0; i < N; i++){
        small.randomize();
        mySet.insert(small);
    }

    for (auto _ : state)
    {
        auto value = mySet.equal_range(small);
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(SmallUnorderedSetEqualRange)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void SmallUnorderedSetRehash(State& state)
{
    auto N = state.range(0);
    Small small{};

    std::unordered_set<Small> mySet{};

    for (auto _ : state)
    {
        state.PauseTiming();
        mySet.clear();
        for(long i = 0; i < N; i++){
            small.randomize();
            mySet.insert(small);
        }
        state.ResumeTiming();
        mySet.rehash(122);
    }
    state.SetComplexityN(N);
}

BENCHMARK(SmallUnorderedSetRehash)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void SmallUnorderedSetReserve(State& state)
{
    auto N = state.range(0);
    Small small{};

    std::unordered_set<Small> mySet{};

    for (auto _ : state)
    {
        state.PauseTiming();
        mySet.clear();
        for(long i = 0; i < N; i++){
            small.randomize();
            mySet.insert(small);
        }
        state.ResumeTiming();
        mySet.reserve(120);
    }
    state.SetComplexityN(N);

}

BENCHMARK(SmallUnorderedSetReserve)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();
