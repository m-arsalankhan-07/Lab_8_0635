#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayStock(int *p, int n);
void updateStock(int *p, int n);
void insertItem(int **p, int *n);
void deleteItem(int **p, int *n);
void sortStock(int *p, int n);
void showReport(int *p, int n);

int main()
{
    int n, choice;

    // 1. Ask for starting size
    do
    {
        printf("Enter starting size (3 to 8): ");
        scanf("%d", &n);

    } while (n < 3 || n > 8);

    // Create dynamic array
    int *stock = malloc(n * sizeof(int));

    if (stock == NULL)
    {
        printf("Memory allocation failed!");
        return 1;
    }

    // Enter initial stock values
    for (int i = 0; i < n; i++)
    {
        printf("Enter stock of item %d: ", i + 1);
        scanf("%d", &stock[i]);
    }

    // 2. Menu
    do
    {
        printf("\n\n===== STOCK MANAGEMENT =====\n");
        printf("1. Display Stock\n");
        printf("2. Update Stock\n");
        printf("3. Insert New Item\n");
        printf("4. Delete Item\n");
        printf("5. Sort Stock\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                displayStock(stock, n);
                break;

            case 2:
                updateStock(stock, n);
                showReport(stock, n);
                break;

            case 3:
                insertItem(&stock, &n);
                showReport(stock, n);
                break;

            case 4:
                deleteItem(&stock, &n);
                showReport(stock, n);
                break;

            case 5:
                sortStock(stock, n);
                printf("\nStock sorted successfully!");
                showReport(stock, n);
                break;

            case 6:
                printf("\nExiting program...");
                break;

            default:
                printf("\nInvalid choice!");
        }

    } while (choice != 6);

    // 8. Free memory
    free(stock);
    stock = NULL;

    printf("\nMemory released successfully!");

    return 0;
}


// Display stock
void displayStock(int *p, int n)
{
    printf("\nCurrent Stock:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Item %d: %d\n", i + 1, *p);
        p++;
    }
}


// Update stock
void updateStock(int *p, int n)
{
    int pos, value;

    printf("Enter position to update: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n)
    {
        printf("Invalid position!");
        return;
    }

    printf("Enter new stock value: ");
    scanf("%d", &value);

    *(p + pos - 1) = value;

    printf("Stock updated successfully!");
}


// Insert new item
void insertItem(int **p, int *n)
{
    int pos, value;

    printf("Enter position to insert: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > *n + 1)
    {
        printf("Invalid position!");
        return;
    }

    printf("Enter stock value: ");
    scanf("%d", &value);

    // Create new array one element bigger
    int *temp = malloc((*n + 1) * sizeof(int));

    if (temp == NULL)
    {
        printf("Memory allocation failed!");
        return;
    }

    // Copy elements before insertion
    for (int i = 0; i < pos - 1; i++)
    {
        temp[i] = (*p)[i];
    }

    // Insert new value
    temp[pos - 1] = value;

    // Copy remaining elements
    for (int i = pos; i < *n + 1; i++)
    {
        temp[i] = (*p)[i - 1];
    }

    // Free old array
    free(*p);

    // Point to new array
    *p = temp;

    (*n)++;

    printf("Item inserted successfully!");
}


// Delete item
void deleteItem(int **p, int *n)
{
    int pos;

    if (*n == 1)
    {
        printf("Cannot delete the last item!");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > *n)
    {
        printf("Invalid position!");
        return;
    }

    // Create new array one element smaller
    int *temp = malloc((*n - 1) * sizeof(int));

    if (temp == NULL)
    {
        printf("Memory allocation failed!");
        return;
    }

    // Copy elements before deleted position
    for (int i = 0; i < pos - 1; i++)
    {
        temp[i] = (*p)[i];
    }

    // Copy elements after deleted position
    for (int i = pos - 1; i < *n - 1; i++)
    {
        temp[i] = (*p)[i + 1];
    }

    // Free old array
    free(*p);

    // Point to new array
    *p = temp;

    (*n)--;

    printf("Item deleted successfully!");
}


// Sort stock using Bubble Sort
void sortStock(int *p, int n)
{
    int temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (*(p + j) > *(p + j + 1))
            {
                temp = *(p + j);

                *(p + j) = *(p + j + 1);

                *(p + j + 1) = temp;
            }
        }
    }
}


// Display total stock and lowest stock
void showReport(int *p, int n)
{
    int total = 0;
    int lowest = *p;

    for (int i = 0; i < n; i++)
    {
        total = total + *p;

        if (*p < lowest)
        {
            lowest = *p;
        }

        p++;
    }

    printf("\n\nTotal Stock: %d", total);
    printf("\nLowest Stock: %d\n", lowest);
}