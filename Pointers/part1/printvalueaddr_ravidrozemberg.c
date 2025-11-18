/*------------------------------------------------------
* Filename: Print Value-Addr
* Description:The program accepts an array of integers and an array of characters.
 The program prints for each element its value and its address in memory.
 The address should appear as a hexadecimal number.
* Author: ravid rozemberg 
-------------------------------------------------------*/
#include <stdio.h>
#define INT_ARRAY_SIZE 8
#define CHAR_ARRAY_SIZE 8

// Function to clear input buffer
void clearBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    int int_array[INT_ARRAY_SIZE];
    char char_array[CHAR_ARRAY_SIZE];
    char *ptr_char;
    int *ptr_int;

    // Read integers with input validation
    for(int i = 0; i < INT_ARRAY_SIZE; i++)
    {
        while (1)
        {
            printf("Enter integer %d: ", i + 1);

            if (scanf("%d", &int_array[i]) == 1)
            {
                break; // valid input
            }
            else
            {
                printf("Invalid input, please enter a valid integer.\n");
                clearBuffer();
            }
        }
        clearBuffer(); // prevent leftover characters
    }

    // Read characters with input validation
    for(int i = 0; i < CHAR_ARRAY_SIZE; i++)
    {
        while (1)
        {
            printf("Enter character %d: ", i + 1);

            if (scanf(" %c", &char_array[i]) == 1)
            {
                break;
            }
            else
            {
                printf("Invalid input, please enter a single character.\n");
                clearBuffer();
            }
        }
        clearBuffer();
    }

    // Print results
    printf("\nInteger Array Values and Addresses:\n");
    for(int i = 0; i < INT_ARRAY_SIZE; i++)
    {
        ptr_int = &int_array[i];
        printf("Value: %d, Address: %p\n", int_array[i], (void*)ptr_int);
    }

    printf("\nCharacter Array Values and Addresses:\n");
    for(int i = 0; i < CHAR_ARRAY_SIZE; i++)
    {
        ptr_char = &char_array[i];
        printf("Value: %c, Address: %p\n", char_array[i], (void*)ptr_char);
    }

    return 0;
}