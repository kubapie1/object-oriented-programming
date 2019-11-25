#include "Medium.h"
#include "BenchIncludes.h"
#include <forward_list>

void MediumForwardListFront(State& state)
{
    auto N = state.range(0);
    std::forward_list<Medium> forwardList{};
    Medium medium{};

    for (long i = 0; i < N; i++) {
        medium.randomize();
        forwardList.push_front(medium);
    }

    for( auto _ : state)
    {
        auto value = forwardList.front();
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumForwardListFront)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumForwardListEmpty(State& state)
{
    auto N = state.range(0);
    std::forward_list<Medium> forwardList{};
    Medium medium{};

    for (long i = 0; i < N; i++) {
        medium.randomize();
        forwardList.push_front(medium);
    }

    for( auto _ : state)
    {
        auto value = forwardList.empty();
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumForwardListEmpty)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumForwardListMaxSize(State& state)
{
    auto N = state.range(0);
    std::forward_list<Medium> forwardList{};
    Medium medium{};

    for (long i = 0; i < N; i++) {
        medium.randomize();
        forwardList.push_front(medium);
    }

    for( auto _ : state)
    {
        auto value = forwardList.max_size();
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumForwardListMaxSize)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumForwardListClear(State& state)
{
    auto N = state.range(0);
    std::forward_list<Medium> forwardList{};
    Medium medium{};


    for( auto _ : state)
    {
        state.PauseTiming();

        for (long i = 0; i < N; i++) {
            medium.randomize();
            forwardList.push_front(medium);
        }

        state.ResumeTiming();

        forwardList.clear();
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumForwardListClear)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumForwardListInsertAfter(State& state)
{
    auto N = state.range(0);
    std::forward_list<Medium> forwardList{};

    Medium medium{};
    Medium medium2{};

    for( auto _ : state)
    {
        state.PauseTiming();
        forwardList.clear();
        for (long i = 0; i < N; i++) {
            medium.randomize();
            forwardList.push_front(medium);
        }
        auto beginIt = forwardList.begin();
        medium2.randomize();
        state.ResumeTiming();

        forwardList.insert_after(beginIt, medium2);
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumForwardListInsertAfter)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumForwardListEraseAfter(State& state)
{
    auto N = state.range(0);
    std::forward_list<Medium> forwardList{};
    Medium medium{};


    for( auto _ : state)
    {
        state.PauseTiming();
        for (long i = 0; i < N; i++) {
            medium.randomize();
            forwardList.push_front(medium);
        }
        medium.randomize();
        forwardList.push_front(medium);
        state.ResumeTiming();

        forwardList.erase_after(forwardList.before_begin());
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumForwardListEraseAfter)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumForwardListPushFront(State& state)
{
    auto N = state.range(0);
    std::forward_list<Medium> forwardList{};
    Medium medium{};

    for( auto _ : state)
    {
        state.PauseTiming();
        forwardList.clear();
        for (long i = 0; i < N; i++) {
            medium.randomize();
            forwardList.push_front(medium);
        }
        medium.randomize();
        state.ResumeTiming();

        forwardList.push_front(medium);
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumForwardListPushFront)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumForwardListPopFront(State& state)
{
    auto N = state.range(0);
    std::forward_list<Medium> forwardList{};
    Medium medium{};


    for( auto _ : state)
    {
        state.PauseTiming();
        for (long i = 0; i < N; i++) {
            medium.randomize();
            forwardList.push_front(medium);
        }
        state.ResumeTiming();
        if(!forwardList.empty())
            forwardList.pop_front();
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumForwardListPopFront)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();


void MediumForwardListResize(State& state)
{
    auto N = state.range(0);
    std::forward_list<Medium> forwardList{};
    Medium medium{};

    for( auto _ : state)
    {
        state.PauseTiming();
        forwardList.clear();
        for (long i = 0; i < N; i++) {
            medium.randomize();
            forwardList.push_front(medium);
        }
        state.ResumeTiming();
        forwardList.resize(5);
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumForwardListResize)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumForwardListSwap(State& state)
{
    auto N = state.range(0);
    std::forward_list<Medium> forwardList{};
    std::forward_list<Medium> forwardList2{};
    Medium medium{};

    for (int i = 0; i < N; i++) {
        medium.randomize();
        forwardList.push_front(medium);
        medium.randomize();
        forwardList2.push_front(medium);
    }

    for( auto _ : state)
    {
        forwardList.swap(forwardList2);
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumForwardListSwap)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();


void MediumForwardListMerge(State& state)
{
    auto N = state.range(0);
    std::forward_list<Medium> forwardList{};
    std::forward_list<Medium> forwardList2{};
    Medium medium{};


    for( auto _ : state)
    {
        state.PauseTiming();
        forwardList.clear();
        forwardList2.clear();
        for (int i = 0; i < N; i++) {
            medium.randomize();
            forwardList.push_front(medium);
            medium.randomize();
            forwardList2.push_front(medium);
        }


        state.ResumeTiming();
        forwardList.merge(forwardList2);
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumForwardListMerge)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();


void MediumForwardListSpliceAfter(State& state)
{
    auto N = state.range();
    Medium medium{}, medium2{};


    std::forward_list<Medium> firstForwardList;
    std::forward_list<Medium> s2;


    for( auto _ : state)
    {
        state.PauseTiming();

        firstForwardList.clear();
        s2.clear();
        for (long i = 0; i < N; i++) {
            medium.randomize();
            firstForwardList.push_front(medium);
            medium2.randomize();
            s2.push_front(medium2);
        }
        state.ResumeTiming();

        firstForwardList.splice_after(firstForwardList.cbegin(), s2, s2.cbegin(), s2.cend());
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumForwardListSpliceAfter)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();


void MediumForwardListRemove(State& state)
{
    auto N = state.range(0);
    std::forward_list<Medium> forwardList{};
    Medium medium{};



    for( auto _ : state)
    {
        state.PauseTiming();

        forwardList.clear();
        for (long i = 0; i < N; i++) {
            medium.randomize();
            forwardList.push_front(medium);
        }
        state.ResumeTiming();

        forwardList.remove(medium);
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumForwardListRemove)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();


void MediumForwardListRemoveIf(State& state)
{
    auto N = state.range(0);
    Medium medium{};

    std::forward_list<Medium> forwardList{};

    for( auto _ : state)
    {
        state.PauseTiming();
        forwardList.clear();
        for (long i = 0; i < N; ++i) {
            medium.randomize();
            forwardList.push_front(medium);
        }
        state.ResumeTiming();
        forwardList.remove_if([](Medium n)
        {
            Medium x{};
            x.randomize();
            return n < x;
        });

    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumForwardListRemoveIf)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();


void MediumForwardListReverse(State& state)
{
    auto N = state.range(0);
    std::forward_list<Medium> forwardList{};

    Medium medium{};
    Medium medium2{};

    for (long i = 0; i < N; i++) {
        medium.randomize();
        forwardList.push_front(medium);
        medium2.randomize();
        forwardList.push_front(medium2);
    }

    for( auto _ : state)
    {
        forwardList.reverse();
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumForwardListReverse)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumForwardListUnique(State& state)
{
    auto N = state.range(0);

    Medium medium{};
    std::forward_list<Medium> firstForwardList{};


    for( auto _ : state)
    {
        state.PauseTiming();
        firstForwardList.clear();
        for (long i = 0; i < N; i++) {
            medium.randomize();
            firstForwardList.push_front(medium);
        }
        state.ResumeTiming();
        firstForwardList.unique();
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumForwardListUnique)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void MediumForwardListSort(State& state)
{
    auto N = state.range(0);
    std::forward_list<Medium> forwardList{};

    Medium medium{};

    for( auto _ : state)
    {
        state.PauseTiming();
        forwardList.clear();
        for (int i = 0; i < N; i++) {
            medium.randomize();
            forwardList.push_front(medium);
        }
        state.ResumeTiming();
        forwardList.sort();
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumForwardListSort)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();