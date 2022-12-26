#ifndef UT_CAKE_SHOWCASE_H
#define UT_CAKE_SHOWCASE_H

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
    std::shared_ptr<CakeShowcase<Cake>> m_TestCakeShowcase;

    void init() {
        std::shared_ptr<Cake> testChocolateCake =
            std::shared_ptr<ChocolateCake>(
                std::make_shared<ChocolateCake>(20, 30));
        std::shared_ptr<Cake> testHoneyCake =
            std::shared_ptr<HoneyCake>(std::make_shared<HoneyCake>(40, 20));
        std::shared_ptr<Cake> testGeodeCake =
            std::shared_ptr<GeodeCake>(std::make_shared<GeodeCake>(50, 10));

        std::vector<Cake *> m_Cakes = std::vector<Cake *>({
            testChocolateCake.get(),
            testHoneyCake.get(),
            testGeodeCake.get(),
        });

        m_TestCakeShowcase = std::make_shared<CakeShowcase<Cake>>(
            m_Cakes.size(), m_Cakes.data());
    }
};

TEST_F(TestCakeShowcase, test_calc_total_price) {
    init();

    int result = 110;

    ASSERT_EQ(m_TestCakeShowcase->calc_total_price(), result);
}

TEST_F(TestCakeShowcase, test_calc_total_sweet) {
    init();

    int result = 60;

    ASSERT_EQ(m_TestCakeShowcase->calc_total_sweet(), result);
}

TEST_F(TestCakeShowcase, test_to_string) {
    init();
}

TEST_F(TestCakeShowcase, test_normal_index_operator) {
    init();

    int result = 40;

    ASSERT_EQ((*m_TestCakeShowcase)[1]->get_price(), result);
}

TEST_F(TestCakeShowcase, test_index_out_of_range) {
    init();

    ASSERT_THROW((*m_TestCakeShowcase)[4]->get_price(), std::out_of_range);
}

#endif
