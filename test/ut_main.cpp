#include <gtest/gtest.h>

#include "HelloWorld.hpp"

TEST(HELLO_WORLD, HelloWorld) {
    std::string output = HelloWorld();
    std::string target = "Hello World\n";

    ASSERT_EQ(output, target);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}