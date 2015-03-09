#include <stdio.h>
#include <cs50.h>
#include <string.h>

void printf_fudd_style(string s)
{
    int length = strlen(s);
    for (int i = 0; i < length; i++)
        if (s[i] == 'r')
            s[i] = 'w';
            
    printf("%s\n", s);
}

int main(void)
{
    printf("How are you going to get the wabbit?\n");
    
    string s = GetString();
    while (s != NULL)
    {
        printf_fudd_style(s);
        s = GetString();
    }
}
