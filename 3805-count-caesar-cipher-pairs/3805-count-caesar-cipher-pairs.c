int cmpFunc(const void* a, const void* b)
{ return strcmp(*(char**)a, *(char**)b); }

long long countPairs(char** words, int wordsSize) {
    long long result=0; int i, j, dist, temp;

    /* Return to base word. */
    for(i=0; i<wordsSize; i++) {
        dist=words[i][0]-'a';
        for(j=0; words[i][j]!='\0'; j++) {
            temp=words[i][j]-'a';
            temp=(temp+26-dist)%26;
            words[i][j]='a'+temp;
        }
    }

    /* Sort the base words. */
    qsort(words, wordsSize, sizeof(char*), cmpFunc);

    /* Calculate the result. */
    for(i=1, temp=1; i<wordsSize; i++) {
        if(strcmp(words[i], words[i-1]))
        { temp=1; }else{ result+=temp++; }
    }

    return result;
}