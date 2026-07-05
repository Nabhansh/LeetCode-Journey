bool rotateString(char* s, char* goal) {
    int n = strlen(s);

    if (n != (int)strlen(goal))
        return false;

    char *temp = (char *)malloc(2 * n + 1);
    strcpy(temp, s);
    strcat(temp, s);

    bool res = strstr(temp, goal) != NULL;
    free(temp);

    return res;
}