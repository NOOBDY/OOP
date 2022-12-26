#ifndef CHOCOLATE_CAKE_H
#define CHOCOLATE_CAKE_H

#include <string>

#include "fmt.h"

#include "cake.h"

class ChocolateCake : public Cake {
public:
    using Cake::Cake;

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
