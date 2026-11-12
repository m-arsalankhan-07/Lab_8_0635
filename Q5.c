#include <stdio.h>

int main()
{
    /* 1. Three double variables */
    double costPrice, sellPrice, quantity;

    /* 2. Three pointers, one for each variable */
    double *pCost = &costPrice;
    double *pSell = &sellPrice;
    double *pQty = &quantity;

    printf("Enter cost price: ");
    scanf("%lf", pCost);
    printf("Enter selling price: ");
    scanf("%lf", pSell);
    printf("Enter quantity sold: ");
    scanf("%lf", pQty);

    /* 3. Total cost, total sales and profit/loss, calculated and stored using pointers */
    double totalCost, totalSales, profit, percentage;
    double *pTotalCost = &totalCost;
    double *pTotalSales = &totalSales;
    double *pProfit = &profit;
    double *pPercentage = &percentage;

    *pTotalCost = *pCost * *pQty;
    *pTotalSales = *pSell * *pQty;
    *pProfit = *pTotalSales - *pTotalCost;

    /* 4. Profit, Loss or No profit no loss */
    printf("\nResult: ");
    if (*pProfit > 0)
        printf("Profit\n");
    else if (*pProfit < 0)
        printf("Loss\n");
    else
        printf("No profit no loss\n");

    printf("Total cost  : %.2f\n", *pTotalCost);
    printf("Total sales : %.2f\n", *pTotalSales);
    printf("Profit/Loss : %.2f\n", *pProfit);

    /* 5. Profit percentage using pointers */
    if (*pTotalCost > 0)
        *pPercentage = (*pProfit / *pTotalCost) * 100;
    else
        *pPercentage = 0;
    printf("Profit percentage: %.2f%%\n", *pPercentage);

    /* 6. Pointer to the larger of costPrice and sellPrice */
    double *pLarger;
    if (*pCost > *pSell)
    {
        pLarger = pCost;
        printf("\nLarger price is costPrice: %.2f\n", *pLarger);
    }
    else if (*pSell > *pCost)
    {
        pLarger = pSell;
        printf("\nLarger price is sellPrice: %.2f\n", *pLarger);
    }
    else
    {
        pLarger = pCost;
        printf("\ncostPrice and sellPrice are equal: %.2f\n", *pLarger);
    }

    /* 7. Table of addresses of every variable and every pointer */
    printf("\n%-14s %-20s %s\n", "Name", "Address", "Value / Points to");
    printf("-------------------------------------------------------\n");

    printf("%-14s %-20p %.2f\n", "costPrice", &costPrice, costPrice);
    printf("%-14s %-20p %.2f\n", "sellPrice", &sellPrice, sellPrice);
    printf("%-14s %-20p %.2f\n", "quantity", &quantity, quantity);
    printf("%-14s %-20p %.2f\n", "totalCost", &totalCost, totalCost);
    printf("%-14s %-20p %.2f\n", "totalSales", &totalSales, totalSales);
    printf("%-14s %-20p %.2f\n", "profit", &profit, profit);
    printf("%-14s %-20p %.2f\n", "percentage", &percentage, percentage);

    printf("%-14s %-20p %p\n", "pCost", &pCost, pCost);
    printf("%-14s %-20p %p\n", "pSell", &pSell, pSell);
    printf("%-14s %-20p %p\n", "pQty", &pQty, pQty);
    printf("%-14s %-20p %p\n", "pTotalCost", &pTotalCost, pTotalCost);
    printf("%-14s %-20p %p\n", "pTotalSales", &pTotalSales, pTotalSales);
    printf("%-14s %-20p %p\n", "pProfit", &pProfit, pProfit);
    printf("%-14s %-20p %p\n", "pPercentage", &pPercentage, pPercentage);
    printf("%-14s %-20p %p\n", "pLarger", &pLarger, pLarger);

    return 0;
}