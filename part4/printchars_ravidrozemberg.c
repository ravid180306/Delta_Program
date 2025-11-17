/*------------------------------------------------------
* Filename: Print Chars
* Description: The program receives a positive integer and prints
a square of characters (where the side of the square is equal to the 
value of the number). 
The characters will be printed according to
the following rules:
• If the number is even, the character to be printed will be *
• If the number is divisible by 3 without a remainder, the character to be printed will be ^
• If the number is divisible by 5 without a remainder, the character to be printed will be %
• Otherwise, the character @ will be printed
• The first rule that applies to the number determines the character to be printed. That is, if the number
15 is received, the character ^ will be printed 15 times.
* Author: ravid rozemberg
\*-------------------------------------------------------*/
#include <stdio.h>
int main() 
{
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    if (n <= 0) 
    {
        printf("Error: Please enter a positive integer.\n");
        return 1;
    }
    char ch;
    if (n % 2 == 0) 
    {
        ch = '*';
    } 
    else if (n % 3 == 0) 
    {
        ch = '^';
    } 
    else if (n % 5 == 0) 
    {
        ch = '%';
    } 
    else 
    {
        ch = '@';
    }
    if((n%2==0)&&(n%3==0))//if n is even and divisible by 3
    {
        ch='*';//print *
    }
    else 
    if((n%2==0)&&(n%5==0))//if n is even and divisible by 5
    {
        ch='*';//print *
    }
     else 
     if((n%3==0)&&(n%5==0))//if n is divisible by 3 and 5
    {
        ch='^';//print ^
    }
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            printf("%c", ch);
        }
        printf("\n");
    }
    return 0;
}
