#ifndef UT_GEODE_CAKE_H
#define UT_GEODE_CAKE_H

#include <string>

#include <gtest/gtest.h>

#include "../src/geode_cake.h"

class TestGeodeCake : public ::testing::Test {
public:
    GeodeCake testCake = GeodeCake(45, 50);
    GeodeCake testCake2 = GeodeCake(45, 50);
    GeodeCake testCake3 = GeodeCake(45, 50);
};

TEST_F(TestGeodeCake, test_geode_cake_get_price) {
    int result = 45;

    ASSERT_EQ(testCake.get_price(), result);
}

TEST_F(TestGeodeCake, test_geode_cake_get_sweet) {
    int result = 50;

    ASSERT_EQ(testCake.get_sweet(), result);
}

TEST_F(TestGeodeCake, test_geode_cake_get_total) {
    int result = 3;

    ASSERT_EQ(Cake::get_total(), result);
}

TEST_F(TestGeodeCake, test_geode_cake_to_string) {
    std::string result = "| GeodeCake            |         45 |         50 |";

    ASSERT_EQ(testCake.to_string(), result);
}

#endif
