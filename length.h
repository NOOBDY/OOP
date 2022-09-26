#ifndef LENGTH_H
#define LENGTH_H

#include "MathVector.h"

double length(double x, double y);
double length(double x, double y, double z);
double length(double v[], int dim);
double length(MathVector &m);
double dot(MathVector v1, MathVector v2);

#endif