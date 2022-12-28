#ifndef CAKE_H
#define CAKE_H

#include <string>

class Cake {
public:
    Cake() = delete;
    Cake(int price, int sweet);
    virtual ~Cake() { m_Total--; }

    virtual int get_price() const { return m_Price; }
    virtual int get_sweet() const { return m_Sweet; }

    static int get_total() { return m_Total; }

    virtual std::string to_string() const = 0;

protected:
    int m_Price;
    int m_Sweet;

    static int m_Total;
};

int Cake::m_Total = 0;

Cake::Cake(int price, int sweet) : m_Price(price), m_Sweet(sweet) {
    m_Total++;
}

#endif
