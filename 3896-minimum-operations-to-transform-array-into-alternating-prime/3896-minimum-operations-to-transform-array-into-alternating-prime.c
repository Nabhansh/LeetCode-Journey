#define MAX_PRIME_PLUS_ONE 100004
#define WORD_SIZE 64
#define WORD_TYPE uint64_t
#define WORD_BASE_UNIT 1llu
#define MAX_BUFFER_REQ (2 * MAX_PRIME_PLUS_ONE / WORD_SIZE + 1)

WORD_TYPE isPrimeMemo[MAX_BUFFER_REQ] = {0};

inline int getIsCheckedStatus(int num) {
    int blockIdx = (num * 2) / WORD_SIZE;
    // using lower-bit for isChecked status
    // using higher-bit for isPrimeNum status
    int lowBitPosn = (num * 2) % WORD_SIZE;
    int highBitPosn = lowBitPosn + 1;

    return (isPrimeMemo[blockIdx] >> lowBitPosn) & WORD_BASE_UNIT;
}

inline void setIsPrimeStatus(int num, int isP) {
    int blockIdx = (num * 2) / WORD_SIZE;
    int lowBitPosn = (num * 2) % WORD_SIZE;
    int highBitPosn = lowBitPosn + 1;

    isPrimeMemo[blockIdx] |= (WORD_BASE_UNIT << lowBitPosn);
    if (isP)
        isPrimeMemo[blockIdx] |= (WORD_BASE_UNIT << highBitPosn);
}

inline int getIsPrimeStatus(int num) {
    int blockIdx = (num * 2) / WORD_SIZE;
    int lowBitPosn = (num * 2) % WORD_SIZE;
    int highBitPosn = lowBitPosn + 1;

    return (isPrimeMemo[blockIdx] >> highBitPosn) & WORD_BASE_UNIT;
}

inline int isPrime(int num) {
    if (num < 2)
        return 0;

    if (getIsCheckedStatus(num))
        return getIsPrimeStatus(num);

    for (int j = 2; j * j <= num; ++j) {
        if (num % j == 0) {
            setIsPrimeStatus(num, 0);
            return 0;
        }
    }
    setIsPrimeStatus(num, 1);
    return 1;
}

int minOperations(int* nums, int numsSize) {
    int n = numsSize;
    int cost = 0;

    // even idxs
    for (int i = 0; i < n; i += 2) {
        int num = nums[i];
        while (!isPrime(num)) {
            ++cost;
            ++num;
        }
    }

    // odd idxs
    for (int i = 1; i < n; i += 2) {
        int num = nums[i];
        if (isPrime(num)) {
            if (num == 2)
                cost += 2;
            else
                ++cost;
        }
    }

    return cost;
}