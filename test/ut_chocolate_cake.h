#ifndef UT_CHOCOLATE_CAKE_H
#define UT_CHOCOLATE_CAKE_H

#include <string>

#include <gtest/gtest.h>

#include "../src/chocolate_cake.h"

class TestChocolateCake : public ::testing::Test {
public:
    ChocolateCake testCake = ChocolateCake(45, 50);
    ChocolateCake testCake2 = ChocolateCake(45, 50);
    ChocolateCake testCake3 = ChocolateCake(45, 50);
};

TEST_F(TestChocolateCake, test_chocolate_cake_get_price) {
    int result = 45;

    ASSERT_EQ(testCake.get_price(), result);
}

TEST_F(TestChocolateCake, test_chocolate_cake_get_sweet) {
    int result = 50;

    ASSERT_EQ(testCake.get_sweet(), result);
}

TEST_F(TestChocolateCake, test_chocolate_cake_get_total) {
    int result = 3;

    ASSERT_EQ(ChocolateCake::get_count(), result);
}

TEST_F(TestChocolateCake, test_chocolate_cake_to_string) {
    std::string result = "| ChocolateCake        |         45 |         50 |";

    ASSERT_EQ(testCake.to_string(), result);
}

#endif
