#include <stdio.h>
#include <stdlib.h>
# define CONSTANT_PRICE_OF_DELIVERY 5.5
# define PRICE_PER_KG 11
# define PRICE_PER_SQCM 0.3

double calc_price(int length_mm, int width_mm, int weight_g)
{
    double total_price = CONSTANT_PRICE_OF_DELIVERY + (PRICE_PER_KG * (weight_g / 1000.0)) + (PRICE_PER_SQCM * ((length_mm / 10.0) * (width_mm / 10.0))) + ((0.1 * ((length_mm / 10.0) * (width_mm / 10.0))) / (weight_g / 1000.0));
    return total_price;
}

int main() 
{
    int length_mm, width_mm, weight_g;
    printf("Enter the length of the package in mm: ");
    scanf("%d", &length_mm);
    printf("Enter the width of the package in mm: ");
    scanf("%d", &width_mm);
    printf("Enter the weight of the package in grams: ");
    scanf("%d", &weight_g);
    
    double price = calc_price(length_mm, width_mm, weight_g);
    double size_sqcm = (length_mm / 10.0) * (width_mm / 10.0);
    double weight_kg = weight_g / 1000.0;
    
    printf("Size of the package: %.2f square centimeters\n", size_sqcm);
    printf("Weight of the package: %.3f kilograms\n", weight_kg);
    printf("Price of delivery: %.2f new shekels\n", price);
    return 0;
}

