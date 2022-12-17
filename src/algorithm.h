#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>
#include <algorithm>

#include "alcohol.h"

bool content_comp(const Alcohol *d1, const Alcohol *d2) {
    return d1->get_alcohol_content() != d2->get_alcohol_content()
               ? d1->get_alcohol_content() < d2->get_alcohol_content()
               : d1->get_name().compare(d2->get_name());
}

bool name_comp(const Alcohol *d1, const Alcohol *d2) {
    return d1->get_name() < d2->get_name();
}

void sort_alcohol_by_content(std::vector<Alcohol *> &alcohol) {
    std::sort(alcohol.begin(), alcohol.end(), content_comp);
}

void sort_alcohol_by_name(std::vector<Alcohol *> &alcohol) {
    std::sort(alcohol.begin(), alcohol.end(), name_comp);
}

Alcohol *get_greatest_content_of_alcohol(std::vector<Alcohol *> &alcohol) {
    return *std::max_element(alcohol.begin(), alcohol.end(), content_comp);
}

Alcohol *get_smallest_content_of_alcohol(std::vector<Alcohol *> &alcohol) {
    return *std::min_element(alcohol.begin(), alcohol.end(), content_comp);
}

#endif