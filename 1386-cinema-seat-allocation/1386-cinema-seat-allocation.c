#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    if (x[0] == y[0]) return x[1] - y[1];
    return x[0] - y[0];
}

int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize) {

    qsort(reservedSeats, reservedSeatsSize, sizeof(int*), cmp);

    int result = 0;
    int i = 0;

    while (i < reservedSeatsSize) {

        int row = reservedSeats[i][0];
        int mask = 0;

        while (i < reservedSeatsSize && reservedSeats[i][0] == row) {
            int seat = reservedSeats[i][1];
            if (seat >= 2 && seat <= 9)
                mask |= 1 << seat;
            i++;
        }

        int count = 0;

        int left  = (mask & ((1<<2)|(1<<3)|(1<<4)|(1<<5))) == 0;
        int right = (mask & ((1<<6)|(1<<7)|(1<<8)|(1<<9))) == 0;
        int mid   = (mask & ((1<<4)|(1<<5)|(1<<6)|(1<<7))) == 0;

        if (left) count++;
        if (right) count++;
        if (!left && !right && mid) count++;

        result += count;
    }

    // rows with no reservations
    int rows_with_reserved = 0;
    for (int j = 0; j < reservedSeatsSize; j++) {
        if (j == 0 || reservedSeats[j][0] != reservedSeats[j-1][0])
            rows_with_reserved++;
    }

    result += (n - rows_with_reserved) * 2;

    return result;
}