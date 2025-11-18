#include <stdio.h>
#include <stdlib.h>
# define CONSTANT_PRICE_OF_DELIVERY 5.5
# define PRICE_PER_KG 11
# define PRICE_PER_SQCM 0.3
/*------------------------------------------------------
* Func ename: calc_price
* Description: The program accepts as input:
• Length of the package in mm
• Width of the package in mm
• Weight of the package in grams
The program calculates and prints:
• Size of the package in square centimeters
• Weight of the package in kilograms
• Price of delivery in new shekels 
\*-------------------------------------------------------*/

double calc_price(int length_mm, int width_mm, int weight_g)
{
    double total_price = CONSTANT_PRICE_OF_DELIVERY + (PRICE_PER_KG * (weight_g / 1000.0)) + (PRICE_PER_SQCM * ((length_mm / 10.0) * (width_mm / 10.0))) + ((0.1 * ((length_mm / 10.0) * (width_mm / 10.0))) / (weight_g / 1000.0));
    return total_price;
}
/*------------------------------------------------------
* Filename: Calc Price
* Description: The program accepts as input:
• The current date
• Date of birth
The program accepts the dates in the following format: yyyy/mm/dd
The program calculates his age in years, months, and days and prints the result.
* Author: ravid rozemberg
\*-------------------------------------------------------*/
int main() 
{
    int length_mm, width_mm, weight_g;
    printf("Enter the length of the package in mm: ");
    scanf("%d", &length_mm);//input length
    printf("Enter the width of the package in mm: ");
    scanf("%d", &width_mm);//input width
    printf("Enter the weight of the package in grams: ");
    scanf("%d", &weight_g);
    
    double price = calc_price(length_mm, width_mm, weight_g);//call the function to calculate price
    double size_sqcm = (length_mm / 10.0) * (width_mm / 10.0);//calculate size in square centimeters
    double weight_kg = weight_g / 1000.0;//calculate weight in kilograms
    // Print results
    printf("Size of the package: %.2f square centimeters\n", size_sqcm);
    printf("Weight of the package: %.3f kilograms\n", weight_kg);
    printf("Price of delivery: %.2f new shekels\n", price);
    return 0;
}

