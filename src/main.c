#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include "version.h"
#include "core.h"

//global declaration of strings for core.c functions
char* _cmonth[4];
char* _string[120];

//forward declaration of functions
void main_menu(void);
void housing_loan(void);
void bank_interest(void);
void ROI(void);
void car_loan(void);

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
            ROI();
            break;
        case 4:
            bank_interest();
            break;
        case 5:
            //KWSP();
            break;
        case 9:
            //help();
            break;
        default:
            printf("Invalid input, please try again.");
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
    printf("\t\t\t 3  Return of Investment (ROI) Calculator\n");
    printf("\t\t\t 4  Bank Interest Calculator\n");
    printf("\t\t\t 5  KWSP Retirement Calculator\n");
    printf("\t\t\t 9  Help & About\n");
    printf("\t\t\t 0  Exit\n\n\n");
}

void housing_loan(void)
{
    int tenure, month, year, cont_exit;
    double cost, loan_amt, pow_func;
    float loan_percnt, interest, installment, monthly_intrst;
    system("cls");

    do
    {
        printf("\n\n\t\t\t\t\t***Housing Loan Calculator***\n\n\n");
        *_string = "\t\tCost of House (RM) \0";
        cost = dchecker(100000000, 1, 0);
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
            rewind(stdin); //Can rewind be used? - Not recommended
            if (month > 12 || month <= 0)
                printf("\nERROR: Invalid month input. Please try again!\n");
        }
        while (month > 12 || month <= 0);

        loan_percnt *= 0.01;
        tenure *= 12;
        loan_amt = loan_percnt * cost;
        monthly_intrst = ((interest) / 100) / 12;
        pow_func = pow((1 + monthly_intrst), tenure);
        installment = loan_amt * (monthly_intrst / (1 - (1 / pow_func)));

        printf("\n\t\t**Monthly repayment**\t: RM %.2f\n\n", installment);
        printf("\nProceed to full repayment schedue? (1 - Yes ; 0 - No [Recalculate house loan] ) : ");
        scanf("%d", &cont_exit);

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
                printf("Error!!!\n\n"); //Anyone is welcome to change the error message. Koh: Make a while loop here
                exit(0);
            }
        }
    }
    while(cont_exit == 0);
}

void bank_interest(void)
{
    int years,cont_exit;
    double initial_amount, final_amount, rate;
    char type;

    printf("Initial amount : RM ");
    scanf("%lf", &initial_amount);
    if(initial_amount > 0)
    {
        printf("\nAnnually interest (Compounded) in %% : ");
        scanf("%lf", &rate);
        if(rate > 0)
        {
            printf("\nNumber of years : ");
            scanf("%d", &years);
            if(years > 0)
            {
                printf("\nType of interest ( M : Monthly Q : Quarterly S : Semiannually A : Annually ) : ");
                getchar();
                scanf("%c", &type);
                switch(type)
                {
                case 'M':
                case 'm':
                    final_amount = (initial_amount * (pow((1.0 + (rate / 100.0 / 12.0)),(12.0 * years))));
                    break;
                case 'Q':
                case 'q':
                    final_amount = (initial_amount * (pow((1.0 + (rate / 100.0 / 4.0)),(4.0 * years))));
                    break;
                case 'S':
                case 's':
                    final_amount = (initial_amount * (pow((1.0 + (rate / 100.0 / 2.0)),(2.0 * years))));
                    break;
                case 'A':
                case 'a':
                    final_amount = (initial_amount * (pow((1.0 + (rate / 100.0)),(years))));
                    break;
                default:
                    printf("Please key in alphabet ( M / Q / S / A ).");
                }
                printf("\nFinal savings balance : RM %.2lf", final_amount);
            }
            else
            {
                printf("Please insert number more than 0.") ;
            }
        }
        else
        {
            printf("\nPlease insert number more than 0.") ;
        }
    }
    else
    {
        printf("\nPlease insert proper value.") ;
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
    //1- Declaration
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
    profit = (investment_gain / amt_returned) * 100;
    invested = (amt_invested/ amt_returned) * 100;


    //4- Output
    printf("Investment Gain: RM%.2f \n", investment_gain);
    printf("Return of Investment: %.2f%% \n", percentage_return);
    printf("Percentage of Profit: %.2f%% \n", profit);
    printf("Percentage of Invested: %.2f%% \n", invested);
    printf("Investment Length :%.1f years \n", investment_time);
}

void car_loan(void)
{
    int loan_period, count = 0, year, month, choice;
    double price, downpay, interest, intrst_sum = 0;
    float rate, payment;
    system("cls");

    do
    {
        printf("\n\n\t\t\t\t\t***Car Loan Calculator***\n\n\n");
        printf("\t\tCar Price (RM)\t\t\t: ");
        scanf("%lf", &price);
        printf("\n\t\tDownpayment (RM)\t\t: ");
        scanf("%lf", &downpay);
        printf("\n\t\tLoan Period (Years)\t\t: ");
        scanf("%d", &loan_period);
        printf("\n\t\tInterest Rate (%% P.A)\t\t: ");
        scanf("%f", &rate);
        do
        {
            {
                printf("\n\t\tFirst loan payback (yy/mm)\t: ");
                scanf("%d/%d", &year, &month);
                rewind(stdin);
                if (month > 12 || month <= 0)
                {
                    printf("\nERROR: Invalid month input. Please try again!\n");
                }
            }
        }
        while (month > 12 || month <= 0);

        payment = (price - downpay) * (1 + (rate / 100) * loan_period) / (loan_period * 12);
        printf("\n\t\tMonthly Repayment (RM)\t\t: %.2f ", payment);
        printf("\n\n\nMonthly Installment Schedule\n----------------------------\n");

        double balance = payment * (loan_period * 12), principal = price;
        printf("\n\n   \t \t\tPayable  \tInterest     \tInterest \t               \t Balance\n");
        printf("No.\t Date\t\tDue (RM) \tAccrued (RM) \tSum      \tPrincipal (RM) \t Due (RM)\n");
        printf("--------------------------------------------------------------------------------------------------\n");

        while (count != loan_period * 12)
        {
            count++;
            balance -= payment;
            interest = ((price - downpay) * (rate / 100) * loan_period) / (loan_period * 12);
            intrst_sum += interest;
            principal = payment - interest;
            if (month > 12)
            {
                year++;
                month = 1;
            }
            if (balance < 0)
                balance = 0;
            printf("%3d\t%d/%.2d\t\t%.2f\t\t%7.2lf\t\t%9.2lf\t%9.2lf\t%9.2lf\n", count, year, month, payment, interest, intrst_sum, principal, balance);
            month++;
        }
        printf("\n\nChoose any one option to continue? (0 - Calculate another car loan; 1 - Return to main menu;\n 2 - Exit the program) : ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            system("cls");
        }
        else if (choice == 1)
        {
            system("cls");
        }
        else if (choice == 2)
        {
            exit(0);
        }
        else
        {
            printf("Error!!!\n\n"); //Anyone is welcome to change the error message.
            exit(0);
        }
    }
    while (choice == 0);
}
