#include "Small.h"
#include "BenchIncludes.h"
#include <forward_list>

void smallForwardListFront(State& state)
{
    auto N = state.range(0);
    std::forward_list<Small> forwardList{};
    Small small{};

    for (int i = 0; i < N; i++) {
        small.randomize();
        forwardList.push_front(small);
    }

    for( auto _ : state)
    {
        auto value = forwardList.front();
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(smallForwardListFront)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void smallForwardListEmpty(State& state)
{
    auto N = state.range(0);
    std::forward_list<Small> forwardList{};
    Small small{};

    for (int i = 0; i < N; i++) {
        small.randomize();
        forwardList.push_front(small);
    }

    for( auto _ : state)
    {
        auto value = forwardList.empty();
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(smallForwardListEmpty)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void smallForwardListMaxSize(State& state)
{
    auto N = state.range(0);
    std::forward_list<Small> forwardList{};
    Small small{};

    for (int i = 0; i < N; i++) {
        small.randomize();
        forwardList.push_front(small);
    }

    for( auto _ : state)
    {
        auto value = forwardList.max_size();
        DoNotOptimize(value);
    }
    state.SetComplexityN(N);
}

BENCHMARK(smallForwardListMaxSize)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void smallForwardListClear(State& state)
{
    auto N = state.range(0);
    std::forward_list<Small> forwardList{};
    Small small{};

    for (int i = 0; i < N; i++) {
        small.randomize();
        forwardList.push_front(small);
    }
    for( auto _ : state)
    {
        forwardList.clear();
    }
    state.SetComplexityN(N);
}

BENCHMARK(smallForwardListClear)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void smallForwardListInsertAfter(State& state)
{
    auto N = state.range(0);
    std::forward_list<Small> forwardList{};
    Small small{};

    for (int i = 0; i < N; i++) {
        small.randomize();
        forwardList.push_front(small);
    }

    Small small2{};
    small2.randomize();

    auto beginIt = forwardList.begin();
    for( auto _ : state)
    {
        forwardList.insert_after(beginIt, small2);
    }
    state.SetComplexityN(N);
}

BENCHMARK(smallForwardListInsertAfter)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void smallForwardListEraseAfter(State& state)
{
    auto N = state.range(0);
    std::forward_list<Small> forwardList{};
    Small small{};

    for (int i = 0; i < N; i++) {
        small.randomize();
        forwardList.push_front(small);
    }

    for( auto _ : state)
    {
        if( !forwardList.empty() )
            forwardList.erase_after(forwardList.before_begin());
    }
    state.SetComplexityN(N);
}

BENCHMARK(smallForwardListEraseAfter)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void smallForwardListPushFront(State& state)
{
    Small small1{};
    small1.randomize();

    auto N = state.range(0);
    std::forward_list<Small> forwardList{};
    Small small{};

    for (int i = 0; i < N; i++) {
        small.randomize();
        forwardList.push_front(small);
    }

    for( auto _ : state)
    {
        forwardList.push_front(small1);
    }
    state.SetComplexityN(N);
}

BENCHMARK(smallForwardListPushFront)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void smallForwardListPopFront(State& state)
{
    auto N = state.range(0);
    std::forward_list<Small> forwardList{};
    Small small{};

    for (int i = 0; i < N; i++) {
        small.randomize();
        forwardList.push_front(small);
    }

    for( auto _ : state)
    {
        if(!forwardList.empty())
            forwardList.pop_front();
    }
    state.SetComplexityN(N);
}

BENCHMARK(smallForwardListPopFront)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();


void smallForwardListResize(State& state)
{
    auto N = state.range(0);
    std::forward_list<Small> forwardList{};
    Small small{};

    for (int i = 0; i < N; i++) {
        small.randomize();
        forwardList.push_front(small);
    }

    for( auto _ : state)
    {
        forwardList.resize(5);
    }
    state.SetComplexityN(N);
}

BENCHMARK(smallForwardListResize)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void smallForwardListSwap(State& state)
{
    auto N = state.range(0);
    std::forward_list<Small> forwardList{};
    std::forward_list<Small> forwardList2{};
    Small small{};

    for (int i = 0; i < N; i++) {
        small.randomize();
        forwardList.push_front(small);
        small.randomize();
        forwardList2.push_front(small);
    }

    for( auto _ : state)
    {
        forwardList.swap(forwardList2);
    }
    state.SetComplexityN(N);
}

BENCHMARK(smallForwardListSwap)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();


void smallForwardListMerge(State& state)
{
    auto N = state.range(0);
    std::forward_list<Small> forwardList{};
    std::forward_list<Small> forwardList2{};
    Small small{};

    for (int i = 0; i < N; i++) {
        small.randomize();
        forwardList.push_front(small);
        small.randomize();
        forwardList2.push_front(small);
    }

    for( auto _ : state)
    {
        forwardList.merge(forwardList2);
    }
    state.SetComplexityN(N);
}

BENCHMARK(smallForwardListMerge)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();


void smallForwardListSpliceAfter(State& state)
{
    auto N = state.range();
    Small small{}, small2{};
    Small small1{}, small3{};

    small.randomize();
    small1.randomize();
    small2.randomize();
    small3.randomize();

    std::forward_list<Small> firstForwardList{small, small2};
    std::forward_list<Small> s2{small1, small3};


    for( auto _ : state)
    {
        firstForwardList.splice_after(firstForwardList.cbegin(), s2, s2.cbegin(), s2.cend());
    }
    state.SetComplexityN(N);
}

BENCHMARK(smallForwardListSpliceAfter)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();


void smallForwardListRemove(State& state)
{
    auto N = state.range(0);
    std::forward_list<Small> forwardList{};
    Small small{};

    for (int i = 0; i < N; i++) {
        small.randomize();
        forwardList.push_front(small);
    }

    for( auto _ : state)
    {
        if(!forwardList.empty())
            forwardList.remove(small);
    }
    state.SetComplexityN(N);
}

BENCHMARK(smallForwardListRemove)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();


void smallForwardListRemoveIf(State& state)
{
    auto N = state.range(0);
    Small small{'a'};
    Small small1{'g'};

    std::forward_list<Small> firstForwardList{small, small1};

    for( auto _ : state)
    {
        firstForwardList.remove_if([](Small n)
        {
            Small x{'g'};
            return n < x;
        });
    }
    state.SetComplexityN(N);
}

BENCHMARK(smallForwardListRemoveIf)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();


void smallForwardListReverse(State& state)
{
    auto N = state.range(0);
    std::forward_list<Small> forwardList{};

    Small small{};
    Small small2{};

    for (int i = 0; i < N; i++) {
        small.randomize();
        forwardList.push_front(small);
        small2.randomize();
        forwardList.push_front(small2);
    }


    for( auto _ : state)
    {
        forwardList.reverse();
    }
    state.SetComplexityN(N);
}

BENCHMARK(smallForwardListReverse)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void smallForwardListUnique(State& state)
{
    auto N = state.range(0);

    Small small{'a'};
    Small small1{'a'};


    std::forward_list<Small> firstForwardList{small, small1};


    for( auto _ : state)
    {
        firstForwardList.unique();
    }
    state.SetComplexityN(N);
}

BENCHMARK(smallForwardListUnique)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();

void smallForwardListSort(State& state)
{
    auto N = state.range(0);
    std::forward_list<Small> forwardList{};

    Small small{};
    Small small2{};

    for (int i = 0; i < N; i++) {
        small.randomize();
        forwardList.push_front(small);
        small2.randomize();
        forwardList.push_front(small2);
    }


    for( auto _ : state)
    {
        forwardList.sort();
    }
    state.SetComplexityN(N);
}

BENCHMARK(smallForwardListSort)->RangeMultiplier(2)->Range(1,1<<18)->Complexity();