#include <stdio.h>

/* 1. Print title and the routes */
void printMenu()
{
    printf("\n=====================================\n");
    printf("        BUS TICKET BOOKING\n");
    printf("=====================================\n");
    printf("  1. Karachi to Hyderabad : Rs. 800\n");
    printf("  2. Karachi to Sukkur    : Rs. 2200\n");
    printf("  3. Karachi to Multan    : Rs. 3500\n");
    printf("-------------------------------------\n");
}

/* 2. Ask for route number (1 to 3) and give it to main() using a pointer */
void getRouteNumber(int *route)
{
    printf("Enter route number (1-3): ");
    scanf("%d", route);
    while (*route < 1 || *route > 3)
    {
        printf("Invalid route number. Try again: ");
        scanf("%d", route);
    }
}

/* 3. Ask for number of seats (1 to 6) and give it to main() using a pointer */
void getSeats(int *seats)
{
    printf("Enter number of seats (1-6): ");
    scanf("%d", seats);
    while (*seats < 1 || *seats > 6)
    {
        printf("Invalid number of seats. Try again: ");
        scanf("%d", seats);
    }
}

/* Ask for seat type: E (Economy) or B (Business) */
void getSeatType(char *type)
{
    printf("Enter seat type (E = Economy, B = Business): ");
    scanf(" %c", type);
    while (*type != 'E' && *type != 'e' && *type != 'B' && *type != 'b')
    {
        printf("Invalid seat type. Enter E or B: ");
        scanf(" %c", type);
    }
}

/* 4. Find the fare of one seat from the route number */
int findFare(int route)
{
    int fare;

    switch (route)
    {
    case 1:
        fare = 800;
        break;
    case 2:
        fare = 2200;
        break;
    case 3:
        fare = 3500;
        break;
    default:
        fare = 0;
    }
    return fare;
}

/* 5. Find the total fare from seat fare and number of seats */
int findTotalFare(int fare, int seats)
{
    return fare * seats;
}

/* 6. Business seat adds 30% of the total, Economy adds nothing */
float addSeatCharge(int total, char type)
{
    float newTotal;

    if (type == 'B' || type == 'b')
        newTotal = total + total * 0.30;
    else
        newTotal = total;
    return newTotal;
}

/* 7. Print the ticket */
void printTicket(int route, int seats, char type, float finalFare)
{
    printf("\n---------------- TICKET ----------------\n");
    printf("Route      : ");
    switch (route)
    {
    case 1:
        printf("Karachi to Hyderabad\n");
        break;
    case 2:
        printf("Karachi to Sukkur\n");
        break;
    case 3:
        printf("Karachi to Multan\n");
        break;
    }
    printf("Seats      : %d\n", seats);
    if (type == 'B' || type == 'b')
        printf("Seat Type  : Business\n");
    else
        printf("Seat Type  : Economy\n");
    printf("Final Fare : Rs. %.2f\n", finalFare);
    printf("----------------------------------------\n");
}

int main()
{
    int i, route, seats, fare, total;
    char type;
    float finalFare;
    float totalEarnings = 0;   /* total earnings of the bus company */

    for (i = 1; i <= 2; i++)
    {
        printf("\n########## Passenger %d of 2 ##########", i);
        printMenu();

        getRouteNumber(&route);
        getSeats(&seats);
        getSeatType(&type);

        fare = findFare(route);
        total = findTotalFare(fare, seats);
        finalFare = addSeatCharge(total, type);

        printTicket(route, seats, type, finalFare);

        totalEarnings = totalEarnings + finalFare;
    }

    printf("\nTotal earnings of the bus company: Rs. %.2f\n", totalEarnings);
    return 0;
}