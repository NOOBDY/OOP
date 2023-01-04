#ifndef SANDWICH_FACTORY_H
#define SANDWICH_FACTORY_H

#include <vector>

template <typename T>
class SandwichFactory {
public:
    static T *create_sandwich(int price, int ID) { return new T(price, ID); }

    static std::vector<T *> create_sandwich_array(int price, int count,
                                                  std::vector<int> ID_list) {
        std::vector<T *> res;

        for (const auto &id : ID_list)
            res.push_back(new T(price, id));

        return res;
    }
};

#endif
