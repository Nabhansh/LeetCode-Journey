#include <string.h>

int helper(int *cnt)
{
    int sum = 0;
    int max = 0;

    for (int i = 0; i < 10; i++)
    {
        sum += cnt[i];

        if (cnt[i] > max)
            max = cnt[i];
    }

    int pairs = sum / 2;
    int possible = sum - max;

    return pairs < possible ? pairs : possible;
}

int score(char** cards, int cardsSize, char x)
{
    int first[10] = {0};
    int second[10] = {0};

    int same = 0;
    int other = 0;

    for (int i = 0; i < cardsSize; i++)
    {
        if (cards[i][0] == x && cards[i][1] == x)
        {
            same++;
        }
        else if (cards[i][0] == x)
        {
            first[cards[i][1] - 'a']++;
            other++;
        }
        else if (cards[i][1] == x)
        {
            second[cards[i][0] - 'a']++;
            other++;
        }
    }

    if (same >= other)
        return other;

    int internal = helper(first) + helper(second);
    int remaining = other - same;

    return same + (internal < remaining / 2 ? internal : remaining / 2);
}