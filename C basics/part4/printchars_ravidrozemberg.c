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

#define DIV2 2
#define DIV3 3
#define DIV5 5
#define ERR_NEG_INPUT 1

int main(void) {
    int n, i, j;
    char ch;

    printf("Enter a positive integer: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return ERR_NEG_INPUT;
    }

    if (n <= 0) {
        printf("Error: Please enter a positive integer.\n");
        return ERR_NEG_INPUT;
    }

    /* Priority: divisible by 2 -> '*'
       else if divisible by 3 -> '^'
       else if divisible by 5 -> '%'
       else -> '@'
       This single chain handles all combinations (e.g., divisible by 2 and 3)
       because the first true condition wins. */
    if (n % DIV2 == 0) {
        ch = '*';
    } else if (n % DIV3 == 0) {
        ch = '^';
    } else if (n % DIV5 == 0) {
        ch = '%';
    } else {
        ch = '@';
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            putchar(ch);
        }
        putchar('\n');
    }

    return 0;
}

