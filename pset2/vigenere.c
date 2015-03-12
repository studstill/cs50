#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argv[1] != NULL)
    {
        // Store command-line input as key
        string key = argv[1];

        // Define key length
        int key_length = strlen(key);
        // Define new_key variable for computation later
        int new_key = 0;
        
        // Declare variables to check boolean conditions
        int two_args = 0;
        int only_alpha = 0;

        // Check that there are only 2 command-line arguements
        if (argc == 2)
        {
            two_args = 1;
        }
        
        // Ensure that command-line input is only letters
        for (int i = 0, n = strlen(key); i < n; i++)
        {
            if (isalpha(argv[1][i]))
            {
                only_alpha = 1;
            }  
            else
            {
                printf("Please enter a alpha keyword as your only"
                " command-line arguemnet\n");
                return 1;
            }   
        }

       // Run program if conditions are true
        if (two_args && only_alpha)
        {
            // Get input from user
            string plain_text = GetString();

            // Define variables for iteration during while loop
            int i = 0;
            int j = 0;
            int n = strlen(plain_text);
                        
            // Carry out encryption
            while (i < n)
            {
                // Run this code is input char is a letter
                if (isalpha(plain_text[i]))
                {               
                    new_key = j % key_length;
                    int shift = 0;
                    
                    // Run this is key char is upper case
                    if (isupper(key[new_key]))
                    {
                        shift = key[new_key] - 65;
                    }
                    // Run this is key char is lower case
                    else
                    {
                        shift = key[new_key] - 97;
                    }                    
                    
                    // Apply rules if plain_text char is upper case
                    if (isupper(plain_text[i]))
                    {
                        // Zero index upper case input; Determine shift
                        int index = (((plain_text[i] - 65) + shift) % 26);
                        // Apply shift to capital letter
                        int letter = index + 65;
                        printf("%c", letter);
                    }
                    
                    // Apply rules if letter is lower case
                    else
                    {
                        // Zero index lower-case input; Determine shift
                        int index = (((plain_text[i] - 97) + shift) % 26);
                        // Apply shift to lower case letter
                        int letter = index + 97;
                        printf("%c", letter);
                    }
                    
                    i++;
                    j++;
                }
                
                // Run this code if input char is not a letter
                else
                {
                    printf("%c", plain_text[i]);
                    i++;
                }
            }
            
            printf("\n");
     
        }
       
        // Usage instructions
         else
        {
            printf("Please run the program again and include only one word "
            "or one string of letters as your command line arguement\n");
            return 1;
        }
    }
    
    // Usage instructions
    else
    {
        printf("Please run the program again and include only one word "
        "or one string of letters as your command line arguement\n");
        return 1;
    }
}
