#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int count = 0;

    double *temp;

    // 1. Ask the user for number of days
    do
    {
        printf("Enter number of days (1 to 10): ");
        scanf("%d", &n);

    } while (n < 1 || n > 10);


    // 2. Dynamically allocate memory
    temp = (double *)malloc(n * sizeof(double));

    if (temp == NULL)
    {
        printf("Memory allocation failed!");
        return 1;
    }


    // 3. Read temperatures
    for (i = 0; i < n; i++)
    {
        do
        {
            printf("Enter temperature for day %d (-10 to 55): ", i + 1);
            scanf("%lf", &temp[i]);

        } while (temp[i] < -10 || temp[i] > 55);
    }


    // 4. Print each temperature with its memory address
    printf("\nTemperature Readings:\n");

    for (i = 0; i < n; i++)
    {
        printf("Day %d: %.2lf at address %p\n",
               i + 1, temp[i], (void *)&temp[i]);
    }


    // 5. Find hottest and coldest using pointers
    double *ptr = temp;

    double hottest = *ptr;
    double coldest = *ptr;

    for (i = 0; i < n; i++)
    {
        if (*ptr > hottest)
        {
            hottest = *ptr;
        }

        if (*ptr < coldest)
        {
            coldest = *ptr;
        }

        ptr++;
    }

    printf("\nHottest temperature: %.2lf", hottest);
    printf("\nColdest temperature: %.2lf", coldest);


    // 6. Count temperatures greater than 40
    ptr = temp;

    for (i = 0; i < n; i++)
    {
        if (*ptr > 40)
        {
            count++;
        }

        ptr++;
    }

    printf("\nNumber of days above 40: %d", count);


    // 7. Free dynamically allocated memory
    free(temp);
    temp = NULL;


    // 8. Confirm memory release
    printf("\n\nMemory has been released successfully!");

    return 0;
}