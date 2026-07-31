int compare_x(const void* a, const void* b) {
    return (*(int**)a)[0] - (*(int**)b)[0];
}

int compare_y(const void* a, const void* b) {
    return (*(int**)a)[1] - (*(int**)b)[1];
}

bool checkCuts(int** rectangles, int rectanglesSize, int dim) {
    int gapCount = 0;
    
    // Dimension-specific bits
    int start;
    switch(dim) {
        case 0:
            qsort(rectangles, rectanglesSize, sizeof(int*), compare_x);
            start = 0;
            break;
        default:
            qsort(rectangles, rectanglesSize, sizeof(int*), compare_y);
            start = 1;
    }
    int end = start + 2;

    // Core loop
    int furthestEnd = rectangles[0][end];
    for (int i = 1; i < rectanglesSize; i++) {
        if (rectangles[i][start] >= furthestEnd) {
            gapCount++;
            // Early return
            if (gapCount > 1) {
                return true;
            }
        }
        furthestEnd = rectangles[i][end] > furthestEnd ? rectangles[i][end] : furthestEnd;
    }
    return false;
}

bool checkValidCuts(int n, int** rectangles, int rectanglesSize, int* rectanglesColSize) {
    // We ignore n, as it does nothing for us other than make
    //  discussing complexity confusing. Since it can be 10^9,
    //  avoiding using it at all is best.

    // Likewise, ignore rectanglesColSize because it's always 4
    return checkCuts(rectangles, rectanglesSize, 0) || checkCuts(rectangles, rectanglesSize, 1);
}