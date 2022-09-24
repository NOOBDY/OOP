#include <gtest/gtest.h>

#include "HelloWorld.h"

TEST(HELLOWORLD, HelloWorld) {
    std::string output = HelloWorld();
    std::string target = "Hello World\n";

    ASSERT_EQ(output, target);
}