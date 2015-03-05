#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Temperature in F:\n");
    float f = GetFloat();
    
    float c = 5.0 / 9.0 * (f - 32.0);
    
    printf("%.1f in Celcius\n", c);
    
}
    
