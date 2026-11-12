
#include <stdio.h>

// Function prototypes
int findMax(int *p, int n);
int findMin(int *p, int n);
double findAverage(int *p, int n);
int countAbove(int *p, int n, double avg);
void reverseArray(int *p, int n);
int searchMark(int *p, int n, int key);

int main()
{
    int marks[10];
    int i, key;
    int max, min, position;
    int passCount;
    double avg;

    // 1. Input marks of 10 students
    for (i = 0; i < 10; i++)
    {
        do
        {
            printf("Enter marks of student %d (0-100): ", i + 1);
            scanf("%d", &marks[i]);

        } while (marks[i] < 0 || marks[i] > 100);
    }

    // 2. Find maximum, minimum and average
    max = findMax(marks, 10);
    min = findMin(marks, 10);
    avg = findAverage(marks, 10);

    printf("\nHighest marks: %d", max);
    printf("\nLowest marks: %d", min);
    printf("\nAverage marks: %.2lf\n", avg);

    // Count students above average
    printf("Students above average: %d\n",
           countAbove(marks, 10, avg));

    // 3. Print array before reversing
    printf("\nMarks before reversing:\n");

    for (i = 0; i < 10; i++)
    {
        printf("%d ", marks[i]);
    }

    // Reverse the array
    reverseArray(marks, 10);

    // Print array after reversing
    printf("\n\nMarks after reversing:\n");

    for (i = 0; i < 10; i++)
    {
        printf("%d ", marks[i]);
    }

    // 4. Search for a particular mark
    printf("\n\nEnter marks to search: ");
    scanf("%d", &key);

    position = searchMark(marks, 10, key);

    if (position == -1)
    {
        printf("Mark not found!");
    }
    else
    {
        printf("Mark found at position %d", position + 1);
    }

    // 5. Count students who passed (40 or more)
    passCount = 0;

    for (i = 0; i < 10; i++)
    {
        if (marks[i] >= 40)
        {
            passCount++;
        }
    }

    printf("\n\nNumber of students who passed: %d\n", passCount);

    return 0;
}


// Find maximum mark
int findMax(int *p, int n)
{
    int max = *p;

    for (int i = 0; i < n; i++)
    {
        if (*p > max)
        {
            max = *p;
        }

        p++;
    }

    return max;
}


// Find minimum mark
int findMin(int *p, int n)
{
    int min = *p;

    for (int i = 0; i < n; i++)
    {
        if (*p < min)
        {
            min = *p;
        }

        p++;
    }

    return min;
}


// Calculate average
double findAverage(int *p, int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + *p;
        p++;
    }

    return (double)sum / n;
}


// Count students above average
int countAbove(int *p, int n, double avg)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (*p > avg)
        {
            count++;
        }

        p++;
    }

    return count;
}


// Reverse array using two pointers
void reverseArray(int *p, int n)
{
    int *start = p;
    int *end = p + n - 1;
    int temp;

    while (start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}


// Search for a particular mark
int searchMark(int *p, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (*p == key)
        {
            return i;
        }

        p++;
    }

    return -1;
}