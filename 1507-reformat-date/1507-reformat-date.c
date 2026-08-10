#include <stdio.h>
#include <string.h>

char* reformatDate(char* date)
{
    static char result[11];

    char day[5];
    char month[4];
    char year[5];

    sscanf(date, "%s %s %s", day, month, year);

    int dayNum = 0;

    sscanf(day, "%d", &dayNum);

    int monthNum;

    if (strcmp(month, "Jan") == 0)
        monthNum = 1;
    else if (strcmp(month, "Feb") == 0)
        monthNum = 2;
    else if (strcmp(month, "Mar") == 0)
        monthNum = 3;
    else if (strcmp(month, "Apr") == 0)
        monthNum = 4;
    else if (strcmp(month, "May") == 0)
        monthNum = 5;
    else if (strcmp(month, "Jun") == 0)
        monthNum = 6;
    else if (strcmp(month, "Jul") == 0)
        monthNum = 7;
    else if (strcmp(month, "Aug") == 0)
        monthNum = 8;
    else if (strcmp(month, "Sep") == 0)
        monthNum = 9;
    else if (strcmp(month, "Oct") == 0)
        monthNum = 10;
    else if (strcmp(month, "Nov") == 0)
        monthNum = 11;
    else
        monthNum = 12;

    sprintf(result, "%s-%02d-%02d",
            year, monthNum, dayNum);

    return result;
}