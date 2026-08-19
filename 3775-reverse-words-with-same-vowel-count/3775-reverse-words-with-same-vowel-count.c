#include <stdlib.h>
#include <string.h>

int vowels(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

char* reverseWords(char* s) {
    int n = strlen(s);
    char *ans = (char *)malloc((n + 1) * sizeof(char));
    strcpy(ans, s);

    int firstCount = 0;
    int i = 0;

    while (ans[i] != ' ' && ans[i] != '\0') {
        if (vowels(ans[i]))
            firstCount++;
        i++;
    }

    while (ans[i] != '\0') {
        i++;

        int start = i;
        int count = 0;

        while (ans[i] != ' ' && ans[i] != '\0') {
            if (vowels(ans[i]))
                count++;
            i++;
        }

        if (count == firstCount) {
            int left = start;
            int right = i - 1;

            while (left < right) {
                char temp = ans[left];
                ans[left] = ans[right];
                ans[right] = temp;
                left++;
                right--;
            }
        }
    }

    return ans;
}