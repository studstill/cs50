/***************************************************************************
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 ***************************************************************************/
 
// standard libraries
#define _XOPEN_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // Check for comand-line user input
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // Convert command-line input to an integer
    int n = atoi(argv[1]);

    // If supplied, ultize command-line "seed"
    // If not, use time as seed
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // Define an array
    int values[n];
    
    // Print n number of pseudo-random numbers
    for (int i = 0; i < n; i++)
    {
        values[i] = (int) (drand48() * LIMIT);
        // printf("%i\n", (int) (drand48() * LIMIT));
        printf("%i\n", values[i]);
    }
    
    // success
    return 0;
}
