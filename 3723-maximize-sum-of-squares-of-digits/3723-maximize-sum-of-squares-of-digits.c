#include <stdlib.h>

char* maxSumOfSquares(int num, int sum)
{
    static char ans[200005];

    if (sum > 9 * num)
        return "";

    int pos = 0;

    while (sum >= 9)
    {
        ans[pos++] = '9';
        sum -= 9;
    }

    if (sum > 0)
        ans[pos++] = '0' + sum;

    while (pos < num)
        ans[pos++] = '0';

    ans[pos] = '\0';

    return ans;
}