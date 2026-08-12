int minOperations(char** logs, int logsSize) {
    int depth = 0;

    for (int i = 0; i < logsSize; i++) {
        if (logs[i][0] == '.' && logs[i][1] == '.') {
            if (depth > 0)
                depth--;
        } else if (logs[i][0] != '.') {
            depth++;
        }
    }

    return depth;
}