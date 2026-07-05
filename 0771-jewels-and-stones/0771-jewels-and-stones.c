int numJewelsInStones(char* jewels, char* stones) {
    bool isJewel[128] = {false};

    while (*jewels) {
        isJewel[(int)*jewels] = true;
        jewels++;
    }

    int count = 0;

    while (*stones) {
        if (isJewel[(int)*stones])
            count++;
        stones++;
    }

    return count;
}