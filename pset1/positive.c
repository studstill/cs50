#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {   
        printf("Please give me a positive integer.\n");
        n = GetInt();
    }
    while (n < 1);
    printf("Thanks for the positive integer!\n");
    
}
