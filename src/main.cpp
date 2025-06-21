#include "search_engine.h"

int main(int argc, char** argv)
{
    launch();
    ConverterJSON converter;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
};