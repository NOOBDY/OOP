#ifndef UT_TEQUILA_H
#define UT_TEQUILA_H

#include <gtest/gtest.h>

#include "tequila.h"

class TestTequila : public ::testing::Test {
public:
    Tequila normalTequila = Tequila("test", 10, 0.5);
};

TEST_F(TestTequila, test_normal_sour_name) {
    ASSERT_EQ(normalTequila.get_name(), std::string("test"));
}

TEST_F(TestTequila, test_normal_sour_price) {
    ASSERT_EQ(normalTequila.get_price(), 10);
}

TEST_F(TestTequila, test_normal_sour_content) {
    ASSERT_NEAR(normalTequila.get_alcohol_content(), 0.5, 0.01);
}

TEST_F(TestTequila, test_dilute) {
    normalTequila.dilute();
    ASSERT_NEAR(normalTequila.get_alcohol_content(), 0.025, 0.01);
}

TEST_F(TestTequila, test_join) {
    Tequila second("second", 40, 0.3);

    Tequila abomination = normalTequila + second;

    ASSERT_EQ(abomination.get_name(), "test");
    ASSERT_EQ(abomination.get_alcohol_content(), 0.4);
}

TEST_F(TestTequila, test_equal) {
    Tequila second("test", 10, 0.5);

    ASSERT_TRUE(normalTequila == second);
}

#endif