#include "MathVector.h"

#include <cmath>

MathVector::MathVector(const std::vector<double> vec) : m_Vector(vec) {}

MathVector::MathVector(const int dim, const double arr[]) {
    m_Vector.insert(m_Vector.end(), &arr[0], &arr[dim]);
}

double MathVector::GetLength() const {
    double res = 0;

    for (const auto &num : m_Vector)
        res += pow(num, 2);

    return sqrt(res);
}