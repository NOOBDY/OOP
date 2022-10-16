#ifndef UT_DRINK_H
#define UT_DRINK_H

#include <gtest/gtest.h>

#include "../src/drink.h"

TEST(DRINK, constructor1) {
    ASSERT_THROW(Drink drink("cum", .8f), std::string);
}

TEST(DRINK, constructor2) {
    ASSERT_THROW(Drink drink("Pißwasser", 6.9f), std::string);
}

TEST(DRINK, get_name1) {
    Drink drink("Jesus Juice", 0.2f);

    std::string target = "Jesus Juice";

    ASSERT_EQ(drink.getName(), target);
}

TEST(DRINK, get_name2) {
    Drink drink;

    ASSERT_THROW(drink.getName(), std::string);
}

TEST(DRINK, get_sweetness_level1) {
    Drink drink("Kool Aid", 0.7f);

    ASSERT_NEAR(drink.getSweetnessLevel(), 0.7f, 0.001f);
}

TEST(DRINK, get_sweetness_level2) {
    Drink drink;

    ASSERT_THROW(drink.getSweetnessLevel(), std::string);
}

TEST(DRINK, add_topping1) {
    Drink drink("Olive Oil", 0.0f);

    ASSERT_NO_THROW(drink.addTopping("Spaghetti"));
}

TEST(DRINK, add_topping2) {
    Drink drink("Sex on the Beach", 0.4f);

    drink.addTopping("Umbrella");

    ASSERT_EQ(drink.getToppingCount(), 1);
}

TEST(DRINK, get_topping_by_index1) {
    Drink drink("Szechuan Sauce", 0.4f);

    drink.addTopping("Fries");
    drink.addTopping("Nugget");

    std::string target = "Nugget";

    ASSERT_EQ(drink.getToppingByIndex(1), target);
}

TEST(DRINK, get_topping_by_index2) {
    Drink drink;

    ASSERT_THROW(drink.getToppingByIndex(420), std::string);
}

TEST(DRINK, get_topping_count1) {
    Drink drink;

    ASSERT_EQ(drink.getToppingCount(), 0);
}

TEST(DRINK, get_topping_count2) {
    Drink drink("QQㄋㄟㄋㄟ好喝到咩噗茶", 0.5f);

    drink.addTopping("Bubble");
    drink.addTopping("Ice");

    ASSERT_EQ(drink.getToppingCount(), 2);
}

#endif