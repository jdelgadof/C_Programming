//
// Created by Jeferson on 27/08/2023.
//
#include <stdio.h>

int main()
{
    float monthlySalaries[12];
    float taxRate, incomeLimit, overLimitTaxRate;

    // Step 1: Ask user to enter tax percentage and yearly income limit
    printf("Enter tax rate:");
    scanf("%f", &taxRate);

    printf("Enter income limit:");
    scanf("%f", &incomeLimit);

    printf("Enter tax rate for income over the limit:");
    scanf("%f", &overLimitTaxRate);

    // Step 2: Ask user to enter monthly salaries
    for (int month = 0; month < 12; month++)
    {
        printf("Enter income for month %d:", month + 1);
        scanf("%f", &monthlySalaries[month]);
        //printf("\n");
    }

    // Step 3: Calculate and print monthly salaries and tax
    printf("month\t    income\t\ttax\n");
    float totalIncome = 0;
    for (int month = 0; month < 12; month++)
    {

        float income = monthlySalaries[month];
        totalIncome += monthlySalaries[month];
        float tax;

        if (totalIncome < incomeLimit)
        {
            tax = income * taxRate / 100;

        } else
        {
            if (totalIncome - incomeLimit > monthlySalaries[month])
            {
                tax = income * overLimitTaxRate / 100;
            }
            else{
                float diff = totalIncome - incomeLimit;
                tax = ((income - diff) * taxRate / 100) + (diff * overLimitTaxRate / 100);
            }
        }

        printf("%2d\t%8.2f\t%8.2f\n", month + 1, income, tax);
    }

    return 0;
}