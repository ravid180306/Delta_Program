/*------------------------------------------------------
* Filename: Coke_and_Roll.c
* Description: A program for encrypting messages in a vending machine 
* Author: Ravid Rosenberg & Benaya Yesha'ayahu Halevi
-------------------------------------------------------*/

#include <stdio.h>

// Define the number of the coins needed for the special message:
#define AGORA_FOR_SPECIAL_MESSAGE 1
#define TWO_SHEKELS_FOR_SPECIAL_MESSAGE 3
#define FIVE_SHEKELS_FOR_SPECIAL_MESSAGE 3
#define TEN_SHEKELS_FOR_SPECIAL_MESSAGE 7

// A function for print the main menu to the user:
void print_drinks(){
    printf("*************** Welcome to the drinks machine ***************\n");
    printf("Please select the drink you would like to order:\n");
    printf ("press 'C' for Coca-Cola\n");
    printf ("press 'D' for Diet-Cola\n");
    printf ("press 'O' for Orangeade\n");
    printf ("press 'S' for Schweppes\n");
    printf ("press 'G' for Grape juice\n");
    printf ("press 'W' for Mineral water\n");
}

// A function to get the price of the drink
float get_drink_price(char drink){
    switch (drink){
    case 'c':
    case 'C':
        return 5.20;
    case 'd':
    case 'D':
        return 7.20;
    case 'o':
    case 'O':
        return 3.40;
    case 's':
    case 'S':
        return 4.50;
    case 'g':
    case 'G':
        return 3.50;
    case 'w':
    case 'W':
        return 2.50;
    case 'e':
    case 'E':
        return 0;
    default:
        return -1;
    }
}

/* A function to get the payment from the user,
the parmater check if the drink is cola in case the special message should sended
return the accurate payment the user put in.*/
float get_payment(int is_it_cola){
    int agora = 0, half_shekel = 0, shekel = 0, two_shekels = 0, five_shekels = 0, ten_shekels = 0;
    float sum = 0;

    printf("Enter amount of 0.1 NIS: ");
    scanf("%d", &agora);
    printf("Enter amount of 0.5 NIS: ");
    scanf("%d", &half_shekel);
    printf("Enter amount of 1 NIS: ");
    scanf("%d", &shekel);
    printf("Enter amount of 2 NIS: ");
    scanf("%d", &two_shekels);
    printf("Enter amount of 5 NIS: ");
    scanf("%d", &five_shekels);
    printf("Enter amount of 10 NIS: ");
    scanf("%d", &ten_shekels);

    sum = agora * 0.1 + half_shekel * 0.5 + shekel * 1 + two_shekels * 2 + five_shekels * 5 + ten_shekels * 10;

    // If the special message should sended, return the negative of the payment:
    if(agora == AGORA_FOR_SPECIAL_MESSAGE &&
        two_shekels == TWO_SHEKELS_FOR_SPECIAL_MESSAGE &&
        five_shekels == FIVE_SHEKELS_FOR_SPECIAL_MESSAGE &&
        ten_shekels == TEN_SHEKELS_FOR_SPECIAL_MESSAGE &&
        is_it_cola){ return 0 - sum; }

    return sum;
}

// A function to print the exact change to the user:
void return_change(float drink_price, float payment){
    float change = 0, cumulative_change = 0;
    int agora = 0, half_shekel = 0, shekel = 0, two_shekels = 0, five_shekels = 0, ten_shekels = 0;
    
    change = payment - drink_price;
    
    while((ten_shekels + 1) * 10 <= change){ ten_shekels += 1; }
    cumulative_change += (ten_shekels * 10);
    while(cumulative_change + ((five_shekels + 1) * 5) <= change){ five_shekels += 1; }
    cumulative_change += (five_shekels * 5);
    while(cumulative_change + ((two_shekels + 1) * 2) <= change){ two_shekels += 1; }
    cumulative_change += (two_shekels * 2);
    while(cumulative_change + ((shekel + 1) * 1) <= change){ shekel += 1; }
    cumulative_change += (shekel * 1);
    while(cumulative_change + ((half_shekel + 1) * 0.5) <= change){ half_shekel += 1; }
    cumulative_change += (half_shekel * 0.5);
    while(cumulative_change + ((agora + 1) * 0.1) <= change){ agora += 1; }

    printf("Payment received.\n");

    printf("Machine returned %d coins of 0.1 NIS\n", agora);
    printf("Machine returned %d coins of 0.5 NIS\n", half_shekel);
    printf("Machine returned %d coins of 1 NIS\n", shekel);
    printf("Machine returned %d coins of 2 NIS\n", two_shekels);
    printf("Machine returned %d coins of 5 NIS\n", five_shekels);
    printf("Machine returned %d coins of 10 NIS\n\n", ten_shekels);
}

int main(){
    char drink = '\0';
    float drink_price = 0, payment = 0;
    
    print_drinks();
    scanf("%c", &drink);
    while(drink != 'E' &&  drink != 'e'){
        drink_price = get_drink_price(drink);
        if(drink_price == -1){
            printf("No such drink, try again!\n");
        }
        else if(drink_price == 0){ break; }
        else{
            printf("The price of the drink is %f NIS\n", drink_price);
            payment = get_payment(drink == 'C' || drink == 'c');
            
            if(payment < 0){
                printf("Spacial agent, please respond!\n");
                // Set the payment to possitive value:
                payment += ((0 - payment) * 2);
            }

            else if(payment < drink_price){
                 printf("You didn't put in enough money!\n\n");
            }

            if(payment >= drink_price){
                printf("Enjoy your drink!\n");
                return_change(drink_price, payment);
            }
        }

        print_drinks();
        while (getchar() != '\n'); 
        scanf("%c", &drink);
    }

    return 0;
}