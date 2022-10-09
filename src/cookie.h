#ifndef COOKIE_H
#define COOKIE_H

#include <iostream>
#include <string>

#define GRID_SIZE 10

/** Return the x-coordinate of the latest of cookie. */
int check_x(bool **grid) {
    for (int i = 0; i < GRID_SIZE; ++i)
        for (int j = GRID_SIZE - 1; j >= 0; --j)
            if (grid[i][j])
                return j;

    return -1;
}

/** Return the y-coordinate of the latest of cookie. */
int check_y(bool **grid) {
    for (int i = 0; i < GRID_SIZE; ++i)
        for (int j = GRID_SIZE - 1; j >= 0; --j)
            if (grid[i][j])
                return i;

    return -1;
}

/** Print the grid you input. */
int print_grid(bool **grid) {
    /* Implement this function if necessary, it can help you to check your grid
     * is correct or not. */
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j)
            std::cout << grid[i][j] << " ";

        std::cout << "\n";
    }

    return 0;
}

/** Get the coordinate of the cookie which place latest from grid. */
void placeTop(bool **grid) {
    /* You can implement check_x(), check_y() above to get the x, y of the
     * latest cookie you place. */
    int x = check_x(grid);
    int y = check_y(grid);

    /* Check when you place cookie, it will out of bound or not. */
    if (x >= 9 || y <= 0)
        throw std::string("out of range");

    /* Place cookie from the top of current cookie. */
    grid[--y][x] = true;
}

/** Get the coordinate of the cookie which place latest from grid. */
void placeRight(bool **grid) {
    int x = check_x(grid);
    int y = check_y(grid);

    /* Check when you place cookie, it will out of bound or not. */
    if (x >= 9 || y <= 0)
        throw std::string("out of range");

    /* Place cookie from the right of current cookie. */
    grid[y][++x] = true;
}

/** Calculate the count of cookie on the specific row */
int calcRow(bool **grid, int row) {
    if (row >= GRID_SIZE)
        return -1;

    int count = 0;

    for (int i = 0; i < GRID_SIZE; ++i)
        count += grid[row][i];

    return count;
}

/** Calculate the count of cookie on the specific column */
int calcColumn(bool **grid, int column) {
    if (column >= GRID_SIZE)
        return -1;

    int count = 0;

    for (int i = 0; i < GRID_SIZE; ++i)
        count += grid[i][column];

    return count;
}

#endif