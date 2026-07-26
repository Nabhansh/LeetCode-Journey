int findSpecialInteger(int* arr, int arrSize) {

    int len = arrSize / 4;

    for (int i = 0; i + len < arrSize; i++) {
        if (arr[i] == arr[i + len])
            return arr[i];
    }

    return arr[0];
}