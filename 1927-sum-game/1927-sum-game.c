#include <stdbool.h>
#include <string.h>

bool sumGame(char * num) {

    int n = strlen(num);

    int leftSum = 0, rightSum = 0;
    int leftQ = 0, rightQ = 0;

    // Left half
    for (int i = 0; i < n / 2; i++) {

        if (num[i] == '?')
            leftQ++;
        else
            leftSum += num[i] - '0';
    }

    // Right half
    for (int i = n / 2; i < n; i++) {

        if (num[i] == '?')
            rightQ++;
        else
            rightSum += num[i] - '0';
    }

    // If odd number of '?', Alice wins
    if ((leftQ + rightQ) % 2)
        return true;

    // Check if Bob can balance
    return (leftSum - rightSum) !=
           ((rightQ - leftQ) * 9 / 2);
}