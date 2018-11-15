#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include "core.h"

int dchecker(double max, double min, int type, int allowzero)
{
    char* input[40];
    int error = 1;
    while(error == 1){
        printf("%s",*_string);
        scanf("%s",input);
        if(type == 1){ //type 1 = integer
            long value;
            value = strtol(input,NULL,10);
            if(value == 0 && allowzero == 0){
                printf("Value detected is 0, possible input error. Please try again.\n\n");
            }else if(value == 0){
                printf("Value detected is 0, but 0 is allowed. Possible input error?\n\n");
                error = 0;
                _gint = value;
            }else if(errno == ERANGE || value < min || value > max){
                printf("Value keyed in is out of range, please try again.\n\n");
            }else{
                error = 0;
                _gint = value;
            }
        }else if(type == 2){ //type 2 = float
            float value;
            value = strtof(input,NULL);
            if(value == 0 && allowzero == 0){
                printf("Value detected is 0, possible input error. Please try again.\n\n");
            }else if(value == NAN || value == INFINITY){
                printf("Value is invalid, please try again.\n\n");
            }else if(value == 0){
                printf("Value detected is 0, but 0 is allowed. Possible input error?\n\n");
                error = 0;
                _gfloat = value;
            }else if(errno == ERANGE || value < min || value > max){
                printf("Value keyed in is out of range, please try again.\n\n");
            }else{
                error = 0;
                _gfloat = value;
            }
        }else if(type == 3){ //type 3 = double
            double value;
            value = strtod(input, NULL);
            if(value == 0 && allowzero == 0){
                printf("Value detected is 0, possible input error. Please try again.\n\n");
            }else if(value == NAN || value == INFINITY){
                printf("Value is invalid, please try again.\n\n");
            }else if(value == 0){
                printf("Value detected is 0, but 0 is allowed. Possible input error?\n\n");
                error = 0;
                _gdouble = value;
            }else if(errno == ERANGE || value < min || value > max){
                printf("Value keyed in is out of range, please try again.\n\n");
            }else{
                error = 0;
                _gdouble = value;
            }
        }else{
            printf("Someone screwed up, check the code.\n\n");
            return 2;
        }
    }
    return 1;
}

void month_function(int nmonth)
{
    switch(nmonth){
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
