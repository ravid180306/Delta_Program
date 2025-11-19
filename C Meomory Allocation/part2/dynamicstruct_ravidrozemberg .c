/*------------------------------------------------------
* Filename: Dynamic Struct
* Description: The program defines a structure to hold information about time of day (hours, minutes, seconds).
  It dynamically allocates memory for three such structures, prompts the user to input time values for
  the first two structures, calculates the sum of these times, and stores the result in the third structure.
  Finally, it prints the summed time.    
* Author: Ravid Rozemberg
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

struct info_of_day_time {
    int hour;
    int minute;
    int second;
};

int main() {
    struct info_of_day_time *s1 = malloc(sizeof(struct info_of_day_time));
    struct info_of_day_time *s2 = malloc(sizeof(struct info_of_day_time));
    struct info_of_day_time *s3 = malloc(sizeof(struct info_of_day_time));

    if (!s1 || !s2 || !s3) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter time for first struct (hour minute second): ");
    scanf("%d %d %d", &s1->hour, &s1->minute, &s1->second);

    printf("Enter time for second struct (hour minute second): ");
    scanf("%d %d %d", &s2->hour, &s2->minute, &s2->second);

    // Calculate the total time
    s3->second = s1->second + s2->second;
    s3->minute = s1->minute + s2->minute + s3->second / 60;
    s3->hour   = s1->hour + s2->hour + s3->minute / 60;

    // Normalize values
    s3->second %= 60;
    s3->minute %= 60;

    printf("Sum of times: %d hour(s), %d minute(s), %d second(s)\n", s3->hour, s3->minute, s3->second);

    free(s1);
    free(s2);
    free(s3);

    return 0;
}
  
