#include <stdio.h>
/*------------------------------------------------------
* Filename: Max
* Description: The program defines and initializes two variables
 and prints the maximum value between these two variables using a third variable.
* Author: ravid rozemberg
-------------------------------------------------------*/
int main() 
{
int x = 10;
int y = 20;
int z = (x > y) ? x : y;
printf("the max value is:%d\n", z);
}
