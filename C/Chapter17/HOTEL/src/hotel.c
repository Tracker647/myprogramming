#include <stdio.h>
#include "hotel.h"
int menu()
{
    int code, status;

    printf("\n%s%s\n", STARS, STARS);
    printf("Enter the number of the desired hotel:\n");
    printf("1) Fairfield Arms       2) Hotel olympic\n ");
    printf("3) Chertworthy Plaza    4) The stockton\n ");
    printf("5) quit\n");
    printf("%s%s\n", STARS, STARS);
    while ((status = scanf("%d", &code)) != 1 || (code < 1 || code > 5))
    {
        if (status != 1)
            scanf("%*s"); //处理非整数輸入
        printf("Enter an integer from 1 to 5, please.\n");
    }
    return code;
}

int getnights(void)
{
    int nights;
    printf("How many nights are needed? ");
    while (scanf("%d", &nights) != 1)
    {    
        scanf("%*s");  //处理非整数输入
        printf("Please enter an integer, such as 2.\n");
    }  
    return nights;
}

void showprice (double rate, int nights)
{
    int n;
    double total = 0.0;
    double factor = 1.0;
    for (n = 1; n <= nights; n++, factor *= DISCOUNT)
        total += rate * factor;
    printf("The total cost wil1 be $%0.2f.\n", total);
}