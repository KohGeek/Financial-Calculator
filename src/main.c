#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include "version.h"
#include "core.h"

//global declaration of strings for core.c functions
char* _cmonth[4];
char* _string[120];

//global declaration of number for core.c functions
int _gint;
float _gfloat;
double _gdouble;

//forward declaration of functions
void main_menu(void);
void housing_loan(void);
void income_tax(void);
void bank_interest(void);
void ROI(void);
int car_loan(void);

int main()
{
    int opt;

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
            car_loan();
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
    printf("\n\n\t\t\t\t\t***SIMPLE FINANCIAL CALCULATOR***\n\n");
    printf("\t\t\t 1  Housing Loan\n");
    printf("\t\t\t 2  Car Loan\n");
    printf("\t\t\t 3  Retirement Planning (KWSP)\n");
    printf("\t\t\t 4  Bank Interest Calculator\n");
    printf("\t\t\t 9  Help & About\n");
    printf("\t\t\t 0  Exit\n\n\n");
}

void income_tax(void)
{
    printf("");
}

void housing_loan(void)
{
    int tenure, month, year, cont_exit;
    double cost, loan_amt, pow_func;
    float loan_percnt, interest, installment, monthly_intrst;
    system("cls");

    do
    {
        do
        {
            printf("\n\n\t\t\t\t\t***Housing Loan Calculator***\n\n\n");
            *_string = "\t\tCost of House (RM)\t: \0"; //test implementation of new function
            dchecker(100000000, 1, 2, 0);
            cost = _gfloat;
            //printf("\t\tCost of House (RM)\t: ");
            //scanf("%lf", &cost);
            printf("\n\t\tLoan Percentage (%%)\t: ");
            scanf("%f", &loan_percnt);
            printf("\n\t\tLoan Tenure (Years)\t: ");
            scanf("%d", &tenure);
            printf("\n\t\tInterest Rate (%% P.A)\t: ");
            scanf("%f", &interest);
            do
            {
                printf("\n\t\tFirst installment (yy/mm) : "); //suggestion - break month and date into two scanf, might make validation easy
                scanf("%d/%d", &year, &month);
                rewind(stdin); //Can rewind be used?
                if (month > 12 || month <= 0)
                    printf("\nERROR: Invalid month input. Please try again!\n");
            }
            while (month > 12 || month <= 0);


            //Validation needed for division by zero
            //Koh: Validation can be done on input stage, verify?
            loan_percnt *= 0.01;
            tenure *= 12;
            loan_amt = loan_percnt * cost;
            monthly_intrst = ((interest) / 100) / 12;
            pow_func = pow((1 + monthly_intrst), tenure);
            installment = loan_amt * (monthly_intrst / (1 - (1 / pow_func)));


            printf("\n\t\t**Monthly repayment**\t: RM %.2f\n\n", installment); //Need help for ":" indentation - Koh: \t should have worked?
            printf("\nProceed to full repayment schedue? (1 - Yes ; 0 - No [Recalculate house loan] ) : ");
            scanf("%d", &cont_exit);

        }
        while (cont_exit == 0);

        system("cls");

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

            printf("\n\nChoose any one option to continue? (0 - Calculate another housing loan; 1 - Return to main menu;\n 2 - Exit the program) : ");
            scanf("%d", &cont_exit);

            if(cont_exit == 0)
            {
                system("cls");
            }
            else if (cont_exit == 1)
            {
                system("cls");
            }
            else if (cont_exit == 2)
            {
                exit(0);
            }
            else
            {
                printf("Error!!!\n\n"); //Anyone is welcome to change the error message.
                exit(0);
            }
        }
    }
    while(cont_exit == 0);
}

void bank_interest(void)
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
    printf("\n\t\tKey in the frequency of compounding in a year\t-> ");
    scanf("%d",&freq);

    final_amount = (initial_amount * (pow((1 + rate / 100 / freq),(freq * years)))) + (monthly_deposit * (((pow((1 + rate / 100 / freq),(freq * years))) - 1) / (rate / 100 / freq)));
    printf("\n\t\tFinal savings balance -> RM %.2f\n\n", final_amount);

    printf("\n\t\t\tType of interest:\n\n\t\t\t   1 - Annually\n\t\t\t   2 - Monthly\n\t\t\t   3 - Quarterly\n\t\t\t   4 - Semi-annually\n\nPlease key in your selection -> ");
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
    }

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
}

void ROI (void)
{
    //1- Decalaration
    float amt_invested, amt_returned, investment_time, investment_gain, percentage_return, profit, invested ;

    //2- Input
    printf("Amount Invested :RM");
    scanf("%f", &amt_invested);

    printf("Amount Returned :RM");
    scanf("%f", &amt_returned);

    printf("Investment Length (years):");
    scanf("%f", &investment_time);

    //3- Calculation
    investment_gain = amt_returned - amt_invested;
    percentage_return = ((amt_returned - amt_invested)/amt_invested) * 100;
    profit = (investment_gain / amt_returned) *100;
    invested = (amt_invested/ amt_returned) *100;


    //4- Output
    printf("Investment Gain: RM%.2f \n", investment_gain);
    printf("Return of Investment: %.2f%% \n", percentage_return);
    printf("Percentage of Profit: %.2f%% \n", profit);
    printf("Percentage of Invested: %.2f%% \n", invested);
    printf("Investment Length :%.1f years \n", investment_time);
}

void car_loan(void)
{
    int loan_period, count=0, year, month;
    double price, downpay, interest, payment;
    float rate;
    printf("\n\n\t\t\t\t\t***Car Loan Calculator***\n\n\n");
    printf("\t\tCar Price (RM)\t: ");
    scanf("%lf", &price);
    printf("\n\t\tDownpayment (RM)\t: ");
    scanf("%lf", &downpay);
    printf("\n\t\tLoan Period (Years)\t: ");
    scanf("%d", &loan_period);
    printf("\n\t\tInterest Rate (%% P.A)\t: ");
    scanf("%f", &rate);
    printf("\n\t\tFirst loan payback (mm/yy)\t: "); //suggestion - break month and date into two scanf, might make validation easy
    scanf("%d/%d", &year, &month);
    if (month > 12 || month <= 0)
    {
        printf("\nERROR: Invalid month input. Please try again!");
        printf("\n\n\t\tFirst loan payback (yy/mm) : ");
        scanf("%d/%d", &year, &month);
    }


    payment = (((price - downpay) * (rate / 100) * loan_period) + price) / (loan_period * 12);
    printf("\n\t\t Monthly Repayment (RM)\t %.2lf ", payment);
    printf("\n\nMonthly Installment Schedule\n----------------------------\n");

    double balance = (price + (price * (rate/100) * loan_period)), principal = price;
    {
        printf("\n\n   \t \t\tPayable  \tInterest     \t               \tBalance\n");
        printf("No.\t Date\t\tDue (RM) \tAccrued (RM) \tPrincipal (RM) \tDue (RM)\n");
        printf("------------------------------------------------------------------------------------\n");

        while (count != loan_period * 12)
        {
            count++;
            balance -= payment;
            interest = (price * (rate / 100) * loan_period)/(loan_period * 12);
            principal = payment - interest;
            if (month > 12)
            {
                year++;
                month = 1;
            }
            if (balance < 0)
                balance = 0;
            printf("%3d\t%d/%.2d\t\t%.2f\t\t%7.2f\t\t%9.2lf\t%.2f\n", count, year, month, payment, interest, principal, balance);
            month++;
        }
    }
}
