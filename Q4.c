#include <stdio.h>

/* 1. Print title and fare rules */
void printRules()
{
    printf("\n=====================================\n");
    printf("            TAXI SERVICE\n");
    printf("=====================================\n");
    printf("  Base fare        : Rs. 150\n");
    printf("  First 10 km      : Rs. 60 per km\n");
    printf("  After 10 km      : Rs. 45 per km\n");
    printf("-------------------------------------\n");
}

/* 2. Ask for distance (more than 0, up to 200) and give it to main() */
void getDistance(float *distance)
{
    printf("Enter distance in km (up to 200): ");
    scanf("%f", distance);
    while (*distance <= 0 || *distance > 200)
    {
        printf("Invalid distance. Try again: ");
        scanf("%f", distance);
    }
}

/* 3. Ask for waiting time (0 to 120 minutes) and give it to main() */
void getWaitingTime(int *minutes)
{
    printf("Enter waiting time in minutes (0-120): ");
    scanf("%d", minutes);
    while (*minutes < 0 || *minutes > 120)
    {
        printf("Invalid waiting time. Try again: ");
        scanf("%d", minutes);
    }
}

/* Ask for the hour of the trip (0 to 23) and give it to main() */
void getHour(int *hour)
{
    printf("Enter hour of the trip (0-23): ");
    scanf("%d", hour);
    while (*hour < 0 || *hour > 23)
    {
        printf("Invalid hour. Try again: ");
        scanf("%d", hour);
    }
}

/* 4. Distance charge: base fare + Rs. 60/km for first 10 km + Rs. 45/km after */
float findDistanceCharge(float distance)
{
    float charge;

    if (distance <= 10)
        charge = 150 + distance * 60;
    else
        charge = 150 + 10 * 60 + (distance - 10) * 45;
    return charge;
}

/* 5. Waiting charge: first 5 minutes free, then Rs. 10 per minute */
float findWaitingCharge(int minutes)
{
    float charge;

    if (minutes > 5)
        charge = (minutes - 5) * 10;
    else
        charge = 0;
    return charge;
}

/* 6. Night charge: 25% extra if hour is 22 or later, or before 6 */
float addNightCharge(float fare, int hour)
{
    if (hour >= 22 || hour < 6)
        fare = fare + fare * 0.25;
    return fare;
}

/* 7. Print the trip receipt */
void printReceipt(float distance, int minutes, float finalFare)
{
    printf("\n------------- TRIP RECEIPT -------------\n");
    printf("Distance      : %.2f km\n", distance);
    printf("Waiting Time  : %d minutes\n", minutes);
    printf("Final Fare    : Rs. %.2f\n", finalFare);
    printf("----------------------------------------\n");
}

int main()
{
    int i, minutes, hour;
    float distance, fare, finalFare;
    float totalEarnings = 0;
    float highestFare = 0;

    for (i = 1; i <= 3; i++)
    {
        printf("\n########## Trip %d of 3 ##########", i);
        printRules();

        getDistance(&distance);
        getWaitingTime(&minutes);
        getHour(&hour);

        fare = findDistanceCharge(distance) + findWaitingCharge(minutes);
        finalFare = addNightCharge(fare, hour);

        printReceipt(distance, minutes, finalFare);

        totalEarnings = totalEarnings + finalFare;
        if (finalFare > highestFare)
            highestFare = finalFare;
    }

    printf("\nTotal earnings   : Rs. %.2f\n", totalEarnings);
    printf("Highest fare     : Rs. %.2f\n", highestFare);
    return 0;
}