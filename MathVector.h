#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H

#include <vector>

class MathVector {
public:
    MathVector() = default;
    MathVector(const std::vector<double> vec);
    MathVector(const int dim, const double arr[]);

    ~MathVector() = default;

    double operator[](int i) { return m_Vector[i]; }
    double GetLength() const;

    std::vector<double> &GetNums() { return m_Vector; }
    const std::vector<double> &GetNums() const { return m_Vector; }

private:
    std::vector<double> m_Vector;
};

#endif