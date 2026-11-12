#include <stdio.h>

/* 1. Print hospital name and room charges */
void printMenu()
{
    printf("\n=====================================\n");
    printf("          CITY HOSPITAL\n");
    printf("=====================================\n");
    printf("  1. General Ward  : Rs. 1500/day\n");
    printf("  2. Semi-Private  : Rs. 3500/day\n");
    printf("  3. Private       : Rs. 6000/day\n");
    printf("-------------------------------------\n");
}

/* 2. Ask for room type (1, 2 or 3) and give it to main() using a pointer */
void getRoomType(int *room)
{
    printf("Enter room type (1-3): ");
    scanf("%d", room);
    while (*room < 1 || *room > 3)
    {
        printf("Invalid room type. Try again: ");
        scanf("%d", room);
    }
}

/* 3. Ask for number of days (1 to 30) and give it to main() using a pointer */
void getDays(int *days)
{
    printf("Enter number of days stayed (1-30): ");
    scanf("%d", days);
    while (*days < 1 || *days > 30)
    {
        printf("Invalid days. Try again: ");
        scanf("%d", days);
    }
}

/* 4. Find room charges from room type and days */
int findRoomCharges(int room, int days)
{
    int rate;

    switch (room)
    {
    case 1:
        rate = 1500;
        break;
    case 2:
        rate = 3500;
        break;
    case 3:
        rate = 6000;
        break;
    default:
        rate = 0;
    }
    return rate * days;
}

/* 5. Ask for medicine bill, add 5% service charge, find new medicine charge */
void getMedicineBill(float *bill)
{
    printf("Enter medicine bill: Rs. ");
    scanf("%f", bill);
    while (*bill < 0)
    {
        printf("Invalid amount. Try again: Rs. ");
        scanf("%f", bill);
    }
}

float findMedicineCharge(float bill)
{
    return bill + bill * 0.05;
}

/* 6. 8% discount if stay is 7 days or more, otherwise no discount */
float findFinalAmount(float total, int days)
{
    float finalAmount;

    if (days >= 7)
        finalAmount = total - total * 0.08;
    else
        finalAmount = total;
    return finalAmount;
}

/* Senior citizen question: y or n */
void getSenior(char *senior)
{
    printf("Is the patient a senior citizen? (y/n): ");
    scanf(" %c", senior);
    while (*senior != 'y' && *senior != 'Y' && *senior != 'n' && *senior != 'N')
    {
        printf("Please enter y or n: ");
        scanf(" %c", senior);
    }
}

/* Rs. 1000 off for senior citizen, bill never goes below 0 */
float applySeniorDiscount(float amount, char senior)
{
    if (senior == 'y' || senior == 'Y')
    {
        amount = amount - 1000;
        if (amount < 0)
            amount = 0;
    }
    return amount;
}

/* 7. Print final bill (room name is shown, not the number) */
void printBill(int room, int days, int roomCharges, float medicine, float finalAmount)
{
    printf("\n---------------- FINAL BILL ----------------\n");
    printf("Room Type         : ");
    switch (room)
    {
    case 1:
        printf("General Ward\n");
        break;
    case 2:
        printf("Semi-Private\n");
        break;
    case 3:
        printf("Private\n");
        break;
    }
    printf("Days Stayed       : %d\n", days);
    printf("Room Charges      : Rs. %d\n", roomCharges);
    printf("Medicine Charges  : Rs. %.2f\n", medicine);
    printf("Final Amount      : Rs. %.2f\n", finalAmount);
    printf("--------------------------------------------\n");
}

int main()
{
    int room, days, roomCharges;
    float medicineBill, medicine, total, finalAmount;
    char senior;

    printMenu();
    getRoomType(&room);
    getDays(&days);
    getMedicineBill(&medicineBill);
    getSenior(&senior);

    roomCharges = findRoomCharges(room, days);
    medicine = findMedicineCharge(medicineBill);
    total = roomCharges + medicine;
    finalAmount = findFinalAmount(total, days);
    finalAmount = applySeniorDiscount(finalAmount, senior);

    printBill(room, days, roomCharges, medicine, finalAmount);
    return 0;
}