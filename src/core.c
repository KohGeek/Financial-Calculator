#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "core.h"

/** flush()
 *
 * flush() is used to clear input buffer in a safe and clean manner
 * by looping through the input buffer. Additional value can be returned
 * to help validate
 *
**/

int flush()
{
    int hasextra = 0;
    char s;
    while((s = fgetc(stdin)) != '\n' && s != EOF)
        hasextra = 1;
    return hasextra;
}

/** Usage of d/f/ichecker - Please read
 *
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
 * To use it in the code, apply this format:
 * *_string = "[insert string here]\0"; (\0 is needed to end the string properly)
 * *_units = "[insert unit here]\0";
 * variable = d/f/ichecker(max,min,allowzero,psfix);
 *
 * **/

long ichecker(long max, long min, int allowzero, int psfix)
{
    char input[20];
    int error = 1, haschar, hasdecimal;
    long value;
    while(error == 1)
    {
        errno = 0;
        hasdecimal = haschar = 0;

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


        scanf("%20s",input);
        flush();

        char tempstr[20];
        int length;
        strncpy(tempstr,input,20);
        if(strlen(tempstr) <= 20)
        {
            length = strlen(tempstr);
        }
        else
        {
            length = 20;
        }

        for(int i = 0; i < length; i++)
        {
            if(isdigit(tempstr[i]) == 0)
            {
                if(i != 0 && tempstr[i] == '.' && hasdecimal == 0)
                {
                    hasdecimal = 1;
                    continue;
                }
                else if(i == 0 && (tempstr[i] == '+' || tempstr[i] == '-'))
                    continue;
                haschar = 1;
                break;
            }
        }

        if(haschar == 0)
        {
            value = strtol(tempstr,NULL,10);

            if(value == 0 && allowzero == 0)
            {
                printf("\nValue detected is 0 and invalid. Please try again.\n\n");
            }
            else if(value == 0)
            {
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
        else
        {
            printf("\nCharacter detected, try inputting only numerical values.\n\n");
        }
    }
    printf("\n");
    return value;
}

float fchecker(float max, float min, int allowzero, int psfix)
{
    char input[20];
    int error = 1, haschar, hasdecimal;
    float value;
    while(error == 1)
    {
        errno = 0;
        hasdecimal = haschar = 0;

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

        scanf("%20s",input);
        flush();

        char tempstr[20];
        int length;
        strncpy(tempstr,input,20);
        if(strlen(tempstr) <= 20)
        {
            length = strlen(tempstr);
        }
        else
        {
            length = 20;
        }

        for(int i = 0; i < length; i++)
        {
            if(isdigit(tempstr[i]) == 0)
            {
                if(i != 0 && tempstr[i] == '.' && hasdecimal == 0)
                {
                    hasdecimal = 1;
                    continue;
                }
                else if(i == 0 && (tempstr[i] == '+' || tempstr[i] == '-'))
                    continue;
                haschar = 1;
                break;
            }
        }

        if(haschar == 0)
        {
            value = strtof(tempstr,NULL);

            if(value == 0 && allowzero == 0)
            {
                printf("\nValue detected is 0 and invalid. Please try again.\n\n");
            }
            else if(value == NAN || value == INFINITY)
            {
                printf("\nValue is invalid, please try again.\n\n");
            }
            else if(value == 0)
            {
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
        else
        {
            printf("\nCharacter detected, try inputting only numerical values.\n\n");
        }
    }
    printf("\n");
    return value;
}

double dchecker(double max, double min, int allowzero, int psfix)
{
    char input[20];
    int error = 1, haschar, hasdecimal;
    double value;
    while(error == 1)
    {
        errno = 0;
        hasdecimal = haschar = 0;

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

        scanf("%20s",input);
        flush();

        char tempstr[20];
        int length;
        strncpy(tempstr,input,20);
        if(strlen(tempstr) <= 20)
        {
            length = strlen(tempstr);
        }
        else
        {
            length = 20;
        }

        for(int i = 0; i < length; i++)
        {
            if(isdigit(tempstr[i]) == 0)
            {
                if(i != 0 && tempstr[i] == '.' && hasdecimal == 0)
                {
                    hasdecimal = 1;
                    continue;
                }
                else if(i == 0 && (tempstr[i] == '+' || tempstr[i] == '-'))
                    continue;
                haschar = 1;
                break;
            }
        }

        if(haschar == 0)
        {
            value = strtod(tempstr, NULL);

            if(value == 0 && allowzero == 0)
            {
                printf("\nValue detected is 0 and invalid. Please try again.\n\n");
            }
            else if(value == NAN || value == INFINITY)
            {
                printf("\nValue is invalid, please try again.\n\n");
            }
            else if(value == 0)
            {
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
        else
        {
            printf("\nCharacter detected, try inputting only numerical values.\n\n");
        }
    }
    printf("\n");
    return value;
}

/** Month_function - README
 *
 * The following function takes in an integer value
 * and returns a global string (_cmonth)
 *
 * This code lacks any sort of error checking functionality,
 * thus data should be sanitised before using this function.
 *
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
    default:
        return;
    }
}
