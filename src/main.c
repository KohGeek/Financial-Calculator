#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include "version.h"
#include <conio.h> //Is this allowed?

//char _cmonth[4] = '';

void main_menu(void);
void housing_loan(void);
void income_tax(void);
int month_function(void);
int bank_interest(void);

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
            exit(0);
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
    printf("\t\t\t 4  (To be volunteered)\n");
    printf("\t\t\t 9  Help & About\n");
    printf("\t\t\t 0  Exit\n\n\n");
}

void income_tax(void){

}

int month_function(int _nmonth)
{
    return 0;
}

void housing_loan(void) //Date system awaiting to be added
{
    int tenure, month, year;
    double cost, loan_amt, pow_func;
    float loan_percnt, interest, installment, monthly_intrst;
	system("cls");
    printf("\n\n\t\t\t\t\t***Housing Loan Calculator***\n\n\n"); //Pls help for the semi-colon indentation...
	printf("\t\tCost of House (RM)         : ");
	scanf("%lf", &cost);
	printf("\n\t\tLoan Percentage (%%)        : ");
	scanf("%f", &loan_percnt);
	printf("\n\t\tLoan Tenure (Years)        : ");
	scanf("%d", &tenure);
	printf("\n\t\tInterest Rate (%% P.A)      : ");
	scanf("%f", &interest);
	printf("\n\t\tFirst loan payback (mm/yy) : ");
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
    int years ;
    float initial_amount , monthly_deposit , annual_interest , final_amount , rate ;
    char type ;

    printf("\nChoose type of interest   A : Annually\n                          M : Monthly\n                          Q : Quarterly\n                          S : Semiannually\n-> ") ;
    scanf("%c" , &type) ;
    printf("Key in initial amount           -> RM ") ;
    scanf("%f" , &initial_amount) ;
    printf("\nKey in monthly deposit        -> RM ") ;
    scanf("%f" , &monthly_deposit) ;
    printf("\nKey in rate in %%-> RM ") ;
    scanf("%f" , &rate) ;
    printf("\nKey in years -> ") ;
    scanf("%d" , &years) ;

    switch(type)
    // [P(1+r/n)^(nt)] + [PMT x (((1+r/n)^(nt)-1)/(r/n))]
    {
        case 'A' :
        case 'a' :
            final_amount = (initial_amount * (pow((1 + rate / 100 / 1),(1 * years)))) + (monthly_deposit * (((pow((1 + rate / 100 / 1),(1 * years))) - 1) / (rate / 100 / 1))) ;
            printf("Final savings balance -> RM %.2f" , final_amount) ;
            break ;
        case 'M' :
        case 'm' :
            final_amount = (initial_amount * (pow((1 + rate / 100 / 12),(12 * years)))) + (monthly_deposit * (((pow((1 + rate / 100 / 12),(12 * years))) - 1) / (rate / 100 / 12))) ;
            printf("Final savings balance -> RM %.2f" , final_amount) ;
            break ;
        case 'Q' :
        case 'q' :
            final_amount = (initial_amount * (pow((1 + rate / 100 / 4.0),(4.0* years)))) + (monthly_deposit * (((pow((1 + rate / 100 / 4.0),(4.0 * years))) - 1) / (rate / 100 / 4.0))) ;
            printf("Final savings balance -> RM %.2f" , final_amount) ;
            break ;
        case 'S' :
        case 's' :
            final_amount = (initial_amount * (pow((1 + rate / 100 / 4.0),(4.0* years)))) + (monthly_deposit * (((pow((1 + rate / 100 / 4.0),(4.0 * years))) - 1) / (rate / 100 / 4.0))) ;
            printf("Final savings balance -> RM %.2f" , final_amount) ;
            break ;
        default :
            printf("Please enter correct code for type of interest.") ;
            break ;

    }

    return 0 ;
}
