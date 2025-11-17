#include <stdio.h>
# define CURRENT_YEAR 2025
# define CURRENT_MONTH 11
# define CURRENT_DAY 17
/*------------------------------------------------------
* Filename: Calc Age
* Description: The program accepts as input:
• The current date
• Date of birth
The program accepts the dates in the following format: yyyy/mm/dd
The program calculates his age in years, months, and days and prints the result.
* Author: ravid rozemberg
-------------------------------------------------------*/
int main() 
{
int birth_year, birth_month, birth_day;
int age_years, age_months, age_days;
int current_year, current_month, current_day;
// Input date of birth
printf("Enter your date of birth (yyyy/mm/dd): ");
scanf("%d/%d/%d", &birth_year, &birth_month, &birth_day);
// Input current date
printf("Enter your date of today date (yyyy/mm/dd): ");
scanf("%d/%d/%d", &current_year, &current_month, &current_day);
// Calculate age in years, months, and days
age_years = current_year - birth_year;
age_months = current_month - birth_month;
age_days = current_day - birth_day;
if (age_days < 0)//day borrow from month
 {
    age_days += 30; // Approximate month length
    age_months--;
}
if (age_months < 0) //month borrow from year
{
    age_months += 12;
    age_years--;
}
if(age_years<0)//birth date is in the future
{
    printf("Error: Birth date is in the future.\n");
    return 1;
}
if(age_years==0)//less than a year old
{
    printf("You are less than a year old! your age is:%d months,%d days\n",age_months,age_days);

}
printf("Your age is: %d years, %d months, and %d days\n", age_years, age_months, age_days);
return 0;
}