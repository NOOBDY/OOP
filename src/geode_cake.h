#ifndef GEODE_CAKE_H
#define GEODE_CAKE_H

#include <string>

#include "fmt.h"

#include "cake.h"

class GeodeCake : public Cake {
public:
    using Cake::Cake;

    std::string to_string() const override;

private:
    static int m_Total;
};

int GeodeCake::m_Total = 0;

std::string GeodeCake::to_string() const {
    return fmt("| GeodeCake            |         %2d |         %2d |\n", //
               m_Price, m_Sweet);
}

#endif
