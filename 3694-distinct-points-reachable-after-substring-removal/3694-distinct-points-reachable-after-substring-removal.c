#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
} Point;

int cmp(const void *a, const void *b)
{
    const Point *p = (const Point *)a;
    const Point *q = (const Point *)b;

    if (p->x != q->x)
        return (p->x > q->x) ? 1 : -1;

    if (p->y != q->y)
        return (p->y > q->y) ? 1 : -1;

    return 0;
}

int distinctPoints(char *s, int k)
{
    int n = strlen(s);

    /*
        Total displacement of the complete string.
    */
    int totalX = 0;
    int totalY = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'U')
            totalY++;
        else if (s[i] == 'D')
            totalY--;
        else if (s[i] == 'L')
            totalX--;
        else if (s[i] == 'R')
            totalX++;
    }

    /*
        Number of possible substrings of length k.
    */
    int count = n - k + 1;

    Point *points = malloc(count * sizeof(Point));

    /*
        Calculate displacement of first window [0 ... k-1].
    */
    int windowX = 0;
    int windowY = 0;

    for (int i = 0; i < k; i++)
    {
        if (s[i] == 'U')
            windowY++;
        else if (s[i] == 'D')
            windowY--;
        else if (s[i] == 'L')
            windowX--;
        else if (s[i] == 'R')
            windowX++;
    }

    /*
        Remove the current window.

        Final position =
            total displacement - removed window displacement
    */
    for (int i = 0; i < count; i++)
    {
        points[i].x = totalX - windowX;
        points[i].y = totalY - windowY;

        /*
            Slide window:
            remove s[i]
            add s[i+k]
        */
        if (i < count - 1)
        {
            if (s[i] == 'U')
                windowY--;
            else if (s[i] == 'D')
                windowY++;
            else if (s[i] == 'L')
                windowX++;
            else if (s[i] == 'R')
                windowX--;

            if (s[i + k] == 'U')
                windowY++;
            else if (s[i + k] == 'D')
                windowY--;
            else if (s[i + k] == 'L')
                windowX--;
            else if (s[i + k] == 'R')
                windowX++;
        }
    }

    /*
        Sort coordinates so duplicates become adjacent.
    */
    qsort(points, count, sizeof(Point), cmp);

    int answer = 1;

    for (int i = 1; i < count; i++)
    {
        if (points[i].x != points[i - 1].x ||
            points[i].y != points[i - 1].y)
        {
            answer++;
        }
    }

    free(points);

    return answer;
}