#include <stdio.h>
# define current_year 2025
# define current_month 11
# define current_day 17
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
printf("Enter your date of birth (yyyy/mm/dd): ");
scanf("%d/%d/%d", &birth_year, &birth_month, &birth_day);
// Calculate age in years, months, and days
age_years = current_year - birth_year;
age_months = current_month - birth_month;
age_days = current_day - birth_day;
if (age_days < 0) {
    age_days += 30; // Approximate month length
    age_months--;
}
if (age_months < 0) {
    age_months += 12;
    age_years--;
}
printf("Your age is: %d years, %d months, and %d days\n", age_years, age_months, age_days);
return 0;
}