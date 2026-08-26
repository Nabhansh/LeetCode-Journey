#include <stdlib.h>
#include <math.h>

double* internalAngles(int* sides, int sidesSize, int* returnSize) {
    *returnSize = 0;

    int a = sides[0];
    int b = sides[1];
    int c = sides[2];

    if (a > b) {
        int t = a;
        a = b;
        b = t;
    }

    if (b > c) {
        int t = b;
        b = c;
        c = t;
    }

    if (a > b) {
        int t = a;
        a = b;
        b = t;
    }

    if (a + b <= c)
        return NULL;

    double* ans = malloc(3 * sizeof(double));

    ans[0] = acos(((double)b * b + (double)c * c - (double)a * a) /
                  (2.0 * b * c)) * 180.0 / M_PI;

    ans[1] = acos(((double)a * a + (double)c * c - (double)b * b) /
                  (2.0 * a * c)) * 180.0 / M_PI;

    ans[2] = acos(((double)a * a + (double)b * b - (double)c * c) /
                  (2.0 * a * b)) * 180.0 / M_PI;

    *returnSize = 3;
    return ans;
}