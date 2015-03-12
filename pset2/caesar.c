#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argv[1] != NULL)
    {
        // Convert command-line input from string to int.  Variabe key gets resulting int
        int key = atoi(argv[1]);
        printf("The key is %d\n", key);
        key = key % 26;
        printf("The key is %d\n", key);
        
        // Declare variables to check boolean conditions
        int only_two_arguements = 0;
        int is_positive_int = 0;

        // Check that there are only 2 comand-line arguements
        if (argc == 2)
            only_two_arguements = 1;

        // Check for positive int
        if (key > 0)
            is_positive_int = 1;

       // Run program if conditions are true
        if (only_two_arguements && is_positive_int)
        {
            string plain_text = GetString();
            
            for (int i = 0, n = strlen(plain_text); i < n; i++)
            {
                if (isalpha(plain_text[i]))
                {
                    if (isupper(plain_text[i]))
                    {
                        int letter = (plain_text[i] + key);
                        printf("%c", letter);
                    }
                    else
                    {
                        int letter = (plain_text[i] + key);
                        printf("%c", letter);
                    }
                }
                else
                {
                    printf("%c", plain_text[i]);
                }
            }
            
            printf("\n");
     
        }

         else
        {
            printf("Please run the program again and include a positive int as your " 
            "second command-line arguement\n");
            return 1;
        }
    }
    else
    {
        printf("Please run the program again and include a positive int as your " 
        "second command-line arguement\n");
        return 1;
    }
}
