typedef struct {
    char word[20];
    int cnt;
} Node;

int mostCommonWordCmp(const void *a, const void *b) {
    return ((Node *)b)->cnt - ((Node *)a)->cnt;
}

char* mostCommonWord(char* paragraph, char** banned, int bannedSize) {
    Node words[1000];
    int size = 0;
    int n = strlen(paragraph);

    for (int i = 0; i < n;) {
        while (i < n && !isalpha(paragraph[i])) i++;
        if (i == n) break;

        char tmp[20];
        int k = 0;
        while (i < n && isalpha(paragraph[i]))
            tmp[k++] = tolower(paragraph[i++]);
        tmp[k] = '\0';

        bool ban = false;
        for (int j = 0; j < bannedSize; j++)
            if (strcmp(tmp, banned[j]) == 0) {
                ban = true;
                break;
            }
        if (ban) continue;

        int idx = -1;
        for (int j = 0; j < size; j++)
            if (!strcmp(words[j].word, tmp)) {
                idx = j;
                break;
            }

        if (idx == -1) {
            strcpy(words[size].word, tmp);
            words[size].cnt = 1;
            size++;
        } else {
            words[idx].cnt++;
        }
    }

    qsort(words, size, sizeof(Node), mostCommonWordCmp);
    return strdup(words[0].word);
}