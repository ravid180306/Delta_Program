/*------------------------------------------------------
* Func ename: dyn_scanf
* Description: The function dynamically allocates memory to read a line of text from the user of arbitrary length.
It starts with an initial buffer size and expands it as needed while reading characters until a newline or EOF is encountered.
The function returns a pointer to the dynamically allocated string containing the user's input.
* Returns: pointer to the dynamically allocated string  
\*-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#define INITIAL_BUFFER_SIZE 10
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
    while ((c = getchar()) != '\n' && c != EOF) {
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
    char *result = realloc(buffer, length + 1);
    if (result == NULL) {
        free(buffer);
        printf("Memory allocation failed\n");
        exit(-1);
    }
    return result;
}
/*------------------------------------------------------
* Filename: Dynamic Scanf
* Description: The program defines a function dyn_scanf that dynamically allocates memory to read a line of text from the user of arbitrary length.
It starts with an initial buffer size and expands it as needed while reading characters until a newline or EOF is encountered.
The function returns a pointer to the dynamically allocated string containing the user's input.
The main function demonstrates the usage of dyn_scanf by calling it, printing the entered line, and freeing the allocated memory.   
*author: Ravid Rozemberg
\*-------------------------------------------------------*/
int main()
{
    char *line = dyn_scanf();
   printf("You entered: \"%s\"\n",line);
    free(line);
    return 0;
}