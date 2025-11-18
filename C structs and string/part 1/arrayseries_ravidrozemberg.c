#include <stdio.h>
/*------------------------------------------------------
* Filename: [Array Series]
* Description: [The program receives an array of 15 numbers.
The program will determine which of the above definitions the array meets, and print one of the following
messages:
"The array is increasing"
"The array is decreasing"
"The array is constant"
"The array is messed up"]
* Author: [ravid rozemberg]
-------------------------------------------------------*/
/*------------------------------------------------------
*
* Function Purpose - [to check if the array is strictly increasing.] 
*
* Parameters –  [ IN arr[] - an array of integers.
                 IN size - the size of the array.]
* Return Values - [Returns 0 if the array is increasing, otherwise returns a non-zero value.]
*
-------------------------------------------------------*/
int check_increasing(int arr[], int size)
{
    int index_accurcy_of_increasing=0;//Index to return an integer value of if increasing or not
    for(int i = 0; i < size - 1; i++)
    {
        if(arr[i] > arr[i + 1])// If the current element is not less than the next
        {
            index_accurcy_of_increasing++;
        }
    }
    return index_accurcy_of_increasing;
}
/*------------------------------------------------------
* Function Purpose - [to check if the array is strictly decreasing.] 
*
* Parameters –  [ IN arr[] - an array of integers.
                 IN size - the size of the array.]
* Return Values - [Returns 0 if the array is decreasing, otherwise returns a non-zero value.]
-------------------------------------------------------*/
int check_decreasing(int arr[], int size)
{
     int index_accurcy_of_decreasing=0;//Index to return an integer value of if decreasing or not
    for(int i = 0; i < size - 1; i++)
    {
        if(arr[i] < arr[i + 1])// If the current element is not greater than the next
        {
           index_accurcy_of_decreasing=0;
        }
        else{
              index_accurcy_of_decreasing=1;
        }
    }
    return index_accurcy_of_decreasing;
}
/*------------------------------------------------------
* Function Name - [check_constant] 
*  
* Function Purpose - [to check if the array is constant.]
*
* Parameters –  [ IN arr[] - an array of integers.
                 IN size - the size of the array.]
* Return Values - [Returns 0 if the array is constant, otherwise returns a non-zero value.]
 
-------------------------------------------------------*/

int check_constant(int arr[], int size)
{
     int index_accurcy_of_const=0;//Index to return an integer value of if const or not
    for(int i = 0; i < size - 1; i++)// If the current element is not equal to the next
    {
        if(arr[i] != arr[i + 1])
        {
            index_accurcy_of_const=0;   
        }
        else{
              index_accurcy_of_const=1;
        }   
    }
    return index_accurcy_of_const;
}
/*------------------------------------------------------
* Function Name - [check_messy] 
*
* Function Purpose - [to check if the array is messy.] 
*
* Parameters –  [ IN arr[] - an array of integers.
                 IN size - the size of the array.]
* Return Values - [Returns 0 if the array is messy, otherwise returns a non-zero value.]
-------------------------------------------------------*/
int check_messy(int arr[], int size)
{
     int index_accurcy_of_messy=0;//Index to return an integer value of if messy or not
    for(int i = 0; i < size - 1; i++)
    {
        if((arr[i+1] >= arr[i + 2] && arr[i] <= arr[i + 1]) || (arr[i+1] <= arr[i + 2] && arr[i] >= arr[i + 1]))// If the array is neither increasing, decreasing, nor constant
        {
           index_accurcy_of_messy=0;
        }
        else{
              index_accurcy_of_messy=1;
        }
    }
   return index_accurcy_of_messy;
}
void print_final_state_of_array(int arr[], int size)
{
    int increasing = check_increasing(arr, size);
    int decreasing = check_decreasing(arr, size);
    int constant = check_constant(arr, size);
    if(increasing == 0)
    {
        printf("The array is increasing\n");
        return;
    }
    if(decreasing == 0)
    {
        printf("The array is decreasing\n");
        return; 
    }
    if(constant == 0)
    {
        printf("The array is constant\n");
        return;
    }
    printf("The array is messed up\n");

}
int main()
{
    int arr[15];// Declare an array of 15 integers
    printf("Enter 15 integers for the array:\n");
    for(int i = 0; i < 15; i++) // Loop to read 15 integers from user
    {
        scanf("%d", &arr[i]);
    }
    print_final_state_of_array(arr, 15);// Call the function to print the final state of the array
    return 0;
}