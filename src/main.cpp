#include "Search_engine_cmake.h"

int main(int argc, char** argv)
{
    launch();
    ConverterJSON converter;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
};