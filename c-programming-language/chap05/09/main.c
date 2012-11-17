#include <stdio.h>

static char daytab[2][13] =
{
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

size_t day_of_year(int year, int month, int day)
{
    char *p;
    char (*parr)[13] = daytab;

    if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0)) {
        parr++;
    }

    for (p = *parr; month > 0; month--) {
        day += *++p;
    }

    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    char *p;
    int month;

    if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0)) {
        p = *(daytab + 1);
    }
    else {
        p = *daytab;
    }

    for (month = 1; yearday > *++p; month++) {
        yearday -= *p;
    }

    *pmonth = month;
    *pday = yearday;
}

int main(void)
{
    return 0;
}
