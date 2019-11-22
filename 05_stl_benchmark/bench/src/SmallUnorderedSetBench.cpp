#include "Small.h"
#include "BenchIncludes.h"
#include <unordered_set>

void SmallUnorderedSetEmpty(State& state)
{

    Small small{};
    small.randomize();

    std::unordered_set<Small> mySet{small};
    for(auto _ : state)
    {
        auto value = mySet.empty();
    }
}

BENCHMARK(SmallUnorderedSetEmpty);

void SmallUnorderedSetSize(State& state)
{
    Small small{};
    small.randomize();
    std::unordered_set<Small> mySet{small};

    for(auto _ : state)
    {
        auto value = mySet.size();
    }
}

BENCHMARK(SmallUnorderedSetSize);

void SmallUnorderedSetMaxSize(State& state)
{
    Small small{};
    small.randomize();
    std::unordered_set<Small> mySet{small};

    for(auto _ : state)
    {
        auto value = mySet.max_size();
    }
}

BENCHMARK(SmallUnorderedSetMaxSize);

void SmallUnorderedSetClear(State& state)
{
    Small small{};
    small.randomize();
    std::unordered_set<Small> mySet{small};

    for(auto _ : state)
    {
        mySet.clear();
    }
}

BENCHMARK(SmallUnorderedSetClear);

void SmallUnorderedSetInsert(State& state)
{
    Small small{};
    small.randomize();
    std::unordered_set<Small> mySet{};

    for(auto _ : state)
    {
        auto value = mySet.insert(small);
    }
}

BENCHMARK(SmallUnorderedSetInsert);

void SmallUnorderedSetErase(State& state)
{
    Small small{};
    small.randomize();
    std::unordered_set<Small> mySet{small};

    for (auto _ : state)
    {
        if(!mySet.empty())
            mySet.erase(mySet.cbegin());
        auto v = 1;
    }
}

BENCHMARK(SmallUnorderedSetErase);

void SmallUnorderedSetSwap(State& state)
{
    Small small{};
    small.randomize();

    Small small1{};
    small1.randomize();

    std::unordered_set<Small> mySet{small};
    std::unordered_set<Small> mySet2{small1};

    for (auto _ : state)
    {
        mySet.swap(mySet2);
    }
}

BENCHMARK(SmallUnorderedSetSwap);

void SmallUnorderedSetCount(State& state)
{
    Small small{};
    small.randomize();

    std::unordered_set<Small> mySet{small};


    for (auto _ : state)
    {
        mySet.count(small);
    }
}

BENCHMARK(SmallUnorderedSetCount);


void SmallUnorderedSetFind(State& state)
{
    Small small{};
    small.randomize();

    std::unordered_set<Small> mySet{small};


    for (auto _ : state)
    {
        auto value = mySet.find(small);
    }
}

BENCHMARK(SmallUnorderedSetFind);

void SmallUnorderedSetEqualRange(State& state)
{
    Small small{};
    Small small1{};
    Small small2{};

    small.randomize();
    small1.randomize();
    small2.randomize();


    std::unordered_set<Small> mySet{small, small1, small2};


    for (auto _ : state)
    {
        auto value = mySet.equal_range(small1);
    }
}

BENCHMARK(SmallUnorderedSetEqualRange);

void SmallUnorderedSetRehash(State& state)
{
    Small small{};
    Small small1{};
    Small small2{};

    small.randomize();
    small1.randomize();
    small2.randomize();

    std::unordered_set<Small> mySet{small, small1, small2};

    for (auto _ : state)
    {
        mySet.rehash(4);
    }
}

BENCHMARK(SmallUnorderedSetRehash);

void SmallUnorderedSetReserve(State& state)
{
    Small small{};
    Small small1{};
    Small small2{};

    small.randomize();
    small1.randomize();
    small2.randomize();

    std::unordered_set<Small> mySet{small, small1, small2};

    for (auto _ : state)
    {
        mySet.reserve(30);
    }

}

BENCHMARK(SmallUnorderedSetReserve);
