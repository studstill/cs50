#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height; // Height of Mario's tower

    do
    {
        printf("\nLet's build Mario's tower!  You must select the height!\n"
        "Please choose a number between 1 and 23\n");
        height = GetInt(); //User inputs height for tower
    } 
    while (height < 0 || height > 23);
    
    int spaces = (height - 1); // Initial number of spaces before "bricks" (#) in tower
        
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < spaces; j++) //Insert appropriate number of spaces
        {
            printf(" ");
        }
        
        for (int k = 0; k <= i+1 ; k++) //Build tower, starting with 2 blocks (#)
        {
            printf("#");
        }
        
        printf("\n");
        spaces--;
     }       
}


