#ifndef ALCOHOL_H
#define ALCOHOL_H

#include <string>
#include <stdexcept>

using String = std::string;
using namespace std;

class Alcohol {
public:
    Alcohol() = default;
    Alcohol(String name, int price, double content);
    virtual ~Alcohol() = default;

    virtual void dilute() = 0;

    String get_name() const { return m_Name; }
    int get_price() const { return m_Price; }
    double get_alcohol_content() const { return m_Content; };

protected:
    String m_Name;
    int m_Price;
    double m_Content;
};

Alcohol::Alcohol(String name, int price, double content) {
    if (name.length() == 0 || price < 0 || content > 1 || content < 0)
        throw std::invalid_argument("Invalid argument");

    m_Name = name;
    m_Price = price;
    m_Content = content;
}

#endif