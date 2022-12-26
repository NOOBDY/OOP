#ifndef CAKE_SHOWCASE_H
#define CAKE_SHOWCASE_H

#include <vector>
#include <string>
#include <numeric>
#include <stdexcept>

#include "cake.h"

template <typename T>
class CakeShowcase {
public:
    CakeShowcase(int length, T **arr) {
        m_Cakes.insert(m_Cakes.end(), &arr[0], &arr[length]);
    }

    int calc_total_price() {
        return std::accumulate(
            m_Cakes.begin(), m_Cakes.end(), 0,
            [](int total, T *cake) { return total + cake->get_price(); });
    }

    int calc_total_sweet() {
        return std::accumulate(
            m_Cakes.begin(), m_Cakes.end(), 0,
            [](int total, T *cake) { return total + cake->get_sweet(); });
    }

    std::string to_string() {
        std::string result =
            "| CakeName             | Price      | Sweet      |\n"
            "| -------------------- | ---------- | ---------- |\n";

        for (const auto &cake : m_Cakes)
            result += cake->to_string();

        result += "| -------------------- | ---------- | ---------- |\n";

        return result;
    }

    T *operator[](int index) {
        if (index >= m_Cakes.size())
            throw std::out_of_range("Index out of range");

        return m_Cakes[index];
    }

private:
    std::vector<T *> m_Cakes;
};

#endif
