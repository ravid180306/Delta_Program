/*------------------------------------------------------
* Filename: Median
* Description: The program sequentially receives an unknown number of integers (of type int), until
it receives an input that is not a number, and prints all the numbers received. 
The program finds the median of all these numbers and prints it.

Highlights:
• It is mandatory to use pointers and memory management functions.
• It is mandatory to check the return values ​​of memory management functions.
• It is mandatory to initialize new pointers with NULL or with a real address.
• The code must be divided into appropriate functions.

* Author: ravid rozemberg
\*-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#define INITIAL_ARRAY_SIZE 10
/*------------------------------------------------------
* Func ename: calc_median
* Description: The function calculates the median of an array of integers.
* Parameters:
- arr: pointer to the array of integers
- size: number of elements in the array
* Returns: the median value as a double
\*-------------------------------------------------------*/
double calc_median(int *arr, int size)
{   
    // Sort the array using bubble sort
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    // Calculate median
    if(size % 2 == 0)
    {
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    }
    else
    {
        return arr[size / 2];
    }
}
void memory_allocation_error()
{
    printf("Memory allocation failed\n");
    exit(-1);
}
void reallocate_memory(int **arr, int *capacity)
{
    *capacity *= 2;
    int *temp = (int *)realloc(*arr, (*capacity) * sizeof(int));
    if(temp == NULL)
    {
        memory_allocation_error();
    }
    *arr = temp;
}


int main() 
{
    int *arr = NULL;
    int size = 0;
    int capacity = INITIAL_ARRAY_SIZE;
    arr = (int *)malloc(capacity * sizeof(int));
    if(arr == NULL)
    {
        memory_allocation_error();
    }
    printf("Enter integers (non-integer to stop):\n");
    while(1)
    {
        int num;
        if(scanf("%d", &num) != 1)
        {
            break;
        }
        if(size >= capacity)
        {
            reallocate_memory(&arr, &capacity);
        }
        arr[size++] = num;
    }
    printf("You entered:\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    double median = calc_median(arr, size);
    printf("Median: %.2f\n", median);
    free(arr);  
    return 0;
} 