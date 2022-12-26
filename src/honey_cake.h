#ifndef HONEY_CAKE_H
#define HONEY_CAKE_H

#include <string>

#include "fmt.h"

#include "cake.h"

class HoneyCake : public Cake {
public:
    using Cake::Cake;
    HoneyCake(int price, int sweet) : Cake(price, sweet) { m_Total++; }
    ~HoneyCake() override { m_Total--; }

    static int get_count() { return m_Total; }

    std::string to_string() const override;

private:
    static int m_Total;
};

int HoneyCake::m_Total = 0;

std::string HoneyCake::to_string() const {
    return fmt("| HoneyCake            |         %2d |         %2d |", //
               m_Price, m_Sweet);
}

#endif
