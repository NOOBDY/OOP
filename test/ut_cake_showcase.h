#ifndef UT_CAKE_SHOWCASE_H
#define UT_CAKE_SHOWCASE_H

#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>

#include <gtest/gtest.h>

#include "../src/chocolate_cake.h"
#include "../src/honey_cake.h"
#include "../src/geode_cake.h"

#include "../src/cake_showcase.h"

class TestCakeShowcase : public ::testing::Test {
public:
    std::shared_ptr<Cake> testChocolateCake =
        std::shared_ptr<ChocolateCake>(std::make_shared<ChocolateCake>(20, 30));
    std::shared_ptr<Cake> testHoneyCake =
        std::shared_ptr<HoneyCake>(std::make_shared<HoneyCake>(40, 20));
    std::shared_ptr<Cake> testGeodeCake =
        std::shared_ptr<GeodeCake>(std::make_shared<GeodeCake>(50, 10));

    std::vector<Cake *> m_Cakes = std::vector<Cake *>({
        testChocolateCake.get(),
        testHoneyCake.get(),
        testGeodeCake.get(),
    });

    std::shared_ptr<CakeShowcase<Cake>> m_TestCakeShowcase =
        std::make_shared<CakeShowcase<Cake>>(m_Cakes.size(), m_Cakes.data());
};

TEST_F(TestCakeShowcase, test_calc_total_price) {
    int result = 110;

    ASSERT_EQ(m_TestCakeShowcase->calc_total_price(), result);
}

TEST_F(TestCakeShowcase, test_calc_total_sweet) {
    int result = 60;

    ASSERT_EQ(m_TestCakeShowcase->calc_total_sweet(), result);
}

TEST_F(TestCakeShowcase, test_to_string) {
    std::string result = "| CakeName             | Price      | Sweet      |\n"
                         "| -------------------- | ---------- | ---------- |\n"
                         "| ChocolateCake        |         20 |         30 |\n"
                         "| HoneyCake            |         40 |         20 |\n"
                         "| GeodeCake            |         50 |         10 |\n"
                         "| -------------------- | ---------- | ---------- |";

    ASSERT_EQ(m_TestCakeShowcase->to_string(), result);
}

TEST_F(TestCakeShowcase, test_normal_index_operator) {
    int result = 40;

    ASSERT_EQ((*m_TestCakeShowcase)[1]->get_price(), result);
}

TEST_F(TestCakeShowcase, test_index_out_of_range) {
    ASSERT_THROW((*m_TestCakeShowcase)[4]->get_price(), std::out_of_range);
}

TEST_F(TestCakeShowcase, test_cake_total) {
    int result = 3;

    ASSERT_EQ(Cake::get_total(), result);
}

TEST_F(TestCakeShowcase, test_chocolate_cake_total) {
    int result = 1;

    ASSERT_EQ(ChocolateCake::get_count(), result);
}

#endif
