#include <gtest/gtest.h>
#include "test_default.cpp"


using namespace std;

int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
