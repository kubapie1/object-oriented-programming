#include "TestIncludes.h"

// TODO: ...
#include <vector>
#include <list>
#include <queue>
#include <deque>

TEST(VectorInt, CreateInitialized) {

    std::vector<int> vector{ 1, 2, 3};

    ASSERT_EQ(3u, vector.size());
    EXPECT_EQ(1, vector[0]);
    EXPECT_EQ(2, vector[1]);
    EXPECT_EQ(3, vector[2]);
}

TEST(VectorDouble, CreateEmptyAndAddValuesAtTheEnd) {

    // TODO: ...
    std::vector<double> vector;

    ASSERT_EQ(0u, vector.size());
    ASSERT_TRUE(vector.empty());

    vector.push_back(11);
    vector.push_back(13);
    vector.push_back(17);

    ASSERT_EQ(3u, vector.size());
    EXPECT_DOUBLE_EQ(11, vector[0]);
    EXPECT_DOUBLE_EQ(13, vector[1]);
    EXPECT_DOUBLE_EQ(17, vector[2]);
}

TEST(VectorFloat, CreateUsingInitializerList) {

    std::initializer_list<float> initializerList = { 10, 20, 30};
    std::vector<float> vector {initializerList};

    ASSERT_EQ(3u, vector.size());
    EXPECT_FLOAT_EQ(10, vector[0]);
    EXPECT_FLOAT_EQ(20, vector[1]);
    EXPECT_FLOAT_EQ(30, vector[2]);
}

TEST(VectorInt, SizeShouldBeLessThanOrEqualToCapacity) {

    // TODO: ...
    int length = 3;
    std::vector<int> vector;
    vector.reserve(length);
    for( int i = 0; i < length; i++)
    {
        vector.push_back(i+1);
    }

    ASSERT_EQ(3u, vector.size());
    EXPECT_FLOAT_EQ(1, vector[0]);
    EXPECT_FLOAT_EQ(2, vector[1]);
    EXPECT_FLOAT_EQ(3, vector[2]);
    EXPECT_EQ(vector.capacity(), vector.size());

    vector.reserve(4);
    vector.insert(vector.begin(), 4);

    ASSERT_EQ(4u, vector.size());
    EXPECT_FLOAT_EQ(4, vector[0]);
    EXPECT_FLOAT_EQ(1, vector[1]);
    EXPECT_FLOAT_EQ(2, vector[2]);
    EXPECT_FLOAT_EQ(3, vector[3]);
    EXPECT_GE(vector.capacity(), vector.size());

    // TODO: ...

    ASSERT_EQ(4u, vector.size());
    EXPECT_EQ(vector.capacity(), vector.size());
}

TEST(VectorFloat, CopyToOtherVectorUsingAssign) {

    // TODO: ...
    std::vector<float> input = {1,2,3};
    std::vector<float> output;

    ASSERT_EQ(3u, input.size());
    EXPECT_EQ(1, input[0]);
    EXPECT_EQ(2, input[1]);
    EXPECT_EQ(3, input[2]);

    ASSERT_TRUE(output.empty());

    // TODO: ...
    output.assign( input.begin() + 1, input.end());



    ASSERT_EQ(2u, output.size());
    EXPECT_EQ(2, output[0]);
    EXPECT_EQ(3, output[1]);

    ASSERT_EQ(3u, input.size());
    EXPECT_EQ(1, input[0]);
    EXPECT_EQ(2, input[1]);
    EXPECT_EQ(3, input[2]);
}

TEST(VectorFloat, EraseFrontValue) {

    // TODO: ...
    std::vector<float> vector = {1, 2, 3};

    ASSERT_EQ(3u, vector.size());
    EXPECT_FLOAT_EQ(1, vector[0]);
    EXPECT_FLOAT_EQ(2, vector[1]);
    EXPECT_FLOAT_EQ(3, vector[2]);

    // TODO: ...
    vector.erase(vector.begin());

    ASSERT_EQ(2u, vector.size());
    EXPECT_FLOAT_EQ(2, vector[0]);
    EXPECT_FLOAT_EQ(3, vector[1]);
}

TEST(VectorVectorVectorFloat, ThreeDimensionalVector) {

    using namespace std;
    // TODO: ...
    //vector<vector<vector<float> > > vect (2,vector<vector<float> >(2,vector <float>(2,0)));
    vector<vector<vector<float>>> vect;
    int howMany = 1;
    for( int i = 0; i < 2; i++ )
    {
        vector<vector<float>> vec2d;
        vect.push_back(vec2d);
        for( int j = 0; j < 2; j++ )
        {
            vector<float> vec1d;
            vect[i].push_back(vec1d);
            for( int k = 0; k < 2; k++)
                vect[i][j].push_back(howMany++);
        }
    }

    ASSERT_EQ(2u, vect.size());
    ASSERT_EQ(2u, vect[0].size());
    ASSERT_EQ(2u, vect[1].size());
    ASSERT_EQ(2u, vect[0][0].size());
    ASSERT_EQ(2u, vect[0][1].size());
    ASSERT_EQ(2u, vect[1][0].size());
    ASSERT_EQ(2u, vect[1][1].size());


    EXPECT_FLOAT_EQ(1, vect[0][0][0]);
    EXPECT_FLOAT_EQ(2, vect[0][0][1]);
    EXPECT_FLOAT_EQ(3, vect[0][1][0]);
    EXPECT_FLOAT_EQ(4, vect[0][1][1]);
    EXPECT_FLOAT_EQ(5, vect[1][0][0]);
    EXPECT_FLOAT_EQ(6, vect[1][0][1]);
    EXPECT_FLOAT_EQ(7, vect[1][1][0]);
    EXPECT_FLOAT_EQ(8, vect[1][1][1]);
}



TEST(ArrayInt, FillWithTheSameValue) {

    // TODO: ...
    std::array<int, 1000> array = { 0 };

    for (auto i = 0u; i < 1000; i++) {
        ASSERT_EQ(0, array[i]);
    }

    for (auto i = 0u; i < 1000; i++) {
        array[i] = 7;
    }

    for (auto i = 0u; i < 1000; i++) {
        ASSERT_EQ(7, array[i]);
    }
}

TEST(ArrayInt, SizeDefinedAtCompileTime) {

    // TODO: ...
    std::array<int, 4> array = {1, 2, 3, 4};

    static_assert(array.size() == 4, "Compilation error: wrong array size");

    ASSERT_EQ(1u, array[0]);
    ASSERT_EQ(2u, array[1]);
    ASSERT_EQ(3u, array[2]);
    ASSERT_EQ(4u, array[3]);
}

TEST(ArrayInt, Sort) {

    // TODO: ...
    std::array<int, 5> array = {5, 3, 4, 1, 2};
    EXPECT_EQ(5, array[0]);
    EXPECT_EQ(3, array[1]);
    EXPECT_EQ(4, array[2]);
    EXPECT_EQ(1, array[3]);
    EXPECT_EQ(2, array[4]);

    // TODO: ...
    std::sort(array.begin(), array.end());
    EXPECT_EQ(1, array[0]);
    EXPECT_EQ(2, array[1]);
    EXPECT_EQ(3, array[2]);
    EXPECT_EQ(4, array[3]);
    EXPECT_EQ(5, array[4]);
}

TEST(ArrayChar, CreateCopy) {

    // TODO: ...
    std::array<char, 5> arrayIn = {'a', 'b', 'c', 'd','\0' };
    std::array<char, 5> arrayOut;

    ASSERT_EQ(5u, arrayIn.size());
    ASSERT_EQ('a', arrayIn[0]);
    ASSERT_EQ('b', arrayIn[1]);
    ASSERT_EQ('c', arrayIn[2]);
    ASSERT_EQ('d', arrayIn[3]);
    ASSERT_EQ('\0', arrayIn[4]);
    EXPECT_STREQ("abcd", arrayIn.data());

    // TODO: ...
    arrayOut = arrayIn;

    ASSERT_EQ(5u, arrayIn.size());
    EXPECT_STREQ("abcd", arrayIn.data());
    ASSERT_EQ(5u, arrayOut.size());
    EXPECT_STREQ("abcd", arrayOut.data());
}

TEST(ListFloat, Sort) {

    // TODO: ...
    std::list<float> list{};
    for (int i = 0; i < 1000; i++) {
        list.push_back(rand());
    }

    ASSERT_EQ(1000, list.size());
    EXPECT_FALSE(std::is_sorted(list.begin(), list.end()));

    // TODO: ...
    list.sort();
    ASSERT_EQ(1000, list.size());
    EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(ListInt, MergeSortedLists) {

    // TODO: ...
    std::list<int> a{1, 3, 5};
    std::list<int> b{2, 4, 6};

    auto iter = a.begin();
    EXPECT_EQ(1, *(iter++));
    EXPECT_EQ(3, *(iter++));
    EXPECT_EQ(5, *(iter++));
    EXPECT_EQ(a.end(), iter);
    iter = b.begin();
    EXPECT_EQ(2, *(iter++));
    EXPECT_EQ(4, *(iter++));
    EXPECT_EQ(6, *(iter++));
    EXPECT_EQ(b.end(), iter);

    // TODO: ...
    a.sort();
    b.sort();
    a.merge(b);

    EXPECT_EQ(0, b.size());
    EXPECT_EQ(6, a.size());
    iter = a.begin();
    EXPECT_EQ(1, *(iter++));
    EXPECT_EQ(2, *(iter++));
    EXPECT_EQ(3, *(iter++));
    EXPECT_EQ(4, *(iter++));
    EXPECT_EQ(5, *(iter++));
    EXPECT_EQ(6, *(iter++));
    EXPECT_EQ(a.end(), iter);
}

TEST(ForwardListFloat, InsertElementAfterIndex) {

    // TODO: ...
    std::list<float> forwardList {1, 2, 3, 4};
    auto iter = forwardList.begin();
    EXPECT_EQ(1, *(iter++));
    EXPECT_EQ(2, *(iter++));
    EXPECT_EQ(3, *(iter++));
    EXPECT_EQ(4, *(iter++));
    EXPECT_EQ(forwardList.end(), iter);

    // TODO: ...

    iter = forwardList.begin();
    *(iter++);
    *(iter++);
    forwardList.insert(iter, 10);

    iter = forwardList.begin();
    EXPECT_EQ(1, *(iter++));
    EXPECT_EQ(2, *(iter++));
    EXPECT_EQ(10, *(iter++));
    EXPECT_EQ(3, *(iter++));
    EXPECT_EQ(4, *(iter++));
    EXPECT_EQ(forwardList.end(), iter);
}

TEST(DequeInt, RemoveFirstElement) {

    // TODO: ...
    std::deque<int> deque = {1, 2, 3};

    ASSERT_EQ(3u, deque.size());
    EXPECT_FLOAT_EQ(1, deque[0]);
    EXPECT_FLOAT_EQ(2, deque[1]);
    EXPECT_FLOAT_EQ(3, deque[2]);

    // TODO: ...
    deque.pop_front();
    ASSERT_EQ(2u, deque.size());
    EXPECT_FLOAT_EQ(2, deque[0]);
    EXPECT_FLOAT_EQ(3, deque[1]);
}
/*
TEST(StackInt, PushAndPop) {

    // TODO: ...

    EXPECT_TRUE(stack.empty());

    // TODO: ...

    ASSERT_EQ(2u, stack.size());
    EXPECT_EQ(2, stack.top());

    // TODO: ...

    ASSERT_EQ(1u, stack.size());
    EXPECT_EQ(1, stack.top());

    // TODO: ...

    ASSERT_EQ(0u, stack.size());
}

TEST(PriorityQueueChar, PushAndPop) {

    // TODO: ...

    ASSERT_TRUE(priority_queue.empty());

    // TODO: ...

    ASSERT_EQ(2u, priority_queue.size());
    EXPECT_EQ(3, priority_queue.top());

    // TODO: ...

    ASSERT_EQ(4u, priority_queue.size());
    EXPECT_EQ(4, priority_queue.top());

    // TODO: ...

    ASSERT_EQ(3u, priority_queue.size());
    EXPECT_EQ(3, priority_queue.top());

    // TODO: ...

    ASSERT_EQ(2u, priority_queue.size());
    EXPECT_EQ(2, priority_queue.top());

    // TODO: ...

    ASSERT_EQ(1u, priority_queue.size());
    EXPECT_EQ(1, priority_queue.top());

    // TODO: ...

    ASSERT_TRUE(priority_queue.empty());
}
*/