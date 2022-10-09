#ifndef UT_COOKIE_H
#define UT_COOKIE_H

#include <gtest/gtest.h>

#include "../src/cookie.h"

bool **create_grid() {
    bool **grid = new bool *[GRID_SIZE];

    for (int i = 0; i < GRID_SIZE; ++i)
        grid[i] = new bool[GRID_SIZE]{0};

    grid[9][0] = true;

    return grid;
}

void delete_grid(bool **grid) {
    for (int i = 0; i < GRID_SIZE; ++i)
        delete[] grid[i];

    delete[] grid;
}

TEST(COOKIE, normal1) {
    bool **grid = create_grid();

    int x = check_x(grid);
    int y = check_y(grid);

    ASSERT_EQ(x, 0);
    ASSERT_EQ(y, 9);

    placeTop(grid);
    placeRight(grid);

    for (int i = 0; i < 5; ++i)
        placeTop(grid);

    int colCount = calcColumn(grid, 1);
    int rowCount = calcRow(grid, 4);

    ASSERT_EQ(colCount, 6);
    ASSERT_EQ(rowCount, 1);

    delete_grid(grid);
}

TEST(COOKIE, normal2) {
    bool **grid = create_grid();

    for (int i = 0; i < 6; ++i) {
        placeRight(grid);
        placeTop(grid);
    }

    int colCount = calcColumn(grid, 3);

    ASSERT_EQ(colCount, 2);

    delete_grid(grid);
}

TEST(COOKIE, place_oor1) {
    bool **grid = create_grid();

    auto lambda = [](bool **grid) {
        for (int i = 0; i < 20; ++i)
            placeTop(grid);
    };

    ASSERT_THROW(lambda(grid), std::string);

    delete_grid(grid);
}

TEST(COOKIE, place_oor2) {
    bool **grid = create_grid();

    auto lambda = [](bool **grid) {
        for (int i = 0; i < 10; ++i)
            placeRight(grid);
    };

    ASSERT_THROW(lambda(grid), std::string);

    delete_grid(grid);
}

TEST(COOKIE, query_oor1) {
    bool **grid = create_grid();

    int rowCount = calcRow(grid, 420);

    ASSERT_EQ(rowCount, -1);

    delete_grid(grid);
}

TEST(COOKIE, query_oor2) {
    bool **grid = create_grid();

    int colCount = calcColumn(grid, 69);

    ASSERT_EQ(colCount, -1);

    delete_grid(grid);
}

TEST(COOKIE, ten_times) {
    bool **grid = create_grid();

    for (int i = 0; i < 5; ++i)
        placeTop(grid);

    for (int i = 0; i < 5; ++i)
        placeRight(grid);

    int rowCount = calcRow(grid, 4);

    ASSERT_EQ(rowCount, 6);

    delete_grid(grid);
}

#endif