#include "TestIncludes.h"

#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include "Large.h"

TEST(LargeTest, SizeIsOneMegabyte) {

    EXPECT_EQ(1024u*1024u, sizeof(Large));
}

TEST(LargeTest, CreateObject) {

    Large large{};
}

TEST(LargeTest, HasLessThenOperator) {

    Large a{};
    Large b{};

    a < b;
}

TEST(LargeTest, HasEqualityOperator) {

    Large a{};
    Large b{};

    a == b;
}

TEST(LargeTest, CanBeHashed) {

    Large large{};
    std::hash<Large> hash;

    hash(large);
}

TEST(LargeTest, Collections) {

    Large large{};

    std::vector<Large> vector{};
    vector.push_back(large);

    std::array<Large, 1> array{};
    array[0] = large;

    std::deque<Large> deque{};
    deque.push_back(large);

    std::list<Large> list{};
    list.push_back(large);

    std::forward_list<Large> forward_list{};
    forward_list.push_front(large);

    std::map<Large, bool> map{};
    map[large] = true;

    std::set<Large> set{};
    set.insert(large);

    std::unordered_map<Large, bool> unordered_map{};
    unordered_map[large] = true;

    std::unordered_set<Large> unordered_set{};
    unordered_set.insert(large);
}

TEST(LargeTest, Randomize) {

    Large large{};
    large.randomize();

    auto count = 0u;

    for (double i : large.data) {

        ASSERT_LE(0.0, i);
        ASSERT_GE(1.0, i);

        if (i != 0.0)
            ++count;
    }

    EXPECT_NE(0u, count) << "All elements were zero?";
}

TEST(LargeTest, Clear) {

    Large large{};
    large.randomize();
    large.clear();

    for (double i : large.data) {
        ASSERT_DOUBLE_EQ(0.0, i);
    }
}


// TODO: Add tests for your operators implementation!

TEST( LargeTest, LessThanOperator)
{
    Large l1 = { 1.0, 2.0, 3.0};
    Large l2 = {1.0, 2.0, 2.0};
    ASSERT_EQ(true, l2<l1);
}

TEST( LargeTest, EqualOperator)
{
    Large l1 = { 5.0, 2.0,3.0};
    Large l2 = { 5.0, 2.0,3.0, 5.0};

    ASSERT_EQ(false, l1 == l2);
}

TEST(LargeTest, HashOperator)
{
    std::unordered_set<Large> unorderedSet{};

    Large l1{};
    Large l2{};
    for (int i = 0; i < Large::SIZE; ++i)
    {
        l1.data[i] = i + 1.5;
        l2.data[i] = (double)i + 2.5;
    }

    unorderedSet.insert(l1);
    ASSERT_EQ(1u, unorderedSet.size());
    ASSERT_EQ(l1, *unorderedSet.cbegin());
    unorderedSet.insert(l2);
    ASSERT_EQ(2u, unorderedSet.size());
}