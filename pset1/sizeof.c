#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c;
    double d;
    float f;
    int i;
    
    printf("char: %i bytes\n", sizeof(c));
    printf("double: %i bytes\n", sizeof(d));
    printf("float: %i bytes\n", sizeof(f));
    printf("int: %i bytes\n", sizeof(i));
    
}
