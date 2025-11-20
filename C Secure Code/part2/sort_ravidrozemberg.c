#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#define INITIAL_BUFFER_SIZE 10
/*------------------------------------------------------
* Func ename: sort
* Description:A generic sorting function (sort) using the bubble sort algorithm
 (which accepts an array of void variables, the size of the array, and a 
 pointer to a compare function that accepts 2 parameters and returns 
 a positive number if the first is greater, a negative number if the second
  is greater, and 0 when the values ​​are equal). 
  The sort function will sort the array according to the return values
  ​​of the compare function that it received as a parameter.
* Returns: pointer to the dynamically allocated string  
\*-------------------------------------------------------*/

void sort1(void *arr,  int elem_size, int (*compare_by_length)(const void *, const void *)) 
{
    int n = sizeof(arr) / elem_size;// Calculate number of elements in the array
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            void *elem1 = (char *)arr + j * elem_size;
            void *elem2 = (char *)arr + (j + 1) * elem_size;
            if (compare_by_length(elem1, elem2) > 0) 
            {
                // Swap elements
                char *temp = malloc(elem_size);
                if (temp == NULL) {
                    printf("Memory allocation failed\n");
                    exit(-1);
                }
                memcpy(temp, elem1, elem_size);
                memcpy(elem1, elem2, elem_size);
                memcpy(elem2, temp, elem_size);
                free(temp);
            }
        }
    }
}


void sort2(void *arr,  int elem_size, int (*compare_by_alpabetic_order)(const void *, const void *)) 
{
    int n = sizeof(arr) / elem_size;// Calculate number of elements in the array
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            void *elem1 = (char *)arr + j * elem_size;
            void *elem2 = (char *)arr + (j + 1) * elem_size;
            if (compare_by_alpabetic_order(elem1, elem2) > 0) 
            {
                // Swap elements
                char *temp = malloc(elem_size);
                if (temp == NULL) {
                    printf("Memory allocation failed\n");
                    exit(-1);
                }
                memcpy(temp, elem1, elem_size);
                memcpy(elem1, elem2, elem_size);
                memcpy(elem2, temp, elem_size);
                free(temp);
            }
        }
    }
}

/*------------------------------------------------------
* Func's name: compare_by_length, compare_by_alpabetic_order
* Description: Two comparison functions for sorting strings.
* compare_by_length: Compares two strings based on their lengths.
* compare_by_alpabetic_order: Compares two strings in alphabetical order.
* Returns: An integer indicating the comparison result.
\*-------------------------------------------------------*/

int compare_by_length(const void *a, const void *b) 
{
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;
    return strlen(str1) - strlen(str2);
}
int compare_by_alpabetic_order(const void *a, const void *b) 
{
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;
    return strcmp(str1, str2);
}

/*------------------------------------------------------
* Func ename: dyn_scanf
* Description: The function dynamically allocates memory to read a line of text from the user of arbitrary length.
It starts with an initial buffer size and expands it as needed while reading characters until a newline or EOF is encountered.
The function returns a pointer to the dynamically allocated string containing the user's input.
* Returns: pointer to the dynamically allocated string  
\*-------------------------------------------------------*/

char *dyn_scanf() 
{
   const char *prompt = "Enter a line of text: ";
    printf("%s", prompt);
    int capacity = INITIAL_BUFFER_SIZE;
    char *buffer = malloc(capacity);
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        exit(-1);
    }
    int length = 0;
    int c;
    while ((c = getchar()) != '\n' && c != EOF){
        // Resize buffer if needed
        if (length + 1 >= capacity) {
            capacity *= 2;
            char *temp = realloc(buffer, capacity);
            if (temp == NULL) {
                free(buffer);
                printf("Memory allocation failed\n");
                exit(-1);
            }
            buffer = temp;
        }
        buffer[length++] = (char)c;
    }
    buffer[length] = '\0'; // Null-terminate the string

    // Resize to exact size
    char *result = realloc(buffer, length + 1);//Insure that the allocated memory is exactly the size needed
    if (result == NULL) {
        free(buffer);
        printf("Memory allocation failed\n");
        exit(-1);
    }
    return result;
}

int main()
{
    char *ptr_arr[5];  // Array of 5 pointers to char
    char *temp[5];
   for (int i = 0; i < 5; i++) 
    {
       char *line = dyn_scanf();
     ptr_arr[i] = line;  // Store the pointer in the array
    }
    sort1(ptr_arr, sizeof(char *), compare_by_length);
    printf("Sorted by length:");
    for (int i = 0; i < 5; i++) 
    {
        printf("%s,", ptr_arr[i]);
    }
    sort2(ptr_arr, sizeof(char *), compare_by_alpabetic_order);
     printf(" \n ");
    printf("Sorted by alpabetic order:");
    for (int i = 0; i < 5; i++) 
    {
        printf("%s,", ptr_arr[i]);
    }
    for (int i = 0; i < 5; i++) 
    {
        free(ptr_arr[i]); // Free each dynamically allocated string
    }
    return 0;
}
  