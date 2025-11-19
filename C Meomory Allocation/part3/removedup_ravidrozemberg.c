#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE_OF_ARRAY 100
/*------------------------------------------------------
* Filename: Remove Duplicates
* Description: The program defines three functions to remove duplicate integers from an array using different approaches:
1. remove_dup_1: Returns a new array with duplicates removed and updates the new size via a pointer.
2. remove_dup_2: Returns the new size and updates the new array via a pointer to pointer.
3. remove_dup_3: Updates both the new array and new size via pointers.
The main function demonstrates the usage of these functions by reading an array from user input,
calling each function, and printing the results.    
* author: Ravid Rozemberg
-------------------------------------------------------*/
int *(remove_dup_1(int arr[], int size, int *new_size))// return the adress of the new array and store the new size in new_size
{
    int *temp = (int *)malloc(size * sizeof(int));
    if(temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(-1);
    }
    int j = 0;
    for(int i = 0; i < size; i++)
    {
        int is_duplicate = 0;
        for(int k = 0; k < j; k++)
        {
            if(arr[i] == temp[k])
            {
                is_duplicate = 1;
                break;
            }
        }
        if(!is_duplicate)
        {
            temp[j++] = arr[i];
        }
    }
    *new_size = j;
    int *result = (int *)malloc(j * sizeof(int));
    if(result == NULL)
    {
        printf("Memory allocation failed\n");
        free(temp);
        exit(-1);
    }
    for(int i = 0; i < j; i++)
    {
        result[i] = temp[i];
    }
    free(temp);
    return result;
}
int remove_dup_2(int arr[], int size, int *new_size)//return the new size and store the adress of the new array in the pointer to pointer   
{
    int *temp = (int *)malloc(size * sizeof(int));
    if(temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(-1);
    }
    int j = 0;
    for(int i = 0; i < size; i++)
    {
        int is_duplicate = 0;
        for(int k = 0; k < j; k++)
        {
            if(arr[i] == temp[k])
            {
                is_duplicate = 1;
                break;
            }
        }
        if(!is_duplicate)
        {
            temp[j++] = arr[i];
        }
    }
    *new_size = j;
    int *result = (int *)malloc(j * sizeof(int));
    if(result == NULL)
    {
        printf("Memory allocation failed\n");
        free(temp);
        exit(-1);
    }
    for(int i = 0; i < j; i++)
    {
        result[i] = temp[i];
    }
    free(temp);
    return j;
}
void remove_dup_3(int arr[], int size, int **new_arr, int *new_size)// store the adress of the new array in the pointer to pointer and the new size in new_size
{
    int *temp = (int *)malloc(size * sizeof(int));
    if(temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(-1);
    }
    int j = 0;
    for(int i = 0; i < size; i++)
    {
        int is_duplicate = 0;
        for(int k = 0; k < j; k++)
        {
            if(arr[i] == temp[k])
            {
                is_duplicate = 1;
                break;
            }
        }
        if(!is_duplicate)
        {
            temp[j++] = arr[i];
        }
    }
    *new_size = j;
    int *result = (int *)malloc(j * sizeof(int));
    if(result == NULL)
    {
        printf("Memory allocation failed\n");
        free(temp);
        exit(-1);
    }
    for(int i = 0; i < j; i++)
    {
        result[i] = temp[i];
    }
    free(temp);
    *new_arr = result;
}
void print_array(int arr[], int size)// print the array values and adress
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[MAX_SIZE_OF_ARRAY];
    int size;
    printf("Enter the size of the array (max %d): ", MAX_SIZE_OF_ARRAY);
    scanf("%d", &size);
    if(size > MAX_SIZE_OF_ARRAY)
    {
        printf("Size exceeds maximum limit\n");
        return -1;
    }
    printf("Enter %d integers:\n", size);
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }    
    printf("Original array (size %d) with adress %p: ", size,(void*)arr);
    print_array(arr, size);
    int new_size1;
    int *new_arr1 = remove_dup_1(arr, size, &new_size1);
    printf("After remove_dup_1, new size: %d, with adress %p array: ", new_size1,(void*)new_arr1);
    print_array(new_arr1, new_size1);
    free(new_arr1); 
}

