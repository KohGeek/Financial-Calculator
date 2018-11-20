#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include "version.h"
#include "core.h"

//global declaration of strings for core.c functions
char* _cmonth[4];
char* _string[120];
char* _units[10];

//forward declaration of functions
void main_menu(void);
void housing_loan(void);
void bank_interest(void);
void ROI(void);
void car_loan(void);
void EPF(void);

int main(void)
{
    int opt;

    do
    {
        main_menu();

        printf("Enter an option to continue: ");
        scanf("%d", &opt);
        flush();

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
            EPF();
            break;
        case 9:
            //help();
            break;
        default:
            system("cls");
            printf("Invalid input, please try again.");
        }
    }
    while (opt != 0);

    return 0;
}

void main_menu(void)
{
    printf("\n\n\t\t\t\t\t***SIMPLE FINANCIAL CALCULATOR***\n\n");
    printf("\t\t\t 1  Housing Loan Calculator\n");
    printf("\t\t\t 2  Car Loan Calculator\n");
    printf("\t\t\t 3  Return of Investment (ROI) Calculator\n");
    printf("\t\t\t 4  Bank Interest Calculator\n");
    printf("\t\t\t 5  EPF Retirement Calculator\n\n");
    printf("\t\t\t 9  Help & About\n");
    printf("\t\t\t 0  Exit\n\n\n");
}

void housing_loan(void)
{
    int tenure, month, year, cont_exit = 2;
    double cost, loan_amt, pow_func;
    float loan_prcnt, intrst_rate, installment, monthly_intrst;
    system("cls");

    do
    {
        printf("\n\n\t\t\t\t\t***Housing Loan Calculator***\n\n\n");
        *_string = "\t\tCost of House\0";
        *_units = "RM\0";
        cost = dchecker(100000000,1,0,1);

        *_string = "\t\tLoan Percentage\0";
        *_units = "%\0";
        loan_prcnt = fchecker(100.00,1.00,0,2);

        *_string = ("\t\tLoan Tenure\0");
        *_units = "Years\0";
        tenure = ichecker(35,20,0,3);

        *_string = "\t\tInterest Rate\0";
        *_units = "% P.A.\0";
        intrst_rate = fchecker(10,2,0,2);

        *_string = "\t\tFirst installment\0";
        *_units = "Year\0";
        year = ichecker(2200,1918,0,1);

        *_string = "\t\tFirst installment\0";
        *_units = "Month\0";
        month = ichecker(12,1,0,1);

        loan_prcnt *= 0.01;
        tenure *= 12;
        loan_amt = loan_prcnt * cost;
        monthly_intrst = ((intrst_rate) / 100) / 12;
        pow_func = pow((1 + monthly_intrst), tenure);
        installment = loan_amt * (monthly_intrst / (1 - (1 / pow_func)));


        printf("\n\t\t**Monthly repayment**\t: RM %.2f\n\n", installment);

        do
        {
            printf("\nChoose any one option to continue? (0 - Calculate again; 1 - Display full repayment schedule;\n 2 - Exit to main menu; 3 - Exit program) : ");
            scanf("%d", &cont_exit);
            flush();
            if(cont_exit == 3)
            {
                exit(0);
            }
            else if(cont_exit == 2)
            {
                system("cls");
                return;
            }
            else if(cont_exit != 1 && cont_exit != 0)
            {
                printf("\nInvalid option, please try again.\n");
            }
        }
        while(cont_exit != 1 && cont_exit != 0);


        system("cls");

        if (cont_exit == 1)
        {
            int no = 0;
            double balance = loan_amt, intrst_sum = 0;
            float intrst_accrued, princpl;
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
                month_function(month);
                printf("%3d\t%s %d\t%.2f\t\t%7.2f\t\t%9.2lf\t%7.2f\t\t%9.2lf\n", no, *_cmonth, year, installment, intrst_accrued, intrst_sum, princpl, balance);
                month++;
            }

            do
            {
                printf("\n\nChoose any one option to continue? (0 - Calculate again; 1 - Return to main menu;\n 2 - Exit the program) : ");
                scanf("%d", &cont_exit);
                flush();
                if (cont_exit == 1)
                    system("cls");
                else if (cont_exit == 0)
                    system("cls");
                else if (cont_exit == 2)
                    exit(0);
                else
                    printf("\nInvalid option, please try again.");
            }
            while(cont_exit != 0 && cont_exit != 1);
        }
    }
    while(cont_exit == 0);
}

void bank_interest(void)
{
    int years, cont_exit = 0;
    double initial_amount, final_amount, rate, freq;
    char type;
    system("cls");

    do
    {
        printf("\n\n\t\t\t\t\t***Fixed Deposit Interest Calculator***\n\n\n");

        *_string = "\t\tInitial amount\0";
        *_units = "RM\0";
        initial_amount = dchecker(100000000,1,0,1);

        *_string = "\t\tAnnual interest (Compounded)\0";
        *_units = "%\0";
        rate = dchecker(10,1,0,2);

        *_string = "\t\tNumber of years";
        years = ichecker(100,1,0,0);

        int error = 0;
        do
        {
            printf("\n\t\t\tType of interest:\n\n");
            printf("\t\t\tM - Monthly\n\t\t\tQ - Quarterly\n\t\t\tS - Semi-Annually\n\t\t\tA - Annually\n");
            printf("\n\t\t\tSelect : ");
            scanf("%c", &type);
            flush();
            switch(type)
            {
            case 'M':
            case 'm':
                freq = 12.0;
                error = 1;
                break;
            case 'Q':
            case 'q':
                freq = 4.0;
                error = 1;
                break;
            case 'S':
            case 's':
                freq = 2.0;
                error = 1;
                break;
            case 'A':
            case 'a':
                freq = 1.0;
                error = 1;
                break;
            default:
                printf("\nPlease key in alphabet ( M / Q / S / A ).\n");
            }
        }
        while(error != 1);

        final_amount = (initial_amount * (pow((1.0 + (rate / 100.0 / freq)),(freq * years))));
        printf("\n\t\tFinal savings balance : RM %.2lf", final_amount);

        do
        {
            printf("\n\nChoose any one option to continue? (0 - Calculate again; 1 - Return to main menu;\n 2 - Exit the program) : ");
            scanf("%d", &cont_exit);
            flush();
            if (cont_exit == 1)
                system("cls");
            else if (cont_exit == 0)
                system("cls");
            else if (cont_exit == 2)
                exit(0);
            else
                printf("\nInvalid option, please try again.");
        }
        while(cont_exit != 0 && cont_exit != 1);
    }
    while(cont_exit == 0);
}

void ROI(void)
{
    //1- Declaration
    float amt_invested, amt_returned, investment_time, investment_gain, percentage_return, annualROI;
    int cont_exit = 0;
    system("cls");

    //2- Input
    do
    {
        printf("\n\n\t\t\t\t\t***Return of Investment Calculator***\n\n\n");

        *_string = "\t\tInitial amount invested\0";
        *_units = "RM\0";
        amt_invested = fchecker(10000000,1,0,1);

        *_string = "\t\tTotal amount returned\0";
        *_units = "RM\0";
        amt_returned = fchecker(100000000,1,0,1);

        *_string = "\t\tInvestment length";
        *_units = "years\0";
        investment_time = ichecker(100,1,0,3);

        //3- Calculation
        investment_gain = amt_returned - amt_invested;
        percentage_return = ((amt_returned - amt_invested) / amt_invested) * 100;
        annualROI = (pow((1 + percentage_return/100),(1/investment_time)) - 1) * 100;

        //4- Output
        printf("\n\n\n\t\tInvestment Gain: RM%.2f \n\n", investment_gain);
        printf("\t\tReturn of Investment: %.2f%% \n\n", percentage_return);
        printf("\t\tAnnualised ROI: %.2f%% \n", annualROI);

        //5 - Options
        do
        {
            printf("\n\nChoose any one option to continue? (0 - Calculate again; 1 - Return to main menu;\n 2 - Exit the program) : ");
            scanf("%d", &cont_exit);
            flush();
            if (cont_exit == 1)
                system("cls");
            else if (cont_exit == 0)
                system("cls");
            else if (cont_exit == 2)
                exit(0);
            else
                printf("\nInvalid option, please try again.");
        }
        while(cont_exit != 0 && cont_exit != 1);
    }
    while(cont_exit == 0);
}

void car_loan(void)
{
    int loan_period, count = 0, year, month, cont_exit = 0;
    double price, downpay, interest, intrst_sum = 0;
    float rate, payment;
    system("cls");

    do
    {
        printf("\n\n\t\t\t\t\t***Car Loan Calculator***\n\n\n");

        *_string = "\t\tCar Price\0";
        *_units = "RM\0";
        price = dchecker(100000000,10000,0,1);

        *_string = "\t\tDown Payment\0";
        downpay = dchecker(price - 1,0,1,1);

        *_string = ("\t\tLoan Tenure\0");
        *_units = "Years\0";
        loan_period = ichecker(9,3,0,3);

        *_string = "\t\tInterest Rate\0";
        *_units = "% P.A.\0";
        rate = fchecker(10,1,0,2);

        *_string = "\t\tFirst installment\0";
        *_units = "Year\0";
        year = ichecker(2200,1918,0,1);

        *_string = "\t\tFirst installment\0";
        *_units = "Month\0";
        month = ichecker(12,1,0,1);

        payment = (price - downpay) * (1 + (rate / 100) * loan_period) / (loan_period * 12);
        printf("\n\t\tMonthly Repayment (RM)\t\t: %.2f ", payment);
        printf("\n\n\n\t\t\t\tMonthly Installment Schedule\n\t\t\t\t----------------------------\n");

        double balance = payment * (loan_period * 12), principal = price;
        printf("\n\n   \t \t\tPayable   \tInterest     \tInterest \t               \t Balance\n");
        printf("No.\t Date\t\tDue (RM)  \tAccrued (RM) \tSum (RM) \tPrincipal (RM) \t Due (RM)\n");
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
            month_function(month);
            printf("%3d\t%s %d\t%7.2f   \t%7.2lf  \t%9.2lf\t%9.2lf\t%9.2lf\n", count, *_cmonth, year, payment, interest, intrst_sum, principal, balance);
            month++;
        }

        do
        {
            printf("\n\nChoose any one option to continue? (0 - Calculate again; 1 - Return to main menu;\n 2 - Exit the program) : ");
            scanf("%d", &cont_exit);
            flush();
            if (cont_exit == 1)
                system("cls");
            else if (cont_exit == 0)
                system("cls");
            else if (cont_exit == 2)
                exit(0);
            else
                printf("\nInvalid option, please try again.");
        }
        while(cont_exit != 0 && cont_exit != 1);
    }
    while (cont_exit == 0);
}

void EPF(void)
{
    int c_age, r_age, life_expect, retire_yr_on, spending_yr_period, cont_exit = 0;
    float total_saving = 0, inflation, month_income;
    system("cls");

    do
    {
        printf("\n\n\t\t\t\t\t***Retirement Savings Calculator***\n\n\n");

        *_string = "\t\tCurrent age\0";
        *_units = "years old\0";
        c_age = ichecker(60,18,0,3);

        *_string = "\t\tRetirement age\0";
        r_age = ichecker(70,c_age,0,3);

        *_string = "\t\tLife expectancy";
        life_expect = ichecker(110,r_age,0,3);

        *_string = "\t\tExpected inflation rate\0";
        *_units = "%\0";
        inflation = fchecker(10,0,1,2);

        *_string = "\t\tMonthly payout\0";
        *_units = "RM\0";
        month_income = fchecker(1000000,0,1,1);

        retire_yr_on = r_age - c_age;
        spending_yr_period = life_expect - r_age;
        month_income *= pow(1 + inflation / 100, r_age - c_age - 1); //monthly income adjusted to inflation

        for(; r_age <= life_expect; r_age++)
        {
            month_income *= (1 + inflation / 100);
            total_saving += ceil(month_income) * 12;
        }

        printf("\n\t\tRetire in : %d years\n\n", retire_yr_on);
        printf("\t\tSpending year period : %d years\n\n", spending_yr_period);
        printf("\t\tTotal saving required by retirement : RM%.2f\n", total_saving);

        do
        {
            printf("\n\nChoose any one option to continue? (0 - Calculate again; 1 - Return to main menu;\n 2 - Exit the program) : ");
            scanf("%d", &cont_exit);
            flush();
            if (cont_exit == 1)
                system("cls");
            else if (cont_exit == 0)
                system("cls");
            else if (cont_exit == 2)
                exit(0);
            else
                printf("\nInvalid option, please try again.");
        }
        while(cont_exit != 0 && cont_exit != 1);
    }
    while(cont_exit == 0);
}
