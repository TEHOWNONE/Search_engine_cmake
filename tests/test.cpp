#include "search_engine.h"

TEST(testfoo, testfoo)
{
    ::testing::InitGoogleTest();
    int ret = RUN_ALL_TESTS();
    EXPECT_EQ(1, 1);
}