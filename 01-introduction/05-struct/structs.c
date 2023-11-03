#include <stdio.h>
#include <string.h>

int main()
{

    struct food {
        char name[10];
        int calories;
        int price;
    };


    struct food cherry;
    strcpy(cherry.name, "Cherry");
    cherry.calories = 50;
    cherry.price = 69;

    printf("The name of the product is %s. For 100g calories are %d and the price is %d cents.\n", cherry.name, cherry.calories, cherry.price);

    return 0;
}
