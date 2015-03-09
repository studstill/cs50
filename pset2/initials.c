#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, char* argv[])
{
    for (int i = 0; i < argc; i++)
        printf("argv[%d] is: %s\n", i, argv[i]);
        
    printf("%d\n", argc);
    
    
    
    return 0;
}
