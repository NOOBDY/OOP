#ifndef COOKIE_H
#define COOKIE_H

int max_dv(const int n, const int array[]) {
    int odd = 0;
    int even = 0;

    if (n < 0)
        return -1;

    for (int i = 0; i < n; ++i) {
        if (array[i] < 0)
            return -1;
    }

    for (int i = 0; i < n; i += 2)
        odd += array[i];

    for (int i = 1; i < n; i += 2)
        even += array[i];

    return odd >= even ? odd : even;
}

#endif