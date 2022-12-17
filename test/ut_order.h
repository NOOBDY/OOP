#ifndef UT_ORDER_H
#define UT_ORDER_H

#include <memory>

#include <gtest/gtest.h>

#include "../src/sour.h"
#include "../src/tequila.h"

#include "../src/order.h"

template <typename T>
using Sp = std::shared_ptr<T>;

class TestOrder : public ::testing::Test {
public:
    Order testOrder;

    Sp<Sour> d1 = std::make_shared<Sour>("testSour1", 40, 0.3);
    Sp<Tequila> d2 = std::make_shared<Tequila>("testTequila1", 40, 0.6);
    Sp<Sour> d3 = std::make_shared<Sour>("testSour2", 60, 0.1);
    Sp<Tequila> d4 = std::make_shared<Tequila>("testTequila2", 60, 0.3);

    void init() {
        testOrder.append_alcohol(d1.get());
        testOrder.append_alcohol(d2.get());
        testOrder.append_alcohol(d3.get());
        testOrder.append_alcohol(d4.get());
    }
};

TEST_F(TestOrder, test_alcohol_count) {
    init();

    ASSERT_EQ(testOrder.get_alcohol_count(), 4);
}

TEST_F(TestOrder, test_total_price) {
    init();

    ASSERT_EQ(testOrder.get_total_price(), 200);
}

#endif