#ifndef SOUR_H
#define SOUR_H

#include "alcohol.h"

class Sour : public Alcohol {
public:
    using Alcohol::Alcohol;

    void dilute();

    Sour operator+(const Sour &other);
    bool operator==(const Sour &other);
    Sour &operator=(const Sour &other) = default;
};

void Sour::dilute() {
    m_Content *= 0.3;
}

Sour Sour::operator+(const Sour &other) {
    return Sour(m_Name, m_Price + other.m_Price,
                (m_Content + other.m_Content) / 2);
}

bool Sour::operator==(const Sour &other) {
    return m_Name == other.m_Name && m_Price == other.m_Price &&
           m_Content == other.m_Content;
}

#endif