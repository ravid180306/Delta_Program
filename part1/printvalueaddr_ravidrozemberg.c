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
int main()
{
    int int_array[INT_ARRAY_SIZE];
    char char_array[CHAR_ARRAY_SIZE];
    char *ptr_char;
    int *ptr_int;
    for(int i = 0; i < INT_ARRAY_SIZE; i++) // Loop to read integers into the integer array
    {
        printf("Enter integer %d: ", i + 1);
        scanf("%d", &int_array[i]);
    }
    for(int i = 0; i < CHAR_ARRAY_SIZE; i++) // Loop to read characters into the character array
    {
        printf("Enter character %d: ", i + 1);
        scanf(" %c", &char_array[i]);   
    }
    printf("\nInteger Array Values and Addresses:\n");
    for(int i = 0; i < INT_ARRAY_SIZE; i++) // Loop to print integer values and their addresses
    {
        ptr_int = &int_array[i];
        printf("Value: %d, Address: %p\n", int_array[i], (void*)ptr_int);
    }
    printf("\nCharacter Array Values and Addresses:\n");
    for(int i = 0; i < CHAR_ARRAY_SIZE; i++) // Loop to print character values and their addresses
    {
        ptr_char = &char_array[i];
        printf("Value: %c, Address: %p\n", char_array[i], (void*)ptr_char);
    }
    return 0;
}