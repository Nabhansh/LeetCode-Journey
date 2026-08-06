#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Helper to find max of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Helper to check if a substring is a palindrome
bool isPalindrome(const char* str, int l, int r) {
    while (l < r) {
        if (str[l++] != str[r--]) return false;
    }
    return true;
}

// Helper to get palindrome lengths for prefixes/suffixes
void getPalindromeLengths(const char* str, int len, int* res, bool isSuffix) {
    for (int i = 0; i < len; ++i) {
        for (int j = i; j < len; ++j) {
            if (isPalindrome(str, i, j)) {
                int pLen = j - i + 1;
                if (isSuffix) {
                    res[i] = max(res[i], pLen); // Longest palindrome starting at i
                } else {
                    res[j] = max(res[j], pLen); // Longest palindrome ending at j
                }
            }
        }
    }
}

int longestPalindrome(char* s, char* t) {
    int m = strlen(s);
    int n = strlen(t);

    int* suffix_s = (int*)calloc(m, sizeof(int));
    int* prefix_t = (int*)calloc(n, sizeof(int));

    getPalindromeLengths(s, m, suffix_s, true);
    getPalindromeLengths(t, n, prefix_t, false);

    int ans = 0;
    for(int i = 0; i < m; i++) ans = max(ans, suffix_s[i]);
    for(int i = 0; i < n; i++) ans = max(ans, prefix_t[i]);

    int** dp = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        dp[i] = (int*)calloc(n, sizeof(int));
    }

    for (int i = 0; i < m; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            if (s[i] == t[j]) {
                dp[i][j] = 2 + (i > 0 && j < n - 1 ? dp[i - 1][j + 1] : 0);
                int extend = max(i + 1 < m ? suffix_s[i + 1] : 0, j > 0 ? prefix_t[j - 1] : 0);
                ans = max(ans, dp[i][j] + extend);
            }
        }
    }

    // Free memory
    free(suffix_s);
    free(prefix_t);
    for (int i = 0; i < m; i++) {
        free(dp[i]);
    }
    free(dp);

    return ans;
}
