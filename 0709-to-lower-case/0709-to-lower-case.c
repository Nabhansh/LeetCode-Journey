char* toLowerCase(char* s) {
    int i = 0;
    while (s[i]) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
        i++;
    }
    return s;
}