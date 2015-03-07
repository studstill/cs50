#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(int argc, string argv[])
{
    // Define variable for storing the total amount of change owed
    float change;
    
    do
    {
        // Prompt user for a non-negative number
        printf("How much change is owed? $");
        change = GetFloat();
        
        // Multiply by 100 to do calculations with ints instead of floats 
        change = change * 100;
        
        // Round change to alleviate float imprecision
        change = round(change);
 
    }
    while (change < 0);
    
    while (change >= 1)
    {
        // Calculate quarters
        int quarters = (change / 25);
        change = change - (quarters * 25);
    
        // Calculate dimes
        int dimes = (change / 10);
        change = change - (dimes * 10);
   
        // Calculate nickels
        int nickels = (change / 5);
        change = change - (nickels * 5);  
    
        // Calculate pennies
        int pennies = (change / 1);
        change = change - (pennies * 1);
        
        // Print the total number of coins that are used
        printf("%d\n", quarters + dimes + nickels + pennies);
    }
}

