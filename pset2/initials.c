#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // Get user's name
    string name = GetString();   
    
    // Initialize iterator to zero
    int i = 0;
    
    // Declare and get the length of user's name
    int stringLength = strlen(name);
        
    // Check to make sure there are no spaces before user's name
    if (name[i] != ' ')
    {
        printf("%c", toupper(name[i]));
    }
        
    // Check string for spaces; Print the next character upper case.
    while (i < stringLength)
    {
        if (name[i] == ' ')
        {
            // Capitalize and print the first char following a space
            printf("%c", toupper(name[i + 1]));
            i++;
        }
        else
        {
            i++;
        }
    
    }      
    
    printf("\n");
    
}
