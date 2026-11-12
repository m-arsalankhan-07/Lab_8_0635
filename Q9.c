#include <stdio.h>
#include <string.h>

// Function prototypes
void readMarks(int *m1, int *m2, int *m3);

void calculateStats(int m1, int m2, int m3,
                    int *total, double *average,
                    int *highest, int *lowest);

void swapMarks(int *a, int *b);

void addGrade(int *mark, int grade);

void findGrade(double avg, char grade[], char remark[]);

void incrementByValue(int x);

void incrementByReference(int *x);


int main()
{
    int m1, m2, m3;
    int total, highest, lowest;
    double average;

    char grade[20];
    char remark[30];

    // Repeat for 5 students
    for (int i = 1; i <= 5; i++)
    {
        printf("\n========== STUDENT %d ==========\n", i);

        // Read three subject marks
        readMarks(&m1, &m2, &m3);

        // Apply grace marks
        addGrade(&m1, 5);
        addGrade(&m2, 5);
        addGrade(&m3, 5);

        // Sort marks from highest to lowest
        if (m1 < m2)
            swapMarks(&m1, &m2);

        if (m1 < m3)
            swapMarks(&m1, &m3);

        if (m2 < m3)
            swapMarks(&m2, &m3);

        // Calculate statistics
        calculateStats(m1, m2, m3,
                       &total, &average,
                       &highest, &lowest);

        // Find grade and remark
        findGrade(average, grade, remark);

        // Display results
        printf("\n----- RESULT -----\n");

        printf("Highest marks: %d\n", highest);
        printf("Middle marks: %d\n", m2);
        printf("Lowest marks: %d\n", lowest);

        printf("Total: %d\n", total);
        printf("Average: %.2lf\n", average);

        printf("Grade: %s\n", grade);
        printf("Remark: %s\n", remark);
    }


    // Comparison demonstration
    printf("\n\n===== PASS BY VALUE VS POINTER =====\n");

    int x = 10;

    printf("\nOriginal value: %d\n", x);

    incrementByValue(x);

    printf("After incrementByValue: %d\n", x);

    incrementByReference(&x);

    printf("After incrementByReference: %d\n", x);

    return 0;
}


// 1. Read three subject marks
void readMarks(int *m1, int *m2, int *m3)
{
    do
    {
        printf("Enter marks for subject 1 (0-100): ");
        scanf("%d", m1);

    } while (*m1 < 0 || *m1 > 100);


    do
    {
        printf("Enter marks for subject 2 (0-100): ");
        scanf("%d", m2);

    } while (*m2 < 0 || *m2 > 100);


    do
    {
        printf("Enter marks for subject 3 (0-100): ");
        scanf("%d", m3);

    } while (*m3 < 0 || *m3 > 100);
}


// 2. Calculate statistics
void calculateStats(int m1, int m2, int m3,
                    int *total, double *average,
                    int *highest, int *lowest)
{
    *total = m1 + m2 + m3;

    *average = (double)*total / 3;

    *highest = m1;

    *lowest = m1;

    if (m2 > *highest)
        *highest = m2;

    if (m3 > *highest)
        *highest = m3;

    if (m2 < *lowest)
        *lowest = m2;

    if (m3 < *lowest)
        *lowest = m3;
}


// 3. Swap two marks
void swapMarks(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}


// 4. Add grace marks
void addGrade(int *mark, int grade)
{
    if (*mark >= 35 && *mark < 40)
    {
        int needed = 40 - *mark;

        if (needed <= grade)
        {
            *mark = *mark + needed;
        }
    }
}


// 5. Find grade and remark
void findGrade(double avg, char grade[], char remark[])
{
    if (avg >= 80)
    {
        strcpy(grade, "A");
        strcpy(remark, "Excellent");
    }
    else if (avg >= 60)
    {
        strcpy(grade, "B");
        strcpy(remark, "Good");
    }
    else
    {
        strcpy(grade, "C");
        strcpy(remark, "Needs Improvement");
    }
}


// 6. Pass by value
void incrementByValue(int x)
{
    x++;

    printf("Inside incrementByValue: %d\n", x);
}


// Pass by reference using pointer
void incrementByReference(int *x)
{
    (*x)++;

    printf("Inside incrementByReference: %d\n", *x);
}