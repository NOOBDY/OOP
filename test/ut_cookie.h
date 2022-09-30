#ifndef UT_COOKIE_H
#define UT_COOKIE_H

#include <gtest/gtest.h>

#include "../src/cookie.h"

TEST(MAX_DV, even1) {
    const int n = 4;
    const int array[] = {1, 2, 3, 4};

    int target = 6;
    int output = max_dv(n, array);

    ASSERT_EQ(target, output);
}

TEST(MAX_DV, even2) {
    const int n = 6;
    const int array[] = {1, 3, 1, 2, 5, 4};

    int target = 9;
    int output = max_dv(n, array);

    ASSERT_EQ(target, output);
}

TEST(MAX_DV, odd1) {
    const int n = 3;
    const int array[] = {2, 7, 4};

    int target = 7;
    int output = max_dv(n, array);

    ASSERT_EQ(target, output);
}

TEST(MAX_DV, odd2) {
    const int n = 5;
    const int array[] = {2, 7, 4, 1, 8};

    int target = 14;
    int output = max_dv(n, array);

    ASSERT_EQ(target, output);
}

TEST(MAX_DV, neg_array_val1) {
    const int n = 4;
    const int array[] = {1, -2, 3, 4};

    int target = -1;
    int output = max_dv(n, array);

    ASSERT_EQ(target, output);
}

TEST(MAX_DV, neg_array_val2) {
    const int n = 3;
    const int array[] = {3, 1, -5};

    int target = -1;
    int output = max_dv(n, array);

    ASSERT_EQ(target, output);
}

TEST(MAX_DV, neg_array_size1) {
    const int n = -2;
    const int array[] = {1, 5};

    int target = -1;
    int output = max_dv(n, array);

    ASSERT_EQ(target, output);
}

TEST(MAX_DV, neg_array_size2) {
    const int n = -3;
    const int array[] = {1, 5, 2};

    int target = -1;
    int output = max_dv(n, array);

    ASSERT_EQ(target, output);
}

#endif