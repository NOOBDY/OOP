#ifndef BEEF_SANDWICH_H
#define BEEF_SANDWICH_H

#include "sandwich.h"

class BeefSandwich : public Sandwich {
public:
    BeefSandwich(int price, int ID);
    ~BeefSandwich() override;

    static bool record_has_specific_id(int ID);
    static std::size_t get_size_of_record_container();

private:
    static std::set<int> m_IDs;
};

std::set<int> BeefSandwich::m_IDs;

BeefSandwich::BeefSandwich(int price, int ID) : Sandwich(price, ID) {
    m_IDs.insert(ID);
}

BeefSandwich::~BeefSandwich() {
    m_IDs.erase(m_ID);
}

bool BeefSandwich::record_has_specific_id(int ID) {
    return m_IDs.find(ID) != m_IDs.end();
}

std::size_t BeefSandwich::get_size_of_record_container() {
    return m_IDs.size();
}

#endif
