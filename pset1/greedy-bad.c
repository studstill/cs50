#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Define variable for storing the total amount of change owed
    float change;
    
    do
    {
        // Prompt user for a non-negative number
        printf("How much change is owed? $");
        change = ((GetFloat()) * 100);
    }
    while (change < 0);
    
    printf("\nHere is your change using the fewest possible coins:\n");
    
    if (change >= 25)
    {
        // Calculate quarters
        int quarters = (change / 25);
        printf("%d Quarters\n", quarters);
        change = change - (quarters * 25);
    }
    
    if (change >= 10)
    {
        // Calculate dimes
        int dimes = (change / 10);
        printf("%d Dimes\n", dimes);
        change = change - (dimes * 10);
    }
   
    if (change >= 05)
    {
        // Calculate nickels
        int nickels = (change / 5);
        printf("%d Nickels\n", nickels);
        change = change - (nickels * 5);  
    }
    
    if (change > 0)
    {
        // Calculate pennies
        int pennies = (change / 1);
        printf("%d Pennies\n", pennies);
        change = change - (pennies * 1);
    }
    
}

