#ifndef UT_HONEY_CAKE_H
#define UT_HONEY_CAKE_H

#include <string>

#include <gtest/gtest.h>

#include "../src/honey_cake.h"

class TestHoneyCake : public ::testing::Test {
public:
    HoneyCake testCake = HoneyCake(45, 50);
    HoneyCake testCake2 = HoneyCake(45, 50);
    HoneyCake testCake3 = HoneyCake(45, 50);
};

TEST_F(TestHoneyCake, test_honey_cake_get_price) {
    int result = 45;

    ASSERT_EQ(testCake.get_price(), result);
}

TEST_F(TestHoneyCake, test_honey_cake_get_sweet) {
    int result = 50;

    ASSERT_EQ(testCake.get_sweet(), result);
}

TEST_F(TestHoneyCake, test_honey_cake_get_total) {
    int result = 3;

    ASSERT_EQ(Cake::get_total(), result);
}

TEST_F(TestHoneyCake, test_honey_cake_to_string) {
    std::string result = "| HoneyCake            |         45 |         50 |\n";

    ASSERT_EQ(testCake.to_string(), result);
}

#endif
