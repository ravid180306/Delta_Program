/*------------------------------------------------------
* Filename: Array Sort
* Description:The program defines an array of size 10 of ints, 
and another array of size 10 of pointers to ints, 
which will be filled with the addresses of all the ints 
in the first array (in order). 
The program then receives 10 values ​​from the user to initialize the first array.
 After receiving the values, the program must sort the second array so that 
 the pointer in the first place points to the smallest value in the first array, 
 the second pointer points to the second smallest value in the first array, 
 and so on until the tenth pointer points to the largest value in the first array.
* Author: ravid rozemberg 
-------------------------------------------------------*/
#include <stdio.h>
#define ARRAY_SIZE 10
/*------------------------------------------------------
* Function Purpose - [to fill the pointer array with addresses of the integer array.]
* Parameters –  [ IN arr[] - an array of integers.
                 IN size - the size of the array.
                 OUT ptr_arr[] - an array of pointers to integers.]
* Return Values - [Returns the pointer array filled with addresses of the integer array.]
-------------------------------------------------------*/
void fill_adress_of_array(int arr[], int size, int *ptr_arr[])
{
    for(int i = 0; i < size; i++) // Loop to fill the pointer array with addresses of the integer array
    {
        ptr_arr[i] = &arr[i];
    }
}
/*------------------------------------------------------
* Function Purpose - [to swap two integer pointers.]
* Parameters –  [ IN OUT a - pointer to an integer pointer.
                 IN OUT b - pointer to an integer pointer.]
* Return Values - [void]
-------------------------------------------------------*/
void swap(int **a, int **b)
{
    int *temp = *a;
    *a = *b;
    *b = temp;
}
/*------------------------------------------------------
* Function Purpose - [to sort the pointer array based on the values they point to in ascending order.]
* Parameters –  [ IN OUT ptr_arr[] - an array of pointers to integers.
                 IN size - the size of the array.]  
* Return Values - [void]
-------------------------------------------------------*/
void sort_and_print_pointer_array_adress(int *ptr_arr[], int size,int position[],int arr[])
{
    for(int i = 0; i < size; i++) // Print the pointer array before sorting
    {
        printf("Pointer %d points to address: %p with value: %d\n", i + 1, (void*)ptr_arr[i], *ptr_arr[i]);
    }
    printf("\nSorting the pointer array based on the values they point to...\n\n");
     // Sort ONLY the pointer array
    for (int i = 0; i < 10; i++) 
    {
        for (int j = i + 1; j < 10; j++) 
        {
            if (*ptr_arr[j] < *ptr_arr[i]) 
            {
                int* temp = ptr_arr[i];
                ptr_arr[i] = ptr_arr[j];
                ptr_arr[j] = temp;
            }
        }
    }

    // Build position[] so we know where each original element ended up
    for (int i = 0; i < 10; i++) 
    {
        for (int j = 0; j < 10; j++) 
        {
            if (ptr_arr[j] == &arr[i]) 
            {
                position[i] = j;   // ptrs[j] points to arr[i]
                break;
            }
        }
    }

    // Print original array with new pointer positions
    printf("\nOriginal array with new pointer positions:\n");
    for (int i = 0; i < 10; i++) 
    {
        printf("arr[%d] = %d  →  pointer sorted index = %d\n",
               i, arr[i], position[i]);
    }
}
int main()
{
    int arr[ARRAY_SIZE]; // Declare an array of integers
    int *ptr_arr[ARRAY_SIZE]; // Declare an array of pointers to integers
    int position[ARRAY_SIZE]; // Array to hold the new positions of original elements

    printf("Enter %d integers for the array:\n", ARRAY_SIZE);
    for(int i = 0; i < ARRAY_SIZE; i++) // Loop to read integers from user
    {
        scanf("%d", &arr[i]);
    }

    fill_adress_of_array(arr, ARRAY_SIZE, ptr_arr); // Fill the pointer array with addresses of the integer array
    sort_and_print_pointer_array_adress(ptr_arr, ARRAY_SIZE,position,arr); // Sort and print the pointer array based on the values they point to

    return 0;
}