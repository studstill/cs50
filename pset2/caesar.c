#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    printf("%i\n", argc);
    
    if (argv[1] != NULL)
    {
        printf("%c\n", argv[1][0]);
        printf("%s\n", argv[1]);
    
    
        // Convert string inside argv[1] to an int
        int k = atoi(argv[1]);
        printf("%i\n", k);

        if (argc != 2)
        {
            printf("Please run the program again and include a positive int as your " 
            "second command-line arguement\n");
            return 1;
        }
        else if (argv[1][0] > '9')
        {
            printf("Please run the program again and include a positive int as your " 
            "second command-line arguement\n");
            return 1;
        }
        else if (argv[1][0] < '1')
        {
            printf("Please run the program again and include a positive int as your " 
            "second command-line arguement\n");
            return 1;  
        }
        else
        { 
            printf("You did it!\n");
            return 0;
        }
    }
}
