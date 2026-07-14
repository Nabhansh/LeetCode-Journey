int bitwiseComplement(int n) {
    if (n == 0) {
        return 1;
    }

    unsigned int mask = 0;
    unsigned int temp = (unsigned int)n;

    while (temp > 0) {
        mask = (mask << 1) | 1;
        temp >>= 1;
    }

    return n ^ mask;
}