char* morse[] = {
    ".-","-...","-.-.","-..",".","..-.","--.","....","..",
    ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
    "...","-","..-","...-",".--","-..-","-.--","--.."
};

int uniqueMorseRepresentations(char** words, int wordsSize) {
    char trans[100][80];
    int cnt = 0;

    for (int i = 0; i < wordsSize; i++) {
        char cur[80] = "";
        for (int j = 0; words[i][j]; j++)
            strcat(cur, morse[words[i][j] - 'a']);

        bool found = false;
        for (int k = 0; k < cnt; k++) {
            if (strcmp(cur, trans[k]) == 0) {
                found = true;
                break;
            }
        }

        if (!found)
            strcpy(trans[cnt++], cur);
    }

    return cnt;
}