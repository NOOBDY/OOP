#ifndef UT_ALCOHOL_H
#define UT_ALCOHOL_H

#include <iostream>
#include <vector>
#include <memory>

#include <gtest/gtest.h>

#include "sour.h"
#include "tequila.h"

TEST(Alcohol, test_polymorphism) {
    std::vector<std::shared_ptr<Alcohol>> drinks;

    drinks.push_back(std::make_shared<Sour>("testSour", 40, 0.3));
    drinks.push_back(std::make_shared<Tequila>("testTequila", 40, 0.6));

    for (auto &drink : drinks) {
        drink->dilute();
    }

    ASSERT_NEAR(drinks[0]->get_alcohol_content(), 0.09, 0.001);
    ASSERT_NEAR(drinks[1]->get_alcohol_content(), 0.03, 0.001);
}

TEST(Alcohol, test_invalid_alcohol) {
    ASSERT_THROW(Sour s("", -10, 10), std::string);
}

#endif