#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <algorithm>

#include "alcohol.h"

class Order {
public:
    void append_alcohol(Alcohol *alcohol);
    size_t get_alcohol_count() { return m_Drinks.size(); }
    int get_total_price();

private:
    std::vector<Alcohol *> m_Drinks;
};

void Order::append_alcohol(Alcohol *alcohol) {
    m_Drinks.push_back(alcohol);
}

int Order::get_total_price() {
    int sum = 0;

    std::for_each(m_Drinks.begin(), m_Drinks.end(),
                  [&](Alcohol *d) { sum += d->get_price(); });

    return sum;
}

#endif