#include <stdlib.h>
#include <string.h>

int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

char* gcdOfStrings(char* str1, char* str2) {
    int n1 = strlen(str1), n2 = strlen(str2);

    char *a = malloc(n1 + n2 + 1);
    char *b = malloc(n1 + n2 + 1);

    strcpy(a, str1);
    strcat(a, str2);

    strcpy(b, str2);
    strcat(b, str1);

    if (strcmp(a, b) != 0) {
        free(a);
        free(b);
        char *ans = malloc(1);
        ans[0] = '\0';
        return ans;
    }

    free(a);
    free(b);

    int g = gcd(n1, n2);
    char *ans = malloc(g + 1);
    strncpy(ans, str1, g);
    ans[g] = '\0';
    return ans;
}