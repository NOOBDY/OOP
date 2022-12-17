#ifndef UT_ALGORITHM_H
#define UT_ALGORITHM_H

#include <memory>

#include <gtest/gtest.h>

#include "../src/sour.h"
#include "../src/tequila.h"

#include "../src/algorithm.h"

template <typename T>
using Sp = std::shared_ptr<T>;

class TestAlgorithm : public ::testing::Test {
public:
    void init() {
        drinks.push_back(d1.get());
        drinks.push_back(d2.get());
        drinks.push_back(d3.get());
    }

    std::vector<Alcohol *> drinks;
    Sp<Sour> d1 = std::make_shared<Sour>("testSour1", 40, 0.3);
    Sp<Tequila> d2 = std::make_shared<Tequila>("testTequila1", 40, 0.6);
    Sp<Sour> d3 = std::make_shared<Sour>("testSour2", 60, 0.1);
    Sp<Tequila> d4 = std::make_shared<Tequila>("testTequila2", 60, 0.3);
};

TEST_F(TestAlgorithm, test_sort_content) {
    std::vector<double> sorted_content{0.1, 0.3, 0.3, 0.6};

    init();

    drinks.push_back(d4.get());

    sort_alcohol_by_content(drinks);

    for (int i = 0; i < drinks.size(); ++i)
        ASSERT_NEAR(drinks[i]->get_alcohol_content(), sorted_content[i], 0.001);
}

TEST_F(TestAlgorithm, test_sort_name) {
    std::vector<std::string> sorted_name{
        "testSour1",
        "testSour2",
        "testTequila1",
    };

    init();

    sort_alcohol_by_name(drinks);

    for (int i = 0; i < drinks.size(); ++i)
        ASSERT_EQ(drinks[i]->get_name(), sorted_name[i]);
}

TEST_F(TestAlgorithm, test_max_content) {
    init();

    ASSERT_NEAR(get_greatest_content_of_alcohol(drinks)->get_alcohol_content(),
                0.6, 0.001);
}

TEST_F(TestAlgorithm, test_min_content) {
    init();

    ASSERT_NEAR(get_smallest_content_of_alcohol(drinks)->get_alcohol_content(),
                0.1, 0.001);
}

#endif