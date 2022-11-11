#ifndef SHOPPING_CART
#define SHOPPING_CART

#include <vector>

#include "Product.h"

class ShoppingCart {
public:
    ShoppingCart() = default;
    ShoppingCart(int item_list_size, Product item_list[]);
    ~ShoppingCart() = default;

    ShoppingCart &operator+(const ShoppingCart &other);
    ShoppingCart &operator-(const ShoppingCart &other);
    ShoppingCart &operator=(const ShoppingCart &other) = default;

    std::size_t getItemCount() const { return m_Products.size(); }
    Product getItemByIndex(std::size_t index);
    void setItemByIndex(std::size_t index, Product product);
    void appendItem(Product product);
    int getTotalCost() const;

private:
    std::vector<Product> m_Products;
};

ShoppingCart::ShoppingCart(int item_list_size, Product item_list[]) {
    for (int i = 0; i < item_list_size; ++i) {
        for (const auto &el : m_Products)
            if (item_list[i] == el)
                throw std::string("Duplicate Product");

        m_Products.push_back(item_list[i]);
    }
}

Product ShoppingCart::getItemByIndex(std::size_t index) {
    if (index > m_Products.size())
        throw std::string("Index Ouf of Range");

    return m_Products[index];
}

ShoppingCart &ShoppingCart::operator+(const ShoppingCart &other) {
    for (const auto &i : other.m_Products) {
        bool dup = false;
        for (const auto &j : m_Products) {
            if (i == j)
                dup = true;
        }
        if (!dup)
            m_Products.push_back(i);
    }

    return *this;
}

ShoppingCart &ShoppingCart::operator-(const ShoppingCart &other) {
    for (const auto &i : other.m_Products) {
        for (int j = 0; j < m_Products.size(); ++j) {
            if (i == m_Products[j])
                m_Products.erase(m_Products.begin() + j);
        }
    }

    return *this;
}

void ShoppingCart::setItemByIndex(std::size_t index, Product product) {
    if (index > m_Products.size())
        throw std::string("Index Ouf of Range");

    for (const auto &el : m_Products)
        if (el == product)
            throw std::string("Duplicate Product");

    m_Products[index] = product;
}

void ShoppingCart::appendItem(Product product) {
    for (const auto &el : m_Products)
        if (el == product)
            throw std::string("Duplicate Product");

    m_Products.push_back(product);
};

int ShoppingCart::getTotalCost() const {
    int total = 0;

    for (const auto &el : m_Products) {
        total += el.getPrice();
    }

    return total;
}

#endif