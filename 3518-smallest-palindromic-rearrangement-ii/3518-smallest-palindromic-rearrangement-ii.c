#include <string.h>
char* smallestPalindrome(char* s, int k) {
    int length = strlen(s);
    if (length < 2 && k == 1) return s;
    char* importantPart = malloc(length / 2);
    char* newImportant = malloc(length / 2);
    char* new = malloc(length + 1);
    strncpy(importantPart, s, length / 2);
    int census[26];
    memset(census, 0, 26 * sizeof(int));
    for (int i = 0; i < length / 2; i++)
    {
        census[importantPart[i] - 'a']++;
    }
    int partialCensus[26];
    memset(partialCensus, 0, 26 * sizeof(int));
    long permutations = 1;
    int usedChars = 0;
    for (int i = 25; i >= 0; i--)
    {
        for (int j = 0; j < census[i]; j++)
        {
            permutations *= ++usedChars;
            permutations /= ++partialCensus[i];
            if (permutations >= k)
            {
                int head = 0;
                for (int x = 0; x < i; x++)
                {
                    for (int y = 0; y < census[x]; y++)
                    {
                        newImportant[head++] = 'a' + x;
                    }
                }
                for (j = ++j; j < census[i]; j++)
                {
                    newImportant[head++] = 'a' + i;
                }
                long eliminatedPerms = 0;
                while (true) for (int x = 0; x < 26; x++)
                {
                    if (partialCensus[x])
                    {
                        int checkPermutations = permutations * partialCensus[x] / usedChars;
                        if (eliminatedPerms + checkPermutations >= k)
                        {
                            newImportant[head++] = 'a' + x;
                            partialCensus[x]--;
                            permutations = checkPermutations;
                            if (--usedChars == 0)
                            {
                                for (int i = 0; i < length / 2; i++)
                                {
                                    new[i] = newImportant[i];
                                    new[length - i - 1] = newImportant[i];
                                }
                                if (length % 2) new[length / 2] = s[length / 2];
                                new[length] = '\0';
                                free(importantPart);
                                free(newImportant);
                                return new;
                            }
                            else break;
                        }
                        else
                        {
                            eliminatedPerms += checkPermutations;
                        }
                    }
                }
            }
        }
    }
    free(importantPart);
    free(newImportant);
    free(new);
    return "";
}