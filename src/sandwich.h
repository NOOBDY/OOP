#ifndef SANDWICH_H
#define SANDWICH_H

#include <set>

class Sandwich {
public:
    Sandwich(int price, int ID);
    virtual ~Sandwich();

    virtual int get_price() const { return m_Price; }
    virtual int get_ID() const { return m_ID; }

    static bool record_has_specific_id(int ID);
    static std::size_t get_size_of_record_container();

protected:
    int m_Price;
    int m_ID;

    static std::set<int> m_IDs;
};

std::set<int> Sandwich::m_IDs;

Sandwich::Sandwich(int price, int ID) : m_Price(price), m_ID(ID) {
    m_IDs.insert(ID);
}

Sandwich::~Sandwich() {
    m_IDs.erase(m_ID);
}

bool Sandwich::record_has_specific_id(int ID) {
    return m_IDs.find(ID) != m_IDs.end();
}

std::size_t Sandwich::get_size_of_record_container() {
    return m_IDs.size();
}

#endif
