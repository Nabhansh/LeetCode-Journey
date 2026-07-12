int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool hasGroupsSizeX(int* deck, int deckSize) {
    int count[10000] = {0};

    for (int i = 0; i < deckSize; i++) {
        count[deck[i]]++;
    }

    int result = 0;

    for (int i = 0; i < 10000; i++) {
        if (count[i] > 0) {
            result = gcd(result, count[i]);
        }
    }

    return result >= 2;
}