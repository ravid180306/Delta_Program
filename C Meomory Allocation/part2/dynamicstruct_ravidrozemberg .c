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

typedef struct {
    int hour;
    int minute;
    int second;
} Time;

// Allocate a Time on the heap and return pointer (exits on failure).
Time *alloc_time(void) {
    Time *t = malloc(sizeof *t);
    if (!t) {
        // Use only printf per your request
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    return t;
}

// Validate time fields: hour 0-23, minute 0-59, second 0-59.
int validate_time(const Time *t) {
    if (t->hour  < 0 || t->hour  > 23) return 0;
    if (t->minute < 0 || t->minute > 59) return 0;
    if (t->second < 0 || t->second > 59) return 0;
    return 1;
}

// Read a time from the user with prompt. Keeps asking until valid input provided.
// This function discards leftover input inline when scanf fails.
void read_time(const char *prompt, Time *t) {
    int rc;
    int c;
    while (1) {
        printf("%s", prompt);
        rc = scanf("%d %d %d", &t->hour, &t->minute, &t->second);
        if (rc != 3) {
            printf("Invalid input — please enter three integers (hour minute second).\n");
            // discard rest of line (we removed clear_stdin as requested)
            while ((c = getchar()) != '\n' && c != EOF) { /* discard */ }
            continue;
        }
        if (!validate_time(t)) {
            printf("Out of range. Hour must be 0..23, minute 0..59, second 0..59. Try again.\n");
            // If user entered numbers but out of range, there is likely a newline to consume; consume it just in case.
            while ((c = getchar()) != '\n' && c != EOF) { /* discard */ }
            continue;
        }
        // valid
        return;
    }
}

// Normalize values (roll seconds -> minutes, minutes -> hours).
void normalize_time(Time *t) {
    if (t->second >= 60) {
        t->minute += t->second / 60;
        t->second %= 60;
    } else if (t->second < 0) {
        int borrow = ( -t->second + 59 ) / 60;
        t->minute -= borrow;
        t->second += borrow * 60;
    }

    if (t->minute >= 60) {
        t->hour += t->minute / 60;
        t->minute %= 60;
    } else if (t->minute < 0) {
        int borrow = ( -t->minute + 59 ) / 60;
        t->hour -= borrow;
        t->minute += borrow * 60;
    }

    // hours left as-is (may be >= 24) to reflect total duration
}

// Add two times and return a newly allocated Time with the sum (normalized).
Time *add_times(const Time *a, const Time *b) {
    Time *res = alloc_time();
    res->second = a->second + b->second;
    res->minute = a->minute + b->minute;
    res->hour   = a->hour   + b->hour;
    normalize_time(res);
    return res;
}

// Print a Time in human-readable format.
void print_time(const char *prefix, const Time *t) {
    printf("%s%d hour(s), %d minute(s), %d second(s)\n",
           prefix, t->hour, t->minute, t->second);
}

int main(void) {
    // You can keep using malloc like below (as in your original), or
    // replace with automatic variables (Time s1, s2, s3;) and pass &s1, &s2, &s3 to functions.
    Time *s1 = alloc_time();
    Time *s2 = alloc_time();
    Time *s3 = NULL;

    read_time("Enter time for first struct (hour minute second): ", s1);
    read_time("Enter time for second struct (hour minute second): ", s2);

    s3 = add_times(s1, s2);

    print_time("Sum of times: ", s3);

    // free directly (removed free_time function as requested)
    free(s1);
    free(s2);
    free(s3);
    return 0;
}
  
