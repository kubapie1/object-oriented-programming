#include "Small.h"
#include "BenchIncludes.h"
#include <set>

void SmallSetEmpty(State& state)
{

    Small small{};
    small.randomize();

    std::set<Small> mySet{small};
    for(auto _ : state)
    {
        auto value = mySet.empty();
    }
}

BENCHMARK(SmallSetEmpty);

void SmallSetSize(State& state)
{
    Small small{};
    small.randomize();
    std::set<Small> mySet{small};

    for(auto _ : state)
    {
        auto value = mySet.size();
    }
}

BENCHMARK(SmallSetSize);

void SmallSetMaxSize(State& state)
{
    Small small{};
    small.randomize();
    std::set<Small> mySet{small};

    for(auto _ : state)
    {
        auto value = mySet.max_size();
    }
}

BENCHMARK(SmallSetMaxSize);

void SmallSetClear(State& state)
{
    Small small{};
    small.randomize();
    std::set<Small> mySet{small};

    for(auto _ : state)
    {
        mySet.clear();
    }
}

BENCHMARK(SmallSetClear);

void SmallSetInsert(State& state)
{
    Small small{};
    small.randomize();
    std::set<Small> mySet{};

    for(auto _ : state)
    {
        auto value = mySet.insert(small);
    }
}

BENCHMARK(SmallSetInsert);

void SmallSetErase(State& state)
{
    Small small{};
    small.randomize();
    std::set<Small> mySet{small};

        for (auto _ : state)
        {
            if(!mySet.empty())
                mySet.erase(mySet.cbegin());
            auto v = 1;
        }
}

BENCHMARK(SmallSetErase);

void SmallSetSwap(State& state)
{
    Small small{};
    small.randomize();

    Small small1{};
    small1.randomize();

    std::set<Small> mySet{small};
    std::set<Small> mySet2{small1};

    for (auto _ : state)
    {
        mySet.swap(mySet2);
    }
}

BENCHMARK(SmallSetSwap);

void SmallSetCount(State& state)
{
    Small small{};
    small.randomize();

    std::set<Small> mySet{small};


    for (auto _ : state)
    {
        mySet.count(small);
    }
}

BENCHMARK(SmallSetCount);


void SmallSetFind(State& state)
{
    Small small{};
    small.randomize();

    std::set<Small> mySet{small};


    for (auto _ : state)
    {
        auto value = mySet.find(small);
    }
}

BENCHMARK(SmallSetFind);

void SmallSetEqualRange(State& state)
{
    Small small{};
    Small small1{};
    Small small2{};

    small.randomize();
    small1.randomize();
    small2.randomize();


    std::set<Small> mySet{small, small1, small2};


    for (auto _ : state)
    {
        auto value = mySet.equal_range(small1);
    }
}

BENCHMARK(SmallSetEqualRange);

void SmallSetLowerBound(State& state)
{
    Small small{};
    Small small1{};
    Small small2{};

    small.randomize();
    small1.randomize();
    small2.randomize();


    std::set<Small> mySet{small, small1, small2};


    for (auto _ : state)
    {
        auto value = mySet.lower_bound(small);
    }
}

BENCHMARK(SmallSetLowerBound);

void SmallSetUpperBound(State& state)
{
    Small small{};
    Small small1{};
    Small small2{};

    small.randomize();
    small1.randomize();
    small2.randomize();


    std::set<Small> mySet{small, small1, small2};


    for (auto _ : state)
    {
        auto value = mySet.upper_bound(small1);
    }
}

BENCHMARK(SmallSetUpperBound);
