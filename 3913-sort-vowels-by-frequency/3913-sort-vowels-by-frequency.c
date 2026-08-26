#include <string.h>

int isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

char* sortVowels(char* s) {
    int freq[5] = {0};
    int first[5] = {1000000000, 1000000000, 1000000000, 1000000000, 1000000000};
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};

    for (int i = 0; s[i]; i++) {
        for (int j = 0; j < 5; j++) {
            if (s[i] == vowels[j]) {
                freq[j]++;
                if (first[j] == 1000000000)
                    first[j] = i;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (freq[j] > freq[i] ||
                (freq[j] == freq[i] && first[j] < first[i])) {
                int tf = freq[i];
                freq[i] = freq[j];
                freq[j] = tf;

                int tfirst = first[i];
                first[i] = first[j];
                first[j] = tfirst;

                char tv = vowels[i];
                vowels[i] = vowels[j];
                vowels[j] = tv;
            }
        }
    }

    int pos = 0;

    for (int i = 0; s[i]; i++) {
        if (isVowel(s[i])) {
            while (pos < 5 && freq[pos] == 0)
                pos++;

            s[i] = vowels[pos];
            freq[pos]--;
        }
    }

    return s;
}