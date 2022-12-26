#ifndef CHOCOLATE_CAKE_H
#define CHOCOLATE_CAKE_H

#include <string>

#include "fmt.h"

#include "cake.h"

class ChocolateCake : public Cake {
public:
    using Cake::Cake;
    ChocolateCake(int price, int sweet) : Cake(price, sweet) { m_Total++; }
    ~ChocolateCake() override { m_Total--; }

    static int get_total() { return m_Total; }

    std::string to_string() const override;

private:
    static int m_Total;
};

int ChocolateCake::m_Total = 0;

std::string ChocolateCake::to_string() const {
    return fmt("| ChocolateCake        |         %2d |         %2d |\n", //
               m_Price, m_Sweet);
}

#endif
