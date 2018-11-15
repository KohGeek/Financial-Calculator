#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <errno.h>
#include <conio.h>
#include "version.h"

char _cmonth[4];
char _string[120];
int _gint;
float _gfloat;
double _gdouble;

void main_menu(void);
void housing_loan(void);
void income_tax(void);
int month_function(int nmonth);
int bank_interest(void);
void dchecker(float max, float min, int type);

int main(void)
{
    int opt;

	system("cls");
    printf("\n\n\t\t\t\t\t***SIMPLE FINANCIAL CALCULATOR***\n\n");

    do
    {
        main_menu();

        printf("Enter an option to continue: ");
        scanf("%d", &opt);

        switch(opt)
        {
        case 0:
            break;
        case 1:
            housing_loan();
            break;
        case 2:
            //car_loan();
            break;
        case 3:
            //KWSP();
            break;
        case 4:
            bank_interest();
            break;
        }
    }
    while (opt != 0);

    return 0;
}

void main_menu(void)
{
    printf("\t\t\t 1  Housing Loan\n");
    printf("\t\t\t 2  Car Loan\n");
    printf("\t\t\t 3  Retirement Planning (KWSP)\n");
    printf("\t\t\t 4  Bank Interest Calculator\n");
    printf("\t\t\t 9  Help & About\n");
    printf("\t\t\t 0  Exit\n\n\n");
}

void income_tax(void)
{

}

int dchecker(double max, double min, int type, bool allowzero)
{
    char *input[40];
    int error = 1;
    while(error == 1){
        printf("%s",_string);
        scanf("%s",&input);
        if(type == 1){ //type 1 = integer
            long value;
            strtol(input, &value,10);
            if(errno == ERANGE || value < min || value > max){
                printf("Value keyed in is out of range, please try again.\n");
            }else if(value == 0 && allowzero == FALSE){
                printf("Value detected is 0, possible input error. Please try again.\n");
            }else if(value == 0){
                printf("Value detected is 0, but 0 is allowed. Possible input error?\n")
                error = 0;
                _gint = value;
            }else{
                error = 0;
                _gint = value;
            }
        }else if(type == 2){ //type 2 = float
            float value;
            strtof(input, &value);
            if(errno == ERANGE || value < min || value > max){
                printf("Value keyed in is out of range, please try again.\n");
            }else if(value == 0 && allowzero == FALSE){
                printf("Value detected is 0, possible input error. Please try again.\n");
            }else if(value == nan || value == inf){
                printf("Value is invalid, please try again.\n");
            }else if(value == 0){
                printf("Value detected is 0, but 0 is allowed. Possible input error?");
                error = 0;
                _gfloat = value;
            }else{
                error = 0;
                _gfloat = value;
            }
        }else if(type == 3){ //type 3 = double
            double value;
            strtod(input, &value);
            if(errno == ERANGE || value < min || value > max){
                printf("Value keyed in is out of range, please try again.\n");
            }else if(value == 0 && allowzero == FALSE){
                printf("Value detected is 0, possible input error. Please try again.\n");
            }else if(value == nan || value == inf){
                printf("Value is invalid, please try again.\n");
            }else if(value == 0){
                printf("Value detected is 0, but 0 is allowed. Possible input error?");
                error = 0;
                _gdouble = value;
            }else{
                error = 0;
                _gdouble = value;
            }
        }else{
            printf("Someone screwed up, check the code.\n");
            return 2;
        }
    }
    return 1;
}

void month_function(int nmonth)
{
    case(nmonth){
        case 1:
            _cmonth = "Jan";
            break;
        case 2:
            _cmonth = "Feb";
            break;
        case 3:
            _cmonth = "Mac";
            break;
        case 4:
            _cmonth = "Apr";
            break;
        case 5:
            _cmonth = "May";
            break;
        case 6:
            _cmonth = "Jun";
            break;
        case 7:
            _cmonth = "July";
            break;
        case 8:
            _cmonth = "Aug";
            break;
        case 9:
            _cmonth = "Sep";
            break;
        case 10:
            _cmonth = "Oct";
            break;
        case 11:
            _cmonth = "Nov";
            break;
        case 12:
            _cmonth = "Dec";
            break;
    }
}

void housing_loan(void) //Date system awaiting to be added
{
    int tenure, month, year;
    double cost, loan_amt, pow_func;
    float loan_percnt, interest, installment, monthly_intrst;
	system("cls");
    printf("\n\n\t\t\t\t\t***Housing Loan Calculator***\n\n\n");
    printf("\t\tCost of House (RM)\t: ");
    scanf("%lf", &cost);
    printf("\n\t\tLoan Percentage (%%)\t: ");
    scanf("%f", &loan_percnt);
    printf("\n\t\tLoan Tenure (Years)\t: ");
    scanf("%d", &tenure);
    printf("\n\t\tInterest Rate (%% P.A)\t: ");
    scanf("%f", &interest);
	printf("\n\t\tFirst loan payback (mm/yy)\t: ");
	scanf("%d/%d", &year, &month);
	if (month > 12)
	{
		printf("\nERROR: Invalid month input. Please try again!");
		printf("\n\n\t\tFirst loan payback (yy/mm) : ");
		scanf("%d/%d", &year, &month);
	}

	//Validation needed for division by zero
    loan_percnt *= 0.01;
    tenure *= 12;
    loan_amt = loan_percnt * cost;
    monthly_intrst = ((interest) / 100) / 12;
    pow_func = pow((1 + monthly_intrst), tenure);
    installment = loan_amt * (monthly_intrst / (1 - (1 / pow_func)));

    int cont_exit;
    printf("\n\t\t**Monthly repayment**\t: RM %.2f\n\n", installment); //Need help for ":" indentation
    printf("\nProceed to full repayment schedue? (1 - Yes ; 0 - No [back to main menu] ) : ");
    scanf("%d", &cont_exit);

    int no = 0;
    double balance = loan_amt, intrst_sum = 0;
    float intrst_accrued, princpl;
    if (cont_exit == 1)
    {
		printf("\n\nLoading...\n\n");
		Sleep(1200);
		system("cls");
        printf("\n\nMonthly Installment Schedule\n----------------------------\n");
        printf("\n\n   \t \t\tPayable  \tInterest      \t Interest \tPrincipal      \tBalance\n");
        printf("No.\t Date\t\tDue (RM) \tAccrued (RM)  \t Sum (RM) \t(RM)           \tDue (RM)\n");
        printf("-------------------------------------------------------------------------------------------------\n");
        while (no != tenure)
        {
            no++;
            intrst_accrued = monthly_intrst * balance;
            princpl = installment - intrst_accrued;
            intrst_sum += intrst_accrued;
            balance -= princpl;
			if (month > 12)
			{
				year++;
				month = 1;
			}
            else if (balance <= 0)
                balance = 0;
			printf("%3d\t%.2d/%d\t\t%.2f\t\t%7.2f\t\t%9.2lf\t%7.2f\t\t%9.2lf\n", no, month, year, installment, intrst_accrued, intrst_sum, princpl, balance);
			month++;
        }
		printf("\n\nChoose any one option to continue? (0 - Exit to main menu; 1 - Calculate another housing loan;\n 2 - Exit the program) : ");
        scanf("%d", &cont_exit);
		if (cont_exit == 0)
		{
			system("cls");
			main();
		}
		else if (cont_exit == 1)
		{
			system("cls");
			housing_loan();
		}
		else if (cont_exit == 2)
			exit(0);
        else
        {
            printf("Error!!!\n\n"); //Anyone is welcome to change the error message.
            exit(0);
        }
    }
    else if (cont_exit == 0)
        main();
    else
    {
        printf("Error!!!\n\n"); //Anyone is welcome to change the error message.
        exit(0);
    }
}

int bank_interest(void)
{
    int years, type, cont_exit, freq;
    float initial_amount, monthly_deposit, annual_interest, final_amount, rate;

    printf("\n\n\t\t\t\t***Bank Interest Calculator***\n\n\n");
    printf("\n\t\tKey in initial amount\t\t\t-> RM ");
    scanf("%f", &initial_amount);
    printf("\n\t\tKey in monthly deposit\t\t\t\t-> RM ");
    scanf("%f", &monthly_deposit);
    printf("\n\t\tKey in rate in percentage\t\t\t-> ");
    scanf("%f", &rate);
    printf("\n\t\tKey in the length of deposit (years)\t\t-> ");
    scanf("%d", &years);
    printf("\n\t\tKey in the frequency of compounding in a year\t-> ")
    scanf("%d",&freq)

    final_amount = (initial_amount * (pow((1 + rate / 100 / freq),(freq * years)))) + (monthly_deposit * (((pow((1 + rate / 100 / freq),(freq * years))) - 1) / (rate / 100 / freq)));
    printf("\n\t\tFinal savings balance -> RM %.2f\n\n", final_amount);

    /**printf("\n\t\t\tType of interest:\n\n\t\t\t   1 - Annually\n\t\t\t   2 - Monthly\n\t\t\t   3 - Quarterly\n\t\t\t   4 - Semi-annually\n\nPlease key in your selection -> ");
    scanf("%d", &type);

    switch(type)
    // [P(1+r/n)^(nt)] + [PMT x (((1+r/n)^(nt)-1)/(r/n))]
    {
    case 1:
        final_amount = (initial_amount * (pow((1 + rate / 100 / 1),(1 * years)))) + (monthly_deposit * (((pow((1 + rate / 100 / 1),(1 * years))) - 1) / (rate / 100 / 1)));
        printf("\n\t\tFinal savings balance -> RM %.2f\n\n", final_amount);
        break;
    case 2:
        final_amount = (initial_amount * (pow((1 + rate / 100 / 12),(12 * years)))) + (monthly_deposit * (((pow((1 + rate / 100 / 12),(12 * years))) - 1) / (rate / 100 / 12))) ;
        printf("\n\t\tFinal savings balance -> RM %.2f\n\n", final_amount);
        break;
    case 3:
        final_amount = (initial_amount * (pow((1 + rate / 100 / 4.0),(4.0* years)))) + (monthly_deposit * (((pow((1 + rate / 100 / 4.0),(4.0 * years))) - 1) / (rate / 100 / 4.0)));
        printf("\n\t\tFinal savings balance -> RM %.2f\n\n", final_amount);
        break;
    case 4:
        final_amount = (initial_amount * (pow((1 + rate / 100 / 2.0),(2.0* years)))) + (monthly_deposit * (((pow((1 + rate / 100 / 2.0),(2.0 * years))) - 1) / (rate / 100 / 4.0)));
        printf("\n\t\tFinal savings balance -> RM %.2f\n\n", final_amount);
        break;
    default :
        printf("\n\t\tPlease enter correct code for type of interest.");
        break;
    }**/

    printf("\n\nEnter '0' to exit to main menu OR '1' to do another calculation. : ");
    scanf("%d", &cont_exit);
    if (cont_exit == 1)
        bank_interest();
    else if (cont_exit == 0)
        main();
    else
    {
        printf("Error!!!\n\n"); //Anyone is welcome to change the error message.
        exit(0);
    }

    return 0;
}
