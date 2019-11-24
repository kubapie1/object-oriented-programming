#include "Medium.h"
#include "BenchIncludes.h"
#include <unordered_set>

void MediumUnorderedSetEmpty(State& state)
{
    auto N = state.range(0);

    Medium medium{};
    std::unordered_set<Medium> mySet{};

    for(long i = 0; i < N; i++){
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

BENCHMARK(MediumUnorderedSetEmpty)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumUnorderedSetSize(State& state)
{
    auto N = state.range(0);

    Medium medium{};
    std::unordered_set<Medium> mySet{};

    for(long i = 0; i < N; i++){
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

BENCHMARK(MediumUnorderedSetSize)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumUnorderedSetMaxSize(State& state)
{
    auto N = state.range(0);

    Medium medium{};
    std::unordered_set<Medium> mySet{};

    for(long i = 0; i < N; i++){
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

BENCHMARK(MediumUnorderedSetMaxSize)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumUnorderedSetClear(State& state)
{
    auto N = state.range(0);

    Medium medium{};
    std::unordered_set<Medium> mySet{};


    for(auto _ : state)
    {
        state.PauseTiming();
        for(long i = 0; i < N; i++){
            medium.randomize();
            mySet.insert(medium);
        }
        state.ResumeTiming();
        mySet.clear();
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumUnorderedSetClear)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumUnorderedSetInsert(State& state)
{
    auto N = state.range(0);
    Medium medium{};
    std::unordered_set<Medium> mySet{};

    for(auto _ : state)
    {
        state.PauseTiming();
        mySet.clear();
        for(long i = 0; i < N; i++){
            medium.randomize();
            mySet.insert(medium);
        }
        state.ResumeTiming();
        auto value = mySet.insert(medium);
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumUnorderedSetInsert)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumUnorderedSetErase(State& state)
{
    auto N = state.range(0);

    Medium medium{};
    std::unordered_set<Medium> mySet{};

    for(long i = 0; i < N; i++){
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

BENCHMARK(MediumUnorderedSetErase)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumUnorderedSetSwap(State& state)
{
    auto N = state.range(0);
    Medium medium{};


    Medium medium1{};


    std::unordered_set<Medium> mySet{};
    std::unordered_set<Medium> mySet2{};

    for(long i = 0; i < N; i++){
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

BENCHMARK(MediumUnorderedSetSwap)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumUnorderedSetCount(State& state)
{
    auto N = state.range(0);
    Medium medium{};
    std::unordered_set<Medium> mySet{};

    for(long i = 0; i < N; i++){
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

BENCHMARK(MediumUnorderedSetCount)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();


void MediumUnorderedSetFind(State& state)
{
    auto N = state.range(0);
    Medium medium{};

    std::unordered_set<Medium> mySet{};

    for(long i = 0; i < N; i++){
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

BENCHMARK(MediumUnorderedSetFind)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumUnorderedSetEqualRange(State& state)
{
    auto N = state.range(0);

    Medium medium{};
    std::unordered_set<Medium> mySet{};

    for(long i = 0; i < N; i++){
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

BENCHMARK(MediumUnorderedSetEqualRange)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumUnorderedSetRehash(State& state)
{
    auto N = state.range(0);
    Medium medium{};

    std::unordered_set<Medium> mySet{};

    for (auto _ : state)
    {
        state.PauseTiming();
        mySet.clear();
        for(long i = 0; i < N; i++){
            medium.randomize();
            mySet.insert(medium);
        }
        state.ResumeTiming();
        mySet.rehash(122);
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumUnorderedSetRehash)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumUnorderedSetReserve(State& state)
{
    auto N = state.range(0);
    Medium medium{};

    std::unordered_set<Medium> mySet{};

    for (auto _ : state)
    {
        state.PauseTiming();
        mySet.clear();
        for(long i = 0; i < N; i++){
            medium.randomize();
            mySet.insert(medium);
        }
        state.ResumeTiming();
        mySet.reserve(120);
    }
    state.SetComplexityN(N);

}

BENCHMARK(MediumUnorderedSetReserve)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();
