int minGenerations(int** points, int pointsSize, int* pointsColSize, int* target, int targetSize) {
    int seen[7][7][7] = {0};
    int list[343][3];
    int count = 0;

    for (int i = 0; i < pointsSize; i++) {
        int x = points[i][0];
        int y = points[i][1];
        int z = points[i][2];

        if (!seen[x][y][z]) {
            seen[x][y][z] = 1;
            list[count][0] = x;
            list[count][1] = y;
            list[count][2] = z;
            count++;
        }

        if (x == target[0] && y == target[1] && z == target[2])
            return 0;
    }

    for (int gen = 1; gen <= 343; gen++) {
        int oldCount = count;
        int newFound = 0;

        for (int i = 0; i < oldCount; i++) {
            for (int j = i + 1; j < oldCount; j++) {
                int x = (list[i][0] + list[j][0]) / 2;
                int y = (list[i][1] + list[j][1]) / 2;
                int z = (list[i][2] + list[j][2]) / 2;

                if (!seen[x][y][z]) {
                    seen[x][y][z] = 1;
                    list[count][0] = x;
                    list[count][1] = y;
                    list[count][2] = z;
                    count++;
                    newFound = 1;

                    if (x == target[0] && y == target[1] && z == target[2])
                        return gen;
                }
            }
        }

        if (!newFound)
            return -1;
    }

    return -1;

}