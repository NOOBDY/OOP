#ifndef TEQUILA_H
#define TEQUILA_H

#include "alcohol.h"

class Tequila : public Alcohol {
public:
    using Alcohol::Alcohol;

    void dilute();

    Tequila operator+(const Tequila &other);
    bool operator==(const Tequila &other);
    Tequila &operator=(const Tequila &other) = default;
};

void Tequila::dilute() {
    m_Content *= 0.05;
}

Tequila Tequila::operator+(const Tequila &other) {
    return Tequila(m_Name, m_Price + other.m_Price,
                   (m_Content + other.m_Content) / 2);
}

bool Tequila::operator==(const Tequila &other) {
    return m_Name == other.m_Name && m_Price == other.m_Price &&
           m_Content == other.m_Content;
}

#endif