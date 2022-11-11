#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
    Product() = default;
    Product(std::string name, int price);

    Product &operator=(const Product &other) = default;
    bool operator==(const Product &other) const;

    std::string getName() const { return m_Name; }
    int getPrice() const { return m_Price; }

private:
    std::string m_Name;
    int m_Price;
};

Product::Product(std::string name, int price) {
    if (name.size() < 4 || price < 0)
        throw std::string("Invalid Value");

    m_Name = name;
    m_Price = price;
}

bool Product::operator==(const Product &other) const {
    return m_Name == other.m_Name && m_Price == other.m_Price;
}

#endif