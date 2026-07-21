#include <stdio.h>

int dayOfYear(char* date) {
    int year, month, day;
    sscanf(date, "%d-%d-%d", &year, &month, &day);

    int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        days[1] = 29;

    int ans = day;

    for (int i = 0; i < month - 1; i++)
        ans += days[i];

    return ans;
}