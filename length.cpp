#include "length.h"

#include <cmath>

double length(double x, double y) {
    using namespace std;

    double i = 0;

    i = pow(x, 2) + pow(y, 2);

    return sqrt(i);
}

double length(double x, double y, double z) {
    using namespace std;

    double i = 0;

    i = pow(x, 2) + pow(y, 2) + pow(z, 2);

    return sqrt(i);
}

double length(double v[], int dim) {
    using namespace std;

    double sum = 0;

    for (int i = 0; i < dim; ++i)
        sum += pow(v[i], 2);

    return sqrt(sum);
}

double length(MathVector &m) {
    return m.GetLength();
}