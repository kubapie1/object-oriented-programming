#include "Small.h"
#include "BenchIncludes.h"
#include <forward_list>

void smallForwardListFront(State& state)
{
    Small small{};
    small.randomize();
    std::forward_list<Small> forwardList{small};

    for( auto _ : state)
    {
        auto value = forwardList.front();
        DoNotOptimize(value);
    }
}

BENCHMARK(smallForwardListFront);

void smallForwardListEmpty(State& state)
{
    Small small{},small1{};
    small.randomize();
    small1.randomize();

    std::forward_list<Small> forwardList{small,small1};
    for( auto _ : state)
    {
        auto value = forwardList.empty();
        DoNotOptimize(value);
    }
}

BENCHMARK(smallForwardListEmpty);

void smallForwardListMaxSize(State& state)
{
    std::forward_list<Small> forwardList{};
    for( auto _ : state)
    {
        auto value = forwardList.max_size();
        DoNotOptimize(value);
    }
}

BENCHMARK(smallForwardListMaxSize);

void smallForwardListClear(State& state)
{
    Small small{},small1{};
    small.randomize();
    small1.randomize();

    std::forward_list<Small> forwardList{small,small1};
    for( auto _ : state)
    {
        forwardList.clear();
    }
}

BENCHMARK(smallForwardListClear);

void smallForwardListInsertAfter(State& state)
{
    Small small{};
    Small small1{};
    Small small2{};
    small.randomize();
    small1.randomize();
    small2.randomize();

    std::forward_list<Small> forwardList{small,small1};
    auto beginIt = forwardList.begin();
    for( auto _ : state)
    {
        forwardList.insert_after(beginIt, small2 );
    }
}

BENCHMARK(smallForwardListInsertAfter);

void smallForwardListEraseAfter(State& state)
{
    Small small{};
    Small small1{};
    small.randomize();
    small.randomize();


    std::forward_list<Small> forwardList{small, small1};

    for( auto _ : state)
    {
        if( !forwardList.empty() )
            forwardList.erase_after(forwardList.before_begin());
    }
}

BENCHMARK(smallForwardListEraseAfter);

void smallForwardListPushFront(State& state)
{
    Small small{};
    Small small1{};

    small.randomize();
    small1.randomize();


    std::forward_list<Small> forwardList{small};

    for( auto _ : state)
    {
        forwardList.push_front(small1);
    }
}

BENCHMARK(smallForwardListPushFront);

void smallForwardListPopFront(State& state)
{
    Small small{};
    Small small1{};

    small.randomize();
    small1.randomize();


    std::forward_list<Small> forwardList{small, small1};

    for( auto _ : state)
    {
        if(!forwardList.empty())
            forwardList.pop_front();
    }
}

BENCHMARK(smallForwardListPopFront);


void smallForwardListResize(State& state)
{
    Small small{};
    Small small1{};

    small.randomize();
    small1.randomize();


    std::forward_list<Small> forwardList{small, small1};

    for( auto _ : state)
    {
        forwardList.resize(1);
    }
}

BENCHMARK(smallForwardListResize);

void smallForwardListSwap(State& state)
{
    Small small{};
    Small small1{};

    small.randomize();
    small1.randomize();

    std::forward_list<Small> firstForwardList{small};
    std::forward_list<Small> secondForwardList{small1};

    for( auto _ : state)
    {
        firstForwardList.swap(secondForwardList);
    }
}

BENCHMARK(smallForwardListSwap);


void smallForwardListMerge(State& state)
{
    Small small{};
    Small small1{};

    small.randomize();
    small1.randomize();

    std::forward_list<Small> firstForwardList{small};
    std::forward_list<Small> secondForwardList{small1};

    for( auto _ : state)
    {
        firstForwardList.merge(secondForwardList);
    }

}

BENCHMARK(smallForwardListMerge);


void smallForwardListSpliceAfter(State& state)
{
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
}

BENCHMARK(smallForwardListSpliceAfter);


void smallForwardListRemove(State& state)
{
    Small small{};


    small.randomize();


    std::forward_list<Small> firstForwardList{small};


    for( auto _ : state)
    {
        if(!firstForwardList.empty())
            firstForwardList.remove(small);
    }
}

BENCHMARK(smallForwardListRemove);


void smallForwardListRemoveIf(State& state)
{
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
}

BENCHMARK(smallForwardListRemoveIf);


void smallForwardListReverse(State& state)
{
    Small small{};
    Small small1{};

    small.randomize();
    small1.randomize();

    std::forward_list<Small> firstForwardList{small, small1};


    for( auto _ : state)
    {
        firstForwardList.reverse();
    }
}

BENCHMARK(smallForwardListReverse);

void smallForwardListUnique(State& state)
{
    Small small{'a'};
    Small small1{'a'};


    std::forward_list<Small> firstForwardList{small, small1};


    for( auto _ : state)
    {
        firstForwardList.unique();
    }
}

BENCHMARK(smallForwardListUnique);

void smallForwardListSort(State& state)
{
    Small small{};
    Small small1{};

    small.randomize();
    small1.randomize();

    std::forward_list<Small> firstForwardList{small, small1};


    for( auto _ : state)
    {
        firstForwardList.sort();
    }
}

BENCHMARK(smallForwardListSort);