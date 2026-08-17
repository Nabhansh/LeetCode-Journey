#include <stdlib.h>

typedef struct {
    int *times;
    long long *prefix;
    int size;
    int capacity;
} ExamTracker;

ExamTracker* examTrackerCreate()
{
    ExamTracker* obj = malloc(sizeof(ExamTracker));

    obj->capacity = 1000;
    obj->size = 0;

    obj->times = malloc(sizeof(int) * obj->capacity);
    obj->prefix = malloc(sizeof(long long) * obj->capacity);

    return obj;
}

void examTrackerRecord(ExamTracker* obj, int time, int score)
{
    if (obj->size == obj->capacity)
    {
        obj->capacity *= 2;

        obj->times = realloc(
            obj->times,
            sizeof(int) * obj->capacity
        );

        obj->prefix = realloc(
            obj->prefix,
            sizeof(long long) * obj->capacity
        );
    }

    obj->times[obj->size] = time;

    if (obj->size == 0)
        obj->prefix[obj->size] = score;
    else
        obj->prefix[obj->size] =
            obj->prefix[obj->size - 1] + score;

    obj->size++;
}

int lowerBound(int* arr, int n, int target)
{
    int left = 0;
    int right = n;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

long long examTrackerTotalScore(
    ExamTracker* obj,
    int startTime,
    int endTime)
{
    int left = lowerBound(
        obj->times,
        obj->size,
        startTime
    );

    int right = lowerBound(
        obj->times,
        obj->size,
        endTime + 1
    );

    long long result = 0;

    if (right > 0)
        result = obj->prefix[right - 1];

    if (left > 0)
        result -= obj->prefix[left - 1];

    return result;
}

void examTrackerFree(ExamTracker* obj)
{
    free(obj->times);
    free(obj->prefix);
    free(obj);
}