char* reformat(char* s) {
    int a[26] = { 0 }, n[10] = { 0 }, ac = 0, nc = 0, d;
    char *o = s--;
    while (*++s || (s--, 0))
        (*s <= '9' && (n[*s - '0']++, ++nc)) || (a[*s - 'a']++, ++ac);    
    d = abs(nc - ac);
    for (int j = 0, k = 0, f = ac > nc; s >= o && d <= 1 ; f = !f)
        if (f) {
            while (j < 26 && !a[j] && ++j);
            j < 26 && a[j] && (*s-- = j + 'a', a[j]--);
        } else {
            while (k < 10 && !n[k] && ++k);
            k < 10 && n[k] && (*s-- = k + '0', n[k]--);
        }
    return d <= 1 ? s + 1 : "";
}

