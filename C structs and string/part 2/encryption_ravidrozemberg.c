#include <stdio.h>
#include <string.h>
#define ARRAY_SIZE 26//Define the size of the array
/*------------------------------------------------------
* Filename: Encryption
* Description: A program that will receive an array of 26 integers, 
representing a ciphertext message that is encrypted according to
 the following rules:
• Each character is converted to its numeric value (int )
• Each element in the array is increased by 5
• Each element moves forward 4 cells, in a circular manner.
• Each element in an even position in the array is multiplied by 7
• Each element moves back 5 cells, in a circular manner.
• Each cell is increased by the value of the cell before it (except the first cell, which has no previous cell).
• Finally, the first and last halves of the array are swapped.
The program will print the plaintext message.

* Author: ravid rozemberg
-------------------------------------------------------*/

/*------------------------------------------------------
* Function Purpose - [to print the decrypted message from the encrypted array.] 
* Parameters –  [ IN arr[] - an array of integers.]
* Return Values - [void]
-------------------------------------------------------*/
void print_decrypted_message(int arr_in[])
{
    int n = ARRAY_SIZE;
    int arr[ARRAY_SIZE];
    int tmp[ARRAY_SIZE];
    int original[ARRAY_SIZE]; //used to hold originals when needed 

    // copy input 
    for (int i = 0; i < n; ++i) arr[i] = arr_in[i];

    // swap halves back (reverse of final swap) 
    {
        int half = n / 2;
        for (int i = 0; i < half; ++i) {
            tmp[i] = arr[i + half];
            tmp[i + half] = arr[i];
        }
        for (int i = 0; i < n; ++i) arr[i] = tmp[i];
    }

    //Undo "each cell increased by previous".Use a copy of arr (original) so we subtract original values, because encryption was done in-place (cumulative).

    for (int i = 0; i < n; ++i) original[i] = arr[i];  //copy originals 
    for (int i = 1; i < n; ++i) {
        arr[i] = original[i] - original[i - 1];
    }
    //arr[0] stays original[0] 
    arr[0] = original[0];

    //Undo "element moves back 5" -> do forward 5 
    for (int i = 0; i < n; ++i) {
        tmp[(i + 5) % n] = arr[i];
    }
    for (int i = 0; i < n; ++i) arr[i] = tmp[i];

    //Undo "multiply even positions by 7" -> divide by 7 (check divisibility) 
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            if (arr[i] % 7 != 0) {
                printf("Error: arr[%d] = %d not divisible by 7. Decryption aborted.\n", i, arr[i]);
                return;
            }
            arr[i] = arr[i] / 7;
        }
    }

    //Undo "element moves forward 4" -> move back 4 
    for (int i = 0; i < n; ++i) {
        tmp[(i - 4 + n) % n] = arr[i];
    }
    for (int i = 0; i < n; ++i) arr[i] = tmp[i];

    //Undo "+5" 
    for (int i = 0; i < n; ++i) arr[i] = arr[i] - 5;

    //Convert to chars and print (null terminate) 
    char decrypted[ARRAY_SIZE + 1];
    for (int i = 0; i < n; ++i) decrypted[i] = (char)arr[i];
    decrypted[n] = '\0';

    printf("The decrypted message is: %s\n", decrypted);
}
int main()
{
    int encrypted_array[ARRAY_SIZE];
    printf("Enter 26 integers for the encrypted message:\n");
    for(int i = 0; i < ARRAY_SIZE; i++) // Loop to read 26 integers from user
    {
        scanf("%d", &encrypted_array[i]);
    }
    print_decrypted_message(encrypted_array);//Call the function to print the decrypted message
    return 0;
}
