int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
    if (a == e) {
        if (c == a && ((b < d && d < f) || (f < d && d < b)))
            return 2;
        return 1;
    }

    if (b == f) {
        if (d == b && ((a < c && c < e) || (e < c && c < a)))
            return 2;
        return 1;
    }

    if (c + d == e + f) {
        if (a + b == c + d && ((c < a && a < e) || (e < a && a < c)))
            return 2;
        return 1;
    }

    if (c - d == e - f) {
        if (a - b == c - d && ((c < a && a < e) || (e < a && a < c)))
            return 2;
        return 1;
    }

    return 2;
}