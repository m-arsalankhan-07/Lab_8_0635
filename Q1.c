#include <stdio.h>

/* 1. Print title and list of 4 recharge packs */
void printMenu()
{
    printf("\n=====================================\n");
    printf("      PREPAID MOBILE RECHARGE\n");
    printf("=====================================\n");
    printf("  1. Rs. 100\n");
    printf("  2. Rs. 200\n");
    printf("  3. Rs. 500\n");
    printf("  4. Rs. 1000\n");
    printf("-------------------------------------\n");
}

/* 2. Ask for pack number (1 to 4) and give it to main() using a pointer */
void getPackNumber(int *pack)
{
    printf("Enter pack number (1-4): ");
    scanf("%d", pack);
    while (*pack < 1 || *pack > 4)
    {
        printf("Invalid pack number. Try again: ");
        scanf("%d", pack);
    }
}

/* 3. Ask for 11-digit mobile number and give it to main() using a pointer */
void getMobileNumber(long long *mobile)
{
    printf("Enter mobile number (11 digits): ");
    scanf("%lld", mobile);
    while (*mobile < 10000000000LL || *mobile > 99999999999LL)
    {
        printf("Invalid number. Enter exactly 11 digits: ");
        scanf("%lld", mobile);
    }
}

/* 4. Find pack amount from pack number using switch */
int getPackAmount(int pack)
{
    int amount;

    switch (pack)
    {
    case 1:
        amount = 100;
        break;
    case 2:
        amount = 200;
        break;
    case 3:
        amount = 500;
        break;
    case 4:
        amount = 1000;
        break;
    default:
        amount = 0;
    }
    return amount;
}

/* 5. Add 15% tax: returns the tax, new amount goes back using a pointer */
float addTax(int amount, float *newAmount)
{
    float tax;

    tax = amount * 0.15;
    *newAmount = amount + tax;
    return tax;
}

/* 6. Bonus: 10% if pack is Rs. 500 or more, otherwise 0 */
float findBonus(int amount)
{
    float bonus;

    if (amount >= 500)
        bonus = amount * 0.10;
    else
        bonus = 0;
    return bonus;
}

/* 7. Print recharge slip */
void printSlip(long long mobile, int amount, float tax, float bonus)
{
    printf("\n------------ RECHARGE SLIP ------------\n");
    printf("Mobile Number : %lld\n", mobile);
    printf("Pack Amount   : Rs. %d\n", amount);
    printf("Tax (15%%)     : Rs. %.2f\n", tax);
    printf("Bonus         : Rs. %.2f\n", bonus);
    printf("Total Balance : Rs. %.2f\n", amount + bonus);
    printf("---------------------------------------\n");
}

int main()
{
    int i, pack, amount;
    long long mobile;
    float tax, newAmount, bonus;
    float totalSpent = 0;

    for (i = 1; i <= 3; i++)
    {
        printf("\n########## Recharge %d of 3 ##########", i);
        printMenu();

        getPackNumber(&pack);
        getMobileNumber(&mobile);

        amount = getPackAmount(pack);
        tax = addTax(amount, &newAmount);
        bonus = findBonus(amount);

        printSlip(mobile, amount, tax, bonus);

        totalSpent = totalSpent + newAmount;
    }

    printf("\nTotal money spent in 3 recharges (incl. tax): Rs. %.2f\n", totalSpent);
    return 0;
}