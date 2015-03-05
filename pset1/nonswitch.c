#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Please give me an int between 1 and 10.\n");
    int n = GetInt();
    
    if (n >= 0 && n < 4)
    {
        printf("You picked a small int!\n");
    }
    else if (n > 3 && n < 8)
    {
        printf("You picked a medium int!.\n");
    }
    else if (n > 7 && n <= 10)
    {
        printf("You picked a large int!\n");
    }
    else
    {
        printf("You picked an invalid int!\n");
    }    
}
