#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include "core.h"

void flush()
{
    char s;
    while((s = fgetc(stdin)) != '\n' && s != EOF); //clearing the input buffer in the most predictable manner
}

/** Usage of d/f/ichecker - Please read
 * d - double, f - float, i - integer
 * d/f/ichecker takes in 4 arguments
 *  - maximum: The maximum value that is accepted
 *  - minimum: The minimum value that is accepted
 *  - allowzero: whether zero is an accepted value
 *      0 - no
 *      1 - yes
 *  - psfix: whether a unit is needed and if it's a suffix or a prefix
 *      0 - not needed
 *      1 - prefix
 *      2 - suffix
 *      3 - suffix with space
 *
 * This allows for an alternative percentage prompt when value is out of range.
 *
 * (Due to the limitation of standard C library and
 * time constraint, junk values are often treated as 0,
 * thus care has been taken to specifically prompt the
 * user about possible 0 value)
 *
 * To use it in the code, apply this format:
 * *_string = "[insert string here]\0"; \0 is needed to end the string properly
 * *_units = "[insert unit here]\0";
 * variable = d/f/ichecker(max,min,allowzero,psfix);
 *
 * **/

long ichecker(long max, long min, int allowzero, int psfix)
{
    char input[40];
    int error = 1;
    long value;
    while(error == 1)
    {
        errno = 0;

        if(psfix == 0)
        {
            printf("%s (%ld - %ld): ",*_string, min, max);
        }
        else if(psfix == 1)
        {
            printf("%s (%s %ld - %ld): ",*_string, *_units, min, max);
        }
        else if(psfix == 2)
        {
            printf("%s (%ld - %ld%s): ",*_string, min, max, *_units);
        }
        else
        {
            printf("%s (%ld - %ld %s): ",*_string, min, max, *_units);
        }


        scanf("%40s",input);
        flush();
        const char* tempstr = input;
        value = strtol(tempstr,NULL,10);

        if(value == 0 && allowzero == 0)
        {
            printf("\nValue detected is 0, possible input error. Please try again.\n\n");
        }
        else if(value == 0)
        {
            printf("\nValue detected is 0, but 0 is allowed. Possible input error?\n");
            error = 0;
        }
        else if(errno == ERANGE || value < min || value > max)
        {
            printf("\nValue keyed in is out of range, should be between %ld and %ld, please try again.\n\n", min, max);
        }
        else
        {
            error = 0;
        }
    }
    printf("\n");
    return value;
}

float fchecker(float max, float min, int allowzero, int psfix)
{
    char input[40];
    int error = 1;
    float value;
    while(error == 1)
    {
        errno = 0;
        if(psfix == 0)
        {
            printf("%s (%.1f - %.1f): ",*_string, min, max);
        }
        else if(psfix == 1)
        {
            printf("%s (%s %.1f - %.1f): ",*_string, *_units, min, max);
        }
        else if(psfix == 2)
        {
            printf("%s (%.1f - %.1f%s): ",*_string, min, max, *_units);
        }
        else
        {
            printf("%s (%.1f - %.1f %s): ",*_string, min, max, *_units);
        }

        scanf("%40s",input);
        flush();
        const char* tempstr = input;
        value = strtof(tempstr,NULL);

        if(value == 0 && allowzero == 0)
        {
            printf("\nValue detected is 0, possible input error. Please try again.\n\n");
        }
        else if(value == NAN || value == INFINITY)
        {
            printf("\nValue is invalid, please try again.\n\n");
        }
        else if(value == 0)
        {
            printf("\nValue detected is 0, but 0 is allowed. Possible input error?\n");
            error = 0;
        }
        else if(errno == ERANGE || value < min || value > max)
        {
            printf("\nValue keyed in is out of range, should be between %.1f and %.1f, please try again.\n\n", min, max);
        }
        else
        {
            error = 0;
        }
    }
    printf("\n");
    return value;
}

double dchecker(double max, double min, int allowzero, int psfix)
{
    char input[40];
    int error = 1;
    double value;
    while(error == 1)
    {
        errno = 0;
        if(psfix == 0)
        {
            printf("%s (%.1lf - %.1lf): ",*_string, min, max);
        }
        else if(psfix == 1)
        {
            printf("%s (%s %.1lf - %.1lf): ",*_string, *_units, min, max);
        }
        else if(psfix == 2)
        {
            printf("%s (%.1lf - %.1lf%s): ",*_string, min, max, *_units);
        }
        else
        {
            printf("%s (%.1lf - %.1lf%s): ",*_string, min, max, *_units);
        }

        scanf("%40s",input);
        flush();
        const char* tempstr = input;
        value = strtod(tempstr, NULL);

        if(value == 0 && allowzero == 0)
        {
            printf("\nValue detected is 0, possible input error. Please try again.\n\n");
        }
        else if(value == NAN || value == INFINITY)
        {
            printf("\nValue is invalid, please try again.\n\n");
        }
        else if(value == 0)
        {
            printf("\nValue detected is 0, but 0 is allowed. Possible input error?\n");
            error = 0;
        }
        else if(errno == ERANGE || value < min || value > max)
        {
            printf("\nValue keyed in is out of range, should be between %.1lf and %.1lf, please try again.\n\n", min, max);
        }
        else
        {
            error = 0;
        }
    }
    printf("\n");
    return value;
}

/** Month_function - README
 * The following function takes in an integer value
 * and returns a global string (_cmonth)
 *
 * This function is to be used in conjunction with
 * dchecker as this code lacks any sort of error
 * checking functionality, thus is all delegated to
 * dchecker.
 **/

void month_function(int nmonth)
{
    switch(nmonth)
    {
    case 1:
        *_cmonth = "Jan\0";
        break;
    case 2:
        *_cmonth = "Feb\0";
        break;
    case 3:
        *_cmonth = "Mac\0";
        break;
    case 4:
        *_cmonth = "Apr\0";
        break;
    case 5:
        *_cmonth = "May\0";
        break;
    case 6:
        *_cmonth = "Jun\0";
        break;
    case 7:
        *_cmonth = "Jul\0";
        break;
    case 8:
        *_cmonth = "Aug\0";
        break;
    case 9:
        *_cmonth = "Sep\0";
        break;
    case 10:
        *_cmonth = "Oct\0";
        break;
    case 11:
        *_cmonth = "Nov\0";
        break;
    case 12:
        *_cmonth = "Dec\0";
        break;
    }
}
