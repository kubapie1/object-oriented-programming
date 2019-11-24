#include "Large.h"
#include "BenchIncludes.h"
#include <set>

void LargeSetEmpty(State& state)
{
    auto N = state.range(0);

    Large large{};
    std::set<Large> mySet{};


    for (long i = 0; i < N; ++i) {
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

BENCHMARK(LargeSetEmpty)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void LargeSetSize(State& state)
{
    auto N = state.range(0);

    Large large{};
    std::set<Large> mySet{};

    for (long i = 0; i < N; ++i) {
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

BENCHMARK(LargeSetSize)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void LargeSetMaxSize(State& state)
{
    auto N = state.range(0);

    Large large{};
    std::set<Large> mySet{};

    for (long i = 0; i < N; ++i) {
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

BENCHMARK(LargeSetMaxSize)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void LargeSetClear(State& state)
{
    auto N = state.range(0);

    Large large{};

    std::set<Large> mySet{};

    for(auto _ : state)
    {
        state.PauseTiming();
        for (long i = 0; i < N; ++i) {
            large.randomize();
            mySet.insert(large);
        }
        state.ResumeTiming();
        mySet.clear();
        ClobberMemory();
    }
    state.SetComplexityN(N);
}

BENCHMARK(LargeSetClear)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void LargeSetInsert(State& state)
{
    auto N = state.range(0);
    Large large{};
    std::set<Large> mySet{};

    for(auto _ : state)
    {
        state.PauseTiming();
        mySet.clear();
        for (long i = 0; i < N; ++i) {
            large.randomize();
            mySet.insert(large);
            ClobberMemory();
        }
        state.ResumeTiming();

        auto value = mySet.insert(large);
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(LargeSetInsert)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void LargeSetErase(State& state)
{
    auto N = state.range(0);
    Large large{};

    std::set<Large> mySet{};
    for (long i = 0; i < N; ++i) {
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

BENCHMARK(LargeSetErase)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void LargeSetSwap(State& state)
{
    auto N = state.range(0);

    Large large{};
    Large large1{};

    std::set<Large> mySet{};
    std::set<Large> mySet2{};

    for(long i = 0; i < N; i++) {
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

BENCHMARK(LargeSetSwap)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void LargeSetCount(State& state)
{
    auto N = state.range(0);

    Large large{};
    std::set<Large> mySet{};

    for (long i = 0; i < N; ++i) {
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

BENCHMARK(LargeSetCount)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();


void LargeSetFind(State& state)
{
    auto N = state.range(0);
    Large large{};
    std::set<Large> mySet{};

    for (long i = 0; i < N; ++i) {
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

BENCHMARK(LargeSetFind)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void LargeSetEqualRange(State& state)
{
    auto N = state.range(0);
    Large large{};
    std::set<Large> mySet{};

    for (long i = 0; i < N; ++i) {
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

BENCHMARK(LargeSetEqualRange)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void LargeSetLowerBound(State& state)
{
    auto N = state.range(0);
    Large large{};
    std::set<Large> mySet{};

    for (long i = 0; i < N; ++i) {
        large.randomize();
        mySet.insert(large);
    }

    for (auto _ : state)
    {
        auto value = mySet.lower_bound(large);
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(LargeSetLowerBound)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void LargeSetUpperBound(State& state)
{
    auto N = state.range(0);

    Large large{};
    std::set<Large> mySet{};

    for (long i = 0; i < N; ++i) {
        large.randomize();
        mySet.insert(large);
    }

    for (auto _ : state)
    {
        auto value = mySet.upper_bound(large);
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(LargeSetUpperBound)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();
