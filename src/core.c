#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include "core.h"

/** Usage of d/f/ichecker - Please read
 * d - double, f - float, i - integer
 * d/f/ichecker takes in 3 arguments
 *  - maximum: The maximum value that is accepted
 *  - minimum: The minimum value that is accepted
 *  - allowzero: whether zero is an accepted value
 *      0 - no
 *      1 - yes
 *
 * Special case: fchecker accepts another argument, percentage
 * - percentage: whether percentage is used
 *      0 - no
 *      1 - yes
 *
 * This allows for an alternative percentage prompt when value is out of range.
 *
 * (Due to the limitation of standard C library and
 * time constraint, junk values are often treated as 0,
 * thus care has been taken to specifically prompt the
 * user about possible 0 value)
 *
 * To use it in the code, apply this format:
 * *_string = "[insert string here]\0";
 * variable = d/f/ichecker(max,min,allowzero);
 *
 * **/

long ichecker(long max, long min, int allowzero)
{
    char input[40];
    int error = 1;
    long value;
    while(error == 1)
    {
        errno = 0;
        printf("%s(%ld - %ld)\t:",*_string, min, max);
        char s;

        scanf("%40s",input);
        while((s = fgetc(stdin)) != '\n' && s != EOF); //clearing the input buffer in the most predictable manner
        const char* tempstr = input;
        value = strtol(tempstr,NULL,10);

        if(value == 0 && allowzero == 0)
        {
            printf("\nValue detected is 0, possible input error. Please try again.\n\n");
        }
        else if(value == 0)
        {
            printf("\nValue detected is 0, but 0 is allowed. Possible input error?\n\n");
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
    return value;
}

float fchecker(float max, float min, int allowzero, int percentage)
{
    char input[40];
    int error = 1;
    float value;
    while(error == 1)
    {
        errno = 0;
        printf("%s(%.1f - %.1f)\t:",*_string, min, max);
        char s;

        scanf("%40s",input);
        while((s = fgetc(stdin)) != '\n' && s != EOF); //clearing the input buffer in the most predictable manner
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
            printf("\nValue detected is 0, but 0 is allowed. Possible input error?\n\n");
            error = 0;
        }
        else if(errno == ERANGE || value < min || value > max)
        {
            if(percentage == 0)
                printf("\nValue keyed in is out of range, should be between %f and %f, please try again.\n\n", min, max);
            else
                printf("\nValue keyed in is out of range, should be between %f%% and %f%%, please try again.\n\n", min, max);
        }
        else
        {
            error = 0;
        }
    }
    return value;
}

double dchecker(double max, double min, int allowzero)
{
    char input[40];
    int error = 1;
    double value;
    while(error == 1)
    {
        errno = 0;
        printf("%s %.1lf - %.1lf)\t:",*_string, min, max);
        char s;

        scanf("%40s",input);
        while((s = fgetc(stdin)) != '\n' && s != EOF); //clearing the input buffer in the most predictable manner
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
            printf("\nValue detected is 0, but 0 is allowed. Possible input error?\n\n");
            error = 0;
        }
        else if(errno == ERANGE || value < min || value > max)
        {
            printf("\nValue keyed in is out of range, should be between %lf and %lf, please try again.\n\n", min, max);
        }
        else
        {
            error = 0;
        }
    }
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
        *_cmonth = "July\0";
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
