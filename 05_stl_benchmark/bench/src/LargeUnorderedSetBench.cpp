#include "Large.h"
#include "BenchIncludes.h"
#include <unordered_set>

void LargeUnorderedSetEmpty(State& state)
{
    auto N = state.range(0);

    Large large{};
    std::unordered_set<Large> mySet{};

    for(long i = 0; i < N; i++){
        large.randomize();
        mySet.insert(large);
    }

    for(auto _ : state)
    {
        auto value = mySet.empty();
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(LargeUnorderedSetEmpty)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void LargeUnorderedSetSize(State& state)
{
    auto N = state.range(0);

    Large large{};
    std::unordered_set<Large> mySet{};

    for(long i = 0; i < N; i++){
        large.randomize();
        mySet.insert(large);
    }

    for(auto _ : state)
    {
        auto value = mySet.size();
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(LargeUnorderedSetSize)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void LargeUnorderedSetMaxSize(State& state)
{
    auto N = state.range(0);

    Large large{};
    std::unordered_set<Large> mySet{};

    for(long i = 0; i < N; i++){
        large.randomize();
        mySet.insert(large);
    }

    for(auto _ : state)
    {
        auto value = mySet.max_size();
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(LargeUnorderedSetMaxSize)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void LargeUnorderedSetClear(State& state)
{
    auto N = state.range(0);

    Large large{};
    std::unordered_set<Large> mySet{};


    for(auto _ : state)
    {
        state.PauseTiming();
        for(long i = 0; i < N; i++){
            large.randomize();
            mySet.insert(large);
        }
        state.ResumeTiming();
        mySet.clear();
    }
    state.SetComplexityN(N);
}

BENCHMARK(LargeUnorderedSetClear)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void LargeUnorderedSetInsert(State& state)
{
    auto N = state.range(0);
    Large large{};
    std::unordered_set<Large> mySet{};

    for(auto _ : state)
    {
        state.PauseTiming();
        mySet.clear();
        for(long i = 0; i < N; i++){
            large.randomize();
            mySet.insert(large);
        }
        state.ResumeTiming();
        auto value = mySet.insert(large);
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(LargeUnorderedSetInsert)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void LargeUnorderedSetErase(State& state)
{
    auto N = state.range(0);

    Large large{};
    std::unordered_set<Large> mySet{};

    for(long i = 0; i < N; i++){
        large.randomize();
        mySet.insert(large);
    }

    for (auto _ : state)
    {
        state.PauseTiming();
        mySet.insert(large);
        state.ResumeTiming();

        auto value = mySet.erase(mySet.cbegin());
        DoNotOptimize(value);

    }
    state.SetComplexityN(N);
}

BENCHMARK(LargeUnorderedSetErase)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void LargeUnorderedSetSwap(State& state)
{
    auto N = state.range(0);
    Large large{};


    Large large1{};


    std::unordered_set<Large> mySet{};
    std::unordered_set<Large> mySet2{};

    for(long i = 0; i < N; i++){
        large.randomize();
        large1.randomize();
        mySet.insert(large);
        mySet2.insert(large1);
    }

    for (auto _ : state)
    {
        mySet.swap(mySet2);
    }
    state.SetComplexityN(N);
}

BENCHMARK(LargeUnorderedSetSwap)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void LargeUnorderedSetCount(State& state)
{
    auto N = state.range(0);
    Large large{};
    std::unordered_set<Large> mySet{};

    for(long i = 0; i < N; i++){
        large.randomize();
        mySet.insert(large);
    }


    for (auto _ : state)
    {
        auto value = mySet.count(large);
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(LargeUnorderedSetCount)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();


void LargeUnorderedSetFind(State& state)
{
    auto N = state.range(0);
    Large large{};

    std::unordered_set<Large> mySet{};

    for(long i = 0; i < N; i++){
        large.randomize();
        mySet.insert(large);
    }

    for (auto _ : state)
    {
        auto value = mySet.find(large);
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(LargeUnorderedSetFind)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void LargeUnorderedSetEqualRange(State& state)
{
    auto N = state.range(0);

    Large large{};
    std::unordered_set<Large> mySet{};

    for(long i = 0; i < N; i++){
        large.randomize();
        mySet.insert(large);
    }

    for (auto _ : state)
    {
        auto value = mySet.equal_range(large);
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(LargeUnorderedSetEqualRange)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void LargeUnorderedSetRehash(State& state)
{
    auto N = state.range(0);
    Large large{};

    std::unordered_set<Large> mySet{};

    for (auto _ : state)
    {
        state.PauseTiming();
        mySet.clear();
        for(long i = 0; i < N; i++){
            large.randomize();
            mySet.insert(large);
        }
        state.ResumeTiming();
        mySet.rehash(122);
    }
    state.SetComplexityN(N);
}

BENCHMARK(LargeUnorderedSetRehash)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void LargeUnorderedSetReserve(State& state)
{
    auto N = state.range(0);
    Large large{};

    std::unordered_set<Large> mySet{};

    for (auto _ : state)
    {
        state.PauseTiming();
        mySet.clear();
        for(long i = 0; i < N; i++){
            large.randomize();
            mySet.insert(large);
        }
        state.ResumeTiming();
        mySet.reserve(120);
    }
    state.SetComplexityN(N);

}

BENCHMARK(LargeUnorderedSetReserve)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();
