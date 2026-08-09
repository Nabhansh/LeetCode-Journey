#include <string.h>

int isPrefixOfWord(char* sentence, char* searchWord)
{
    int wordIndex = 1;
    int i = 0;
    int n = strlen(sentence);
    int m = strlen(searchWord);

    while (i < n)
    {
        while (i < n && sentence[i] == ' ')
            i++;

        if (i >= n)
            break;

        int start = i;

        while (i < n && sentence[i] != ' ')
            i++;

        int length = i - start;

        if (length >= m)
        {
            int match = 1;

            for (int j = 0; j < m; j++)
            {
                if (sentence[start + j] != searchWord[j])
                {
                    match = 0;
                    break;
                }
            }

            if (match)
                return wordIndex;
        }

        wordIndex++;
    }

    return -1;
}