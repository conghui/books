#include <stdio.h>
#include <assert.h>

static char daytab[2][13] =
{
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
    int leap;
    int i;

    assert(year >= 0);
    assert(month >= 1 && month <= 12);

    leap = (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
    assert(day <= daytab[leap][month]);

    for (i = 1; i < month; i++)
    {
        day += daytab[leap][i];
    }

    return day;
}


void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int leap;
    int month;

    assert(year >= 0 && yearday >= 0);
    leap = (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);

    for (month = 1; month <= 12 && yearday > daytab[leap][month]; month++)
    {
        yearday -= daytab[leap][month];
    }

    if (month > 12 && yearday > daytab[leap][12])
    {
        *pmonth = -1;
        *pday = -1;
    }
    else
    {
        *pmonth = month;
        *pday = yearday;
    }
}

int main()
{
    return 0;
}
