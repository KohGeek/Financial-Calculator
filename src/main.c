#include <stdio.h>
#include <stdlib.h>
#include "version.h"

void main_menu(void);
void housing_loan(void);

int main(void)
{
    int opt;

    printf("\t\t\t\t\t***SIMPLE FINANCIAL CALCULATOR***\n\n");

    do
    {
        main_menu();

        printf("Enter a option to continue: ");
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
    printf(" 1  Housing Loan\n");
    printf(" 2  Car Loan\n");
    printf(" 3  Retirement Planning (KWSP)\n");
    printf(" 4  (To be volunteered)\n");
    printf(" 9  Help & About\n");
    printf(" 0  Exit\n\n\n");
}

void housing_loan(void)
{
    int tenure;
    double cost, loan_amt, balance;
    float downpay, loan_percnt, interest, installment;
    printf("\t\t\t\t\t***Housing Loan Calculator***\n\n\n");
    printf("\t\tCost of House (RM): ");
    scanf("%lf", &cost);
    printf("\n\t\tLoan Percentage (%%): ");
    scanf("%f", &loan_percnt);
    printf("\n\t\tLoan Tenure (Years): ");
    scanf("%d", &tenure);
    printf("\n\t\tInterest Rate (%% P.A): ");
    scanf("%f", &interest);

    //Need help in data truncation for higher accuracy calculation
    loan_percnt *= 0.01;
    interest *= 0.01;
    loan_amt = loan_percnt * cost;
    //installment = loan_amt * interest * tenure / (12 * tenure);
    installment = loan_amt * (1 + interest) / (tenure * 12);

    printf("\n\t\t**Monthly repayment** : RM %.2f\n\n", installment);
}
