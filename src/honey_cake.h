#ifndef HONEY_CAKE_H
#define HONEY_CAKE_H

#include <string>

#include "fmt.h"

#include "cake.h"

class HoneyCake : public Cake {
public:
    HoneyCake(int price, int sweet);
    ~HoneyCake() override { m_Count--; }

    static int get_count();

    std::string to_string() const override;

private:
    static int m_Count;
};

int HoneyCake::m_Count = 0;

HoneyCake::HoneyCake(int price, int sweet) : Cake(price, sweet) {
    m_Count++;
}

std::string HoneyCake::to_string() const {
    return fmt("| HoneyCake            |         %2d |         %2d |", //
               m_Price, m_Sweet);
}

int HoneyCake::get_count() {
    return m_Count;
}

#endif
