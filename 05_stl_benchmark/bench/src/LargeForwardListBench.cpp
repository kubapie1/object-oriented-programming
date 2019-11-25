#include "Large.h"
#include "BenchIncludes.h"
#include <forward_list>

void largeForwardListFront(State& state)
{
    auto N = state.range(0);
    std::forward_list<Large> forwardList{};
    Large large{};

    for (long i = 0; i < N; i++) {
        large.randomize();
        forwardList.push_front(large);
    }

    for( auto _ : state)
    {
        auto value = forwardList.front();
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(largeForwardListFront)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void largeForwardListEmpty(State& state)
{
    auto N = state.range(0);
    std::forward_list<Large> forwardList{};
    Large large{};

    for (long i = 0; i < N; i++) {
        large.randomize();
        forwardList.push_front(large);
    }

    for( auto _ : state)
    {
        auto value = forwardList.empty();
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(largeForwardListEmpty)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void largeForwardListMaxSize(State& state)
{
    auto N = state.range(0);
    std::forward_list<Large> forwardList{};
    Large large{};

    for (long i = 0; i < N; i++) {
        large.randomize();
        forwardList.push_front(large);
    }

    for( auto _ : state)
    {
        auto value = forwardList.max_size();
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(largeForwardListMaxSize)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void largeForwardListClear(State& state)
{
    auto N = state.range(0);
    std::forward_list<Large> forwardList{};
    Large large{};


    for( auto _ : state)
    {
        state.PauseTiming();

        for (long i = 0; i < N; i++) {
            large.randomize();
            forwardList.push_front(large);
        }

        state.ResumeTiming();

        forwardList.clear();
    }
    state.SetComplexityN(N);
}

BENCHMARK(largeForwardListClear)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void largeForwardListInsertAfter(State& state)
{
    auto N = state.range(0);
    std::forward_list<Large> forwardList{};

    Large large{};
    Large large2{};

    for( auto _ : state)
    {
        state.PauseTiming();
        forwardList.clear();
        for (long i = 0; i < N; i++) {
            large.randomize();
            forwardList.push_front(large);
        }
        auto beginIt = forwardList.begin();
        large2.randomize();
        state.ResumeTiming();

        forwardList.insert_after(beginIt, large2);
    }
    state.SetComplexityN(N);
}

BENCHMARK(largeForwardListInsertAfter)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void largeForwardListEraseAfter(State& state)
{
    auto N = state.range(0);
    std::forward_list<Large> forwardList{};
    Large large{};


    for( auto _ : state)
    {
        state.PauseTiming();
        for (long i = 0; i < N; i++) {
            large.randomize();
            forwardList.push_front(large);
        }
        large.randomize();
        forwardList.push_front(large);
        state.ResumeTiming();

        forwardList.erase_after(forwardList.before_begin());
    }
    state.SetComplexityN(N);
}

BENCHMARK(largeForwardListEraseAfter)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void largeForwardListPushFront(State& state)
{
    auto N = state.range(0);
    std::forward_list<Large> forwardList{};
    Large large{};

    for( auto _ : state)
    {
        state.PauseTiming();
        forwardList.clear();
        for (long i = 0; i < N; i++) {
            large.randomize();
            forwardList.push_front(large);
        }
        large.randomize();
        state.ResumeTiming();

        forwardList.push_front(large);
    }
    state.SetComplexityN(N);
}

BENCHMARK(largeForwardListPushFront)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void largeForwardListPopFront(State& state)
{
    auto N = state.range(0);
    std::forward_list<Large> forwardList{};
    Large large{};


    for( auto _ : state)
    {
        state.PauseTiming();
        for (long i = 0; i < N; i++) {
            large.randomize();
            forwardList.push_front(large);
        }
        state.ResumeTiming();
        if(!forwardList.empty())
            forwardList.pop_front();
    }
    state.SetComplexityN(N);
}

BENCHMARK(largeForwardListPopFront)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();


void largeForwardListResize(State& state)
{
    auto N = state.range(0);
    std::forward_list<Large> forwardList{};
    Large large{};

    for( auto _ : state)
    {
        state.PauseTiming();
        forwardList.clear();
        for (long i = 0; i < N; i++) {
            large.randomize();
            forwardList.push_front(large);
        }
        state.ResumeTiming();
        forwardList.resize(5);
    }
    state.SetComplexityN(N);
}

BENCHMARK(largeForwardListResize)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void largeForwardListSwap(State& state)
{
    auto N = state.range(0);
    std::forward_list<Large> forwardList{};
    std::forward_list<Large> forwardList2{};
    Large large{};

    for (int i = 0; i < N; i++) {
        large.randomize();
        forwardList.push_front(large);
        large.randomize();
        forwardList2.push_front(large);
    }

    for( auto _ : state)
    {
        forwardList.swap(forwardList2);
    }
    state.SetComplexityN(N);
}

BENCHMARK(largeForwardListSwap)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();


void largeForwardListMerge(State& state)
{
    auto N = state.range(0);
    std::forward_list<Large> forwardList{};
    std::forward_list<Large> forwardList2{};
    Large large{};


    for( auto _ : state)
    {
        state.PauseTiming();
        forwardList.clear();
        forwardList2.clear();
        for (int i = 0; i < N; i++) {
            large.randomize();
            forwardList.push_front(large);
            large.randomize();
            forwardList2.push_front(large);
        }


        state.ResumeTiming();
        forwardList.merge(forwardList2);
    }
    state.SetComplexityN(N);
}

BENCHMARK(largeForwardListMerge)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();


void largeForwardListSpliceAfter(State& state)
{
    auto N = state.range();
    Large large{}, large2{};


    std::forward_list<Large> firstForwardList;
    std::forward_list<Large> s2;


    for( auto _ : state)
    {
        state.PauseTiming();

        firstForwardList.clear();
        s2.clear();
        for (long i = 0; i < N; i++) {
            large.randomize();
            firstForwardList.push_front(large);
            large2.randomize();
            s2.push_front(large2);
        }
        state.ResumeTiming();

        firstForwardList.splice_after(firstForwardList.cbegin(), s2, s2.cbegin(), s2.cend());
    }
    state.SetComplexityN(N);
}

BENCHMARK(largeForwardListSpliceAfter)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();


void largeForwardListRemove(State& state)
{
    auto N = state.range(0);
    std::forward_list<Large> forwardList{};
    Large large{};



    for( auto _ : state)
    {
        state.PauseTiming();

        forwardList.clear();
        for (long i = 0; i < N; i++) {
            large.randomize();
            forwardList.push_front(large);
        }
        state.ResumeTiming();

        forwardList.remove(large);
    }
    state.SetComplexityN(N);
}

BENCHMARK(largeForwardListRemove)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();


void largeForwardListRemoveIf(State& state)
{
    auto N = state.range(0);
   Large large{};

    std::forward_list<Large> forwardList{};

    for( auto _ : state)
    {
        state.PauseTiming();
        forwardList.clear();
        for (long i = 0; i < N; ++i) {
            large.randomize();
            forwardList.push_front(large);
        }
        state.ResumeTiming();
        forwardList.remove_if([](Large n)
        {
            Large x{'g'};
            return n < x;
        });

    }
    state.SetComplexityN(N);
}

BENCHMARK(largeForwardListRemoveIf)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();


void largeForwardListReverse(State& state)
{
    auto N = state.range(0);
    std::forward_list<Large> forwardList{};

    Large large{};
    Large large2{};

    for (long i = 0; i < N; i++) {
        large.randomize();
        forwardList.push_front(large);
        large2.randomize();
        forwardList.push_front(large2);
    }

    for( auto _ : state)
    {
        forwardList.reverse();
    }
    state.SetComplexityN(N);
}

BENCHMARK(largeForwardListReverse)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void largeForwardListUnique(State& state)
{
    auto N = state.range(0);

    Large large{};
    std::forward_list<Large> firstForwardList{};


    for( auto _ : state)
    {
        state.PauseTiming();
        firstForwardList.clear();
        for (long i = 0; i < N; i++) {
            large.randomize();
            firstForwardList.push_front(large);
        }
        state.ResumeTiming();
        firstForwardList.unique();
    }
    state.SetComplexityN(N);
}

BENCHMARK(largeForwardListUnique)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void largeForwardListSort(State& state)
{
    auto N = state.range(0);
    std::forward_list<Large> forwardList{};

    Large large{};

    for( auto _ : state)
    {
        state.PauseTiming();
        forwardList.clear();
        for (int i = 0; i < N; i++) {
            large.randomize();
            forwardList.push_front(large);
        }
        state.ResumeTiming();
        forwardList.sort();
    }
    state.SetComplexityN(N);
}

BENCHMARK(largeForwardListSort)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();