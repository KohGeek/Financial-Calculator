#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "version.h"

void main_menu(void);
void housing_loan(void);

int main(void)
{
    int opt;

    printf("\n\n\t\t\t\t\t***SIMPLE FINANCIAL CALCULATOR***\n\n");

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
    printf("\t\t\t 1  Housing Loan\n");
    printf("\t\t\t 2  Car Loan\n");
    printf("\t\t\t 3  Retirement Planning (KWSP)\n");
    printf("\t\t\t 4  (To be volunteered)\n");
    printf("\t\t\t 9  Help & About\n");
    printf("\t\t\t 0  Exit\n\n\n");
}

void housing_loan(void) //Date system awaiting to be added
{
	int tenure;
	double cost, loan_amt, pow_func;
	float loan_percnt, interest, installment, monthly_intrst;
	printf("\n\n\t\t\t\t\t***Housing Loan Calculator***\n\n\n"); //Pls help for the semi-colon indentation...
	printf("\t\tCost of House (RM)      : ");
	scanf("%lf", &cost);
	printf("\n\t\tLoan Percentage (%%)     : ");
	scanf("%f", &loan_percnt);
	printf("\n\t\tLoan Tenure (Years)     : ");
	scanf("%d", &tenure);
	printf("\n\t\tInterest Rate (%% P.A)   : ");
	scanf("%f", &interest);

	//Need help in data truncation for higher accuracy calculation
	loan_percnt *= 0.01;
	tenure *= 12;
	loan_amt = loan_percnt * cost;
	monthly_intrst = ((interest) / 100) / 12;
	//installment = loan_amt * interest * tenure / (12 * tenure);
	pow_func = pow((1 + monthly_intrst), tenure);
	installment = loan_amt * (monthly_intrst / (1 - (1 / pow_func)));

	int cont_exit;
	printf("\n\t\t**Monthly repayment**   : RM %.2f\n\n", installment); //Need help for ":" indentation
	printf("\nProceed to full repayment schedue? (1 - Yes ; 0 - No [back to main menu] ) : ");
	scanf("%d", &cont_exit);
	printf("\n\nLoading...\n\n");

	int no = 0;
	double balance = loan_amt, intrst_sum = 0;
	float intrst_accrued, princpl;
	if (cont_exit == 1) {
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
			if (balance <= 0)
				balance = 0;
			printf("%3d\t    \t\t%.2f\t\t%7.2f\t\t%9.2lf\t%7.2f\t\t%9.2lf\n", no, installment, intrst_accrued, intrst_sum, princpl, balance);
		}
		printf("\n\nEnter '0' to exit to main menu OR '1' to calculate another housing loan. : ");
		scanf("%d", &cont_exit);
		if (cont_exit == 1)
			housing_loan();
		else if (cont_exit == 0)
			main();
		else {
			printf("Error!!!\n\n"); //Anyone is welcome to change the error message.
			exit(0);
		}
	}
	else if (cont_exit == 0)
		main();
	else {
		printf("Error!!!\n\n"); //Anyone is welcome to change the error message.
		exit(0);
	}
}
