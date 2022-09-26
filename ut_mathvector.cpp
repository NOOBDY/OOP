#include <gtest/gtest.h>

#include "length.h"
#include "MathVector.h"

TEST(MATHVECTOR, Dot) {
    double arr1[2] = {1, 2};
    double arr2[2] = {3, 4};

    MathVector v1(2, arr1);
    MathVector v2(2, arr2);

    double output = dot(v1, v2);
    double target = 11;

    ASSERT_NEAR(output, target, 0.01f);
}