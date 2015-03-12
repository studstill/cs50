#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argv[1] != NULL)
    {
        // Convert command-line input from string to int.
        int key = atoi(argv[1]);
        
        // Declare variables to check boolean conditions
        int two_args = 0;
        int pos_int = 0;

        // Check that there are only 2 comand-line arguements
        if (argc == 2)
        {
            two_args = 1;
        }
        
        // Check for positive int
        if (key > 0)
        {
            pos_int = 1;
        }
        
       // Run program if conditions are true
        if (two_args && pos_int)
        {
            // Get input from user
            string plain_text = GetString();
            
            // Carry out encryption
            for (int i = 0, n = strlen(plain_text); i < n; i++)
            {
                // Check that input is a letter
                if (isalpha(plain_text[i]))
                {
                    // Apply rules if letter is upper case
                    if (isupper(plain_text[i]))
                    {
                        // Zero index capitalized input; Determine shift
                        int shift = (((plain_text[i] - 65) + key) % 26);
                        // Apply shift to capital letter
                        int letter = shift + 65;
                        printf("%c", letter);
                    }
                    
                    // Apply rules if letter is lower case
                    else
                    {
                        // Zero index lower-case input; Determine shift
                        int shift = (((plain_text[i] - 97) + key) % 26);
                        // Apply shift to lower case letter
                        int letter = shift + 97;
                        printf("%c", letter);
                    }
                }
                
                // Print other input as written
                else
                {
                    printf("%c", plain_text[i]);
                }
            }
            
            printf("\n");
     
        }
       
        // Usage instructions
         else
        {
            printf("Please run the program again and include a positive int "
            "as your second command-line arguement\n");
            return 1;
        }
    }
    
    // Usage instructions
    else
    {
        printf("Please run the program again and include a positive int "
        "as your second command-line arguement\n");
        return 1;
    }
}
