#include <string.h>

char* lexSmallest(char* s)
{
    static char answer[1005];
    char temp[1005];

    int n = strlen(s);

    strcpy(answer, s);

    /*
        Try every k.
    */
    for (int k = 1; k <= n; k++)
    {
        /*
            Reverse first k characters.
        */
        strcpy(temp, s);

        int left = 0;
        int right = k - 1;

        while (left < right)
        {
            char c = temp[left];
            temp[left] = temp[right];
            temp[right] = c;

            left++;
            right--;
        }

        if (strcmp(temp, answer) < 0)
            strcpy(answer, temp);

        /*
            Reverse last k characters.
        */
        strcpy(temp, s);

        left = n - k;
        right = n - 1;

        while (left < right)
        {
            char c = temp[left];
            temp[left] = temp[right];
            temp[right] = c;

            left++;
            right--;
        }

        if (strcmp(temp, answer) < 0)
            strcpy(answer, temp);
    }

    return answer;
}