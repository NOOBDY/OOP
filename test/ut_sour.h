#ifndef UT_SOUR_H
#define UT_SOUR_H

#include <gtest/gtest.h>

#include "../src/sour.h"

class TestSour : public ::testing::Test {
public:
    Sour normalSour = Sour("test", 10, 0.5);
};

TEST_F(TestSour, test_normal_sour_name) {
    ASSERT_EQ(normalSour.get_name(), std::string("test"));
}

TEST_F(TestSour, test_normal_sour_price) {
    ASSERT_EQ(normalSour.get_price(), 10);
}

TEST_F(TestSour, test_normal_sour_content) {
    ASSERT_NEAR(normalSour.get_alcohol_content(), 0.5, 0.01);
}

TEST_F(TestSour, test_dilute) {
    normalSour.dilute();
    ASSERT_NEAR(normalSour.get_alcohol_content(), 0.35, 0.01);
}

TEST_F(TestSour, test_join) {
    Sour second("second", 40, 0.3);

    Sour abomination = normalSour + second;

    ASSERT_EQ(abomination.get_name(), "test");
    ASSERT_EQ(abomination.get_alcohol_content(), 0.4);
}

TEST_F(TestSour, test_equal) {
    Sour second("test", 10, 0.5);

    ASSERT_TRUE(normalSour == second);
}

#endif