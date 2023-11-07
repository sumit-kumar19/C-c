#include <stdio.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int max3(int a, int b, int c) {
    int temp = max(a, b);
    if (temp > c) {
        return temp;
    } else {
        return c;
    }
}

int ropecut(int n, int a, int b, int c) {
    if (n == 0) {
        return 0;
    }
    if (n < 0) {
        return -1;
    }

    int res = max3(ropecut(n - a, a, b, c), max3(ropecut(n - b, a, b, c), ropecut(n - c, a, b, c));

    if (res == -1) {
        return -1;
    } else {
        return res + 1;
    }
}

int main() {
    int n = 23, a = 11, b = 9, c = 12;
    printf("%d\n", ropecut(n, a, b, c));

    return 0;
}
