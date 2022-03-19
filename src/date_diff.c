#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#define MAX_LIMIT 11
#define MAX_YEAR 10000
#define MIN_YEAR 0 

int DEBUG = 0;
int HAS_LEAP_YEAR = 1;

void my_printf( const char* format, ... )
{
    va_list args;
    va_start(args, format);
    if ( DEBUG == 1)
    {
        vprintf(format, args);
    }
    va_end( args );
}

/*struct Date {*/
    /*int a, b, c;*/
/*};*/
/*typedef struct Date Date;*/

typedef struct Date 
{
    int dd, mm, yyyy;
} Date;

int is_legal_date(Date legal_date);
int get_day_diff (Date d1, Date d2);
Date get_input_date();

int  is_leap_year( int year )
{
    return ( year % 4 == 0 );
}


int date_to_day(Date date)
{
    int day_in_month[] =  {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day_in_year = 0;

    int day_from_month = 0;
    int day_from_year = 0;
    int day_only = date.dd;

    int i;
    for ( i = 0; i < 12 ; i++)
    {
        /*my_printf("%d\n", day_in_month[i]);*/
        day_in_year += day_in_month[i];
        /*my_printf("sum: %d\n", day_in_year);*/
    }

    day_from_year = day_in_year * date.yyyy;
    if (HAS_LEAP_YEAR)
    {
        int extra_days  = date.yyyy / 4;
        day_from_year = day_from_year + extra_days;
    }
    for ( i = 0; i < date.mm ; i++)
    {
        day_from_month += day_in_month[i];
    }
    int total_day = day_only + day_from_month + day_from_year;
    /*my_printf("total day: %d\n", total_day);*/
    return total_day;
}

Date get_input_date(char* str_date)
/*INPUT DATE*/
/*Date get_input_date()*/
{
    int dd = 0 , mm = 0 , yyyy = 0;
    my_printf("***************************************************\n");
    /*my_printf("%s\n", str_date);*/
    /*int valid_date = 0;*/
    /*while ( valid_date == 0 )*/
    /*char str_date[MAX_LIMIT] = "";*/

    /*INPUT DATE*/
    /*char str_date[MAX_LIMIT];*/

    int count = 0;
    while (1)
    {
        /*scan input date*/
        my_printf("start loop: %d\n", count);

        /*INPUT DATE*/
        /*fgets(str_date, MAX_LIMIT, stdin);*/

        my_printf("str_date: %s\n", str_date);
        count++;
        if (strstr(str_date, "/"))
        {
            my_printf("found /\n");
            sscanf(str_date,"%d/%d/%d", &dd, &mm, &yyyy);
        }
        else if (strstr(str_date, "-"))
        {
            my_printf("found -\n");
            sscanf(str_date,"%d-%d-%d", &dd, &mm, &yyyy);
        } 
        Date d = {dd, mm, yyyy};

        if (is_legal_date(d))
        {
            my_printf("valid date\n");
            break;
        }
        else 
            printf("else Please input a valid date\n");
    }

    my_printf("day: %d\n", dd);
    my_printf("month: %d\n", mm);
    my_printf("year: %d\n", yyyy);

    Date date = {dd, mm, yyyy};
    return date;
}

int is_legal_date(Date legal_date)
{
    if (legal_date.yyyy > MAX_YEAR || legal_date.yyyy < MIN_YEAR)
        return 0;
    if (legal_date.mm < 1 || legal_date.mm > 12)
        return 0;
    if (legal_date.dd < 1 || legal_date.dd > 31)
        return 0;
    if (legal_date.mm == 2)
    {
        if (HAS_LEAP_YEAR)
        {
            if (is_leap_year(legal_date.yyyy))
                return (legal_date.dd <= 29);
        }
        else
            return (legal_date.dd <= 28);
    }
    if  (
            legal_date.mm == 4 || 
            legal_date.mm == 6 ||
            legal_date.mm == 9 || 
            legal_date.mm == 11
    )
        return (legal_date.dd <= 30);
    return 1;
}


int get_day_diff (Date d1, Date d2)
{
    int day_diff;
    int d1_day = date_to_day(d1);
    my_printf("date1_in_day: %d\n", d1_day);
    int d2_day = date_to_day(d2);
    my_printf("date2_in_day: %d\n", d2_day);
    day_diff = d2_day - d1_day;
    my_printf("Day diff: %d\n", day_diff);
    my_printf("%d %d %d\n", d1.dd, d1.mm, d1.yyyy);
    my_printf("%d %d %d\n", d2.dd, d2.mm, d2.yyyy);
    return day_diff;
}

int main()
{
    char str_date1[MAX_LIMIT];
    char str_date2[MAX_LIMIT];
    /*23/11/1987*/
    /*5-11-1987*/
    strcpy( str_date1, "23/11/2023" );
    strcpy( str_date2, "5-11-2038" );
    printf("Please input a date dd-mm-yyyy \n");


    Date d1 = get_input_date(str_date1);
    /*INPUT DATE*/
    /*Date d1 = get_input_date();*/

    my_printf("-----------------------------------------------\n");
    printf("Please input a date dd-mm-yyyy \n");

    Date d2 = get_input_date(str_date2);
    /*INPUT DATE*/
    /*Date d2 = get_input_date();*/
    
    int day_diff = get_day_diff(d1,d2);
    printf("%d", day_diff);
    return 0;
}
