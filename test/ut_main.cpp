#include <gtest/gtest.h>

#include "HelloWorld.hpp"

TEST(HELLO_WORLD, HelloWorld) {
    std::string output = HelloWorld();
    std::string target = "Hello World\n";

    ASSERT_EQ(output, target);
}