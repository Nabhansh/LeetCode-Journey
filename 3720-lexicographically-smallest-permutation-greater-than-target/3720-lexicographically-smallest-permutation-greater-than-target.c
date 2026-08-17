char* answer;
bool found;

void dfs(int* freq, const char* target, char* current, int pos, int targetLen, bool isGreater) {
    if (found) return;

    if (pos == targetLen) {
        if (isGreater) {
            strcpy(answer, current);
            found = true;
        }
        return;
    }

    if (isGreater) {
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                freq[i]--;
                current[pos] = 'a' + i;
                current[pos + 1] = '\0';
                dfs(freq, target, current, pos + 1, targetLen, true);
                if (found) return;
                freq[i]++;
            }
        }
        return;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] == 0) continue;

        char ch = 'a' + i;
        
        if (ch < target[pos]) continue;

        freq[i]--;
        current[pos] = ch;
        current[pos + 1] = '\0';

        dfs(freq, target, current, pos + 1, targetLen, ch > target[pos]);

        if (found) return;
        
        freq[i]++;
    }
}

int cmp(const void* a, const void* b) {
    return *(char*)a - *(char*)b;
}

char* lexGreaterPermutation(char* s, char* target) {
    int sLen = strlen(s);
    int targetLen = strlen(target);
    
    qsort(s, sLen, sizeof(char), cmp);

    int freq[26] = {0};
    for (int i = 0; i < sLen; i++) {
        freq[s[i] - 'a']++;
    }

    answer = (char*)malloc((sLen + 1) * sizeof(char));
    answer[0] = '\0';
    found = false;

    char* current = (char*)malloc((sLen + 1) * sizeof(char));
    current[0] = '\0';

    // DFS 搜索
    dfs(freq, target, current, 0, targetLen, false);

    free(current);

    return answer;
}