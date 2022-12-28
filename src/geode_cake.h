#ifndef GEODE_CAKE_H
#define GEODE_CAKE_H

#include <string>

#include "fmt.h"

#include "cake.h"

class GeodeCake : public Cake {
public:
    GeodeCake(int price, int sweet);
    ~GeodeCake() override { m_Count--; }

    static int get_count();

    std::string to_string() const override;

private:
    static int m_Count;
};

int GeodeCake::m_Count = 0;

GeodeCake::GeodeCake(int price, int sweet) : Cake(price, sweet) {
    m_Count++;
}

std::string GeodeCake::to_string() const {
    return fmt("| GeodeCake            |         %2d |         %2d |", //
               m_Price, m_Sweet);
}

int GeodeCake::get_count() {
    return m_Count;
}

#endif
