#ifndef CAKE_SHOWCASE_H
#define CAKE_SHOWCASE_H

#include <vector>
#include <string>
#include <numeric>
#include <stdexcept>

#include "fmt.h"

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
        return fmt("| CakeName             | Price      | Sweet      |\n"
                   "| -------------------- | ---------- | ---------- |\n"
                   "%s"
                   "| -------------------- | ---------- | ---------- |",
                   std::accumulate(m_Cakes.begin(), m_Cakes.end(),
                                   std::string(),
                                   [](std::string str, T *cake) {
                                       return str + cake->to_string() + "\n";
                                   })
                       .c_str());
    }

    T *operator[](int index) { return m_Cakes.at(index); }

private:
    std::vector<T *> m_Cakes;
};

#endif
