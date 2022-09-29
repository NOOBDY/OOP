#include <gtest/gtest.h>
#include "MathVector.h"
#include "length.h"

TEST(MATHVECTOR, Dot)
{
    double arr1[2] = {1, 2};
    double arr2[2] = {3, 4};
    MathVector v1(2, arr1);
    MathVector v2(2, arr2);
    double result = dot(v1, v2);
    ASSERT_NEAR(result, 11, 0.01);
}