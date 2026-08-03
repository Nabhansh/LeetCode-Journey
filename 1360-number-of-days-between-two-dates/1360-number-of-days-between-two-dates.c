#include <stdlib.h>

static int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

static int leap(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

static int totalDays(char *date) {
    int y, m, d;
    sscanf(date, "%d-%d-%d", &y, &m, &d);

    int days = 0;

    for (int year = 1971; year < y; year++)
        days += leap(year) ? 366 : 365;

    for (int month = 1; month < m; month++) {
        days += daysInMonth[month - 1];
        if (month == 2 && leap(y))
            days++;
    }

    return days + d;
}

int daysBetweenDates(char *date1, char *date2) {
    int a = totalDays(date1);
    int b = totalDays(date2);
    return abs(a - b);
}