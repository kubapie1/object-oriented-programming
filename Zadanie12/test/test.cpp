#include "gtest/gtest.h"
#include "../src/Dummy.h"

TEST( Dummy, Add )
{
    auto dummy = Dummy{};
    EXPECT_EQ(10, dummy.add(5,5) );
}