#include <stdio.h>
/*------------------------------------------------------
* Filename: Max
* Description: The program defines and initializes two variables
 and prints the maximum value between these two variables using a third variable.
* Author: ravid rozemberg
-------------------------------------------------------*/
int main() 
{
int x=6;
int y=9;
int z;
if (x>y)//condition to check which variable is greater
{
    z=x;
}
else
{
    z=y;
}
    printf("The maximum value is: %d\n",z);//print the maximum value
    return 0;
}