#ifndef DRINK_H
#define DRINK_H

#include <string>
#include <vector>

class Drink {
public:
    Drink() = default;
    Drink(const std::string name, const float sweetnessLevel,
          const std::vector<std::string> toppings = {});
    ~Drink() = default;

    std::string getName() const;
    float getSweetnessLevel() const;
    std::string getToppingByIndex(const std::size_t index) const;
    std::size_t getToppingCount() const;

    void addTopping(const std::string topping);

private:
    std::string m_Name = "";
    float m_SweetnessLevel = -1;
    std::vector<std::string> m_Toppings = {};
};

Drink::Drink(const std::string name, const float sweetnessLevel,
             const std::vector<std::string> toppings) {
    if (name.size() < 4)
        throw std::string("Invalid Name");

    if (sweetnessLevel > 1 || sweetnessLevel < 0)
        throw std::string("Invalid Sweetness Level");

    m_Name = name;
    m_SweetnessLevel = sweetnessLevel;
    m_Toppings = toppings;
}

std::string Drink::getName() const {
    if (m_Name == "")
        throw std::string("Empty Name");

    return m_Name;
}

float Drink::getSweetnessLevel() const {
    if (m_SweetnessLevel == -1)
        throw std::string("Empty Sweetness Level");

    return m_SweetnessLevel;
}

std::string Drink::getToppingByIndex(const std::size_t index) const {
    std::size_t size = getToppingCount();

    if (index >= size)
        throw std::string("Index Out of Range");

    return m_Toppings[index];
}

std::size_t Drink::getToppingCount() const {
    return m_Toppings.size();
}

void Drink::addTopping(const std::string topping) {
    m_Toppings.push_back(topping);
}

#endif