int maximum69Number (int num) {
    int place = 1;
    int temp = num;
    int change = 0;

    while (temp > 0) {
        if (temp % 10 == 6)
            change = place;
        temp /= 10;
        place *= 10;
    }

    return num + 3 * change;
}