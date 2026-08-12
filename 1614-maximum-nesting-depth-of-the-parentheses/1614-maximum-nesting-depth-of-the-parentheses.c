int maxDepth(char* s) {
    int depth = 0;
    int ans = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            depth++;

            if (depth > ans)
                ans = depth;
        } else if (s[i] == ')') {
            depth--;
        }
    }

    return ans;
}