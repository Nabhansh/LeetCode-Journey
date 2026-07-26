int* replaceElements(int* arr, int arrSize, int* returnSize) {

    *returnSize = arrSize;

    int maxRight = -1;

    for (int i = arrSize - 1; i >= 0; i--) {
        int temp = arr[i];
        arr[i] = maxRight;
        if (temp > maxRight)
            maxRight = temp;
    }

    return arr;
}