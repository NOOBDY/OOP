#ifndef SWEET_SANDWICH_H
#define SWEET_SANDWICH_H

#include "sandwich.h"

class SweetSandwich : public Sandwich {
public:
    SweetSandwich(int price, int ID);
    ~SweetSandwich() override;

    static bool record_has_specific_id(int ID);
    static std::size_t get_size_of_record_container();

private:
    static std::set<int> m_IDs;
};

std::set<int> SweetSandwich::m_IDs;

SweetSandwich::SweetSandwich(int price, int ID) : Sandwich(price, ID) {
    m_IDs.insert(ID);
}

SweetSandwich::~SweetSandwich() {
    m_IDs.erase(m_ID);
}

bool SweetSandwich::record_has_specific_id(int ID) {
    return m_IDs.find(ID) != m_IDs.end();
}

std::size_t SweetSandwich::get_size_of_record_container() {
    return m_IDs.size();
}

#endif
