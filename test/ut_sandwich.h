#ifndef UT_SANDWICH_H
#define UT_SANDWICH_H

#include <memory>

#include <gtest/gtest.h>

#include "../src/sandwich.h"
#include "../src/beef_sandwich.h"
#include "../src/sweet_sandwich.h"

class TestSandwich : public ::testing::Test {
public:
    std::shared_ptr<Sandwich> testSandwich1 =
        std::make_shared<BeefSandwich>(10, 1);
    std::shared_ptr<Sandwich> testSandwich2 =
        std::make_shared<BeefSandwich>(30, 3);
    std::shared_ptr<Sandwich> testSandwich3 =
        std::make_shared<SweetSandwich>(20, 4);
};

TEST_F(TestSandwich, test_get_price) {
    int target = 10;

    ASSERT_EQ(testSandwich1->get_price(), target);
}

TEST_F(TestSandwich, test_get_id) {
    int target = 4;

    ASSERT_EQ(testSandwich3->get_ID(), target);
}

TEST_F(TestSandwich, test_sandwich_static_methods) {
    int target = 3;

    ASSERT_TRUE(Sandwich::record_has_specific_id(1));
    ASSERT_EQ(Sandwich::get_size_of_record_container(), target);
}

TEST_F(TestSandwich, test_beef_sandwich_static_methods) {
    int target = 2;

    ASSERT_FALSE(BeefSandwich::record_has_specific_id(4));
    ASSERT_EQ(BeefSandwich::get_size_of_record_container(), target);
}

TEST_F(TestSandwich, test_sweet_sandwich_static_methods) {
    int target = 1;

    ASSERT_FALSE(SweetSandwich::record_has_specific_id(1));
    ASSERT_EQ(SweetSandwich::get_size_of_record_container(), target);
}

#endif
