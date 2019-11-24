#include "Medium.h"
#include "BenchIncludes.h"
#include <set>

void MediumSetEmpty(State& state)
{
    auto N = state.range(0);

    Medium medium{};
    std::set<Medium> mySet{};

    for (long i = 0; i < N; ++i) {
        medium.randomize();
        mySet.insert(medium);
    }

    for(auto _ : state)
    {
        auto value = mySet.empty();
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumSetEmpty)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumSetSize(State& state)
{
    auto N = state.range(0);

    Medium medium{};
    std::set<Medium> mySet{};

    for (long i = 0; i < N; ++i) {
        medium.randomize();
        mySet.insert(medium);
    }

    for(auto _ : state)
    {
        auto value = mySet.size();
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumSetSize)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumSetMaxSize(State& state)
{
    auto N = state.range(0);

    Medium medium{};
    std::set<Medium> mySet{};

    for (long i = 0; i < N; ++i) {
        medium.randomize();
        mySet.insert(medium);
    }

    for(auto _ : state)
    {
        auto value = mySet.max_size();
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumSetMaxSize)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumSetClear(State& state)
{
    auto N = state.range(0);

    Medium medium{};

    std::set<Medium> mySet{};

    for(auto _ : state)
    {
        state.PauseTiming();
        for (long i = 0; i < N; ++i) {
            medium.randomize();
            mySet.insert(medium);
        }
        state.ResumeTiming();
        mySet.clear();
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumSetClear)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumSetInsert(State& state)
{
    auto N = state.range(0);
    Medium medium{};
    std::set<Medium> mySet{};

    for(auto _ : state)
    {
        state.PauseTiming();
        mySet.clear();
        for (long i = 0; i < N; ++i) {
            medium.randomize();
            mySet.insert(medium);
        }
        state.ResumeTiming();

        auto value = mySet.insert(medium);
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumSetInsert)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumSetErase(State& state)
{
    auto N = state.range(0);
    Medium medium{};

    std::set<Medium> mySet{};
    for (long i = 0; i < N; ++i) {
        medium.randomize();
        mySet.insert(medium);
    }

        for (auto _ : state)
        {
            state.PauseTiming();
            mySet.insert(medium);
            state.ResumeTiming();

            auto value = mySet.erase(mySet.cbegin());
            DoNotOptimize(value);
        }
    state.SetComplexityN(N);
}

BENCHMARK(MediumSetErase)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumSetSwap(State& state)
{
    auto N = state.range(0);

    Medium medium{};
    Medium medium1{};

    std::set<Medium> mySet{};
    std::set<Medium> mySet2{};

    for(long i = 0; i < N; i++) {
        medium.randomize();
        medium1.randomize();
        mySet.insert(medium);
        mySet2.insert(medium1);
    }
    for (auto _ : state)
    {
        mySet.swap(mySet2);
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumSetSwap)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumSetCount(State& state)
{
    auto N = state.range(0);

    Medium medium{};
    std::set<Medium> mySet{};

    for (long i = 0; i < N; ++i) {
        medium.randomize();
        mySet.insert(medium);
    }

    for (auto _ : state)
    {
        auto value = mySet.count(medium);
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumSetCount)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();


void MediumSetFind(State& state)
{
    auto N = state.range(0);
    Medium medium{};
    std::set<Medium> mySet{};

    for (long i = 0; i < N; ++i) {
        medium.randomize();
        mySet.insert(medium);
    }

    for (auto _ : state)
    {
        auto value = mySet.find(medium);
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumSetFind)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumSetEqualRange(State& state)
{
    auto N = state.range(0);
    Medium medium{};
    std::set<Medium> mySet{};

    for (long i = 0; i < N; ++i) {
        medium.randomize();
        mySet.insert(medium);
    }

    for (auto _ : state)
    {
        auto value = mySet.equal_range(medium);
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumSetEqualRange)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumSetLowerBound(State& state)
{
    auto N = state.range(0);
    Medium medium{};
    std::set<Medium> mySet{};

    for (long i = 0; i < N; ++i) {
        medium.randomize();
        mySet.insert(medium);
    }

    for (auto _ : state)
    {
        auto value = mySet.lower_bound(medium);
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumSetLowerBound)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumSetUpperBound(State& state)
{
    auto N = state.range(0);

    Medium medium{};
    std::set<Medium> mySet{};

    for (long i = 0; i < N; ++i) {
        medium.randomize();
        mySet.insert(medium);
    }

    for (auto _ : state)
    {
        auto value = mySet.upper_bound(medium);
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumSetUpperBound)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();
