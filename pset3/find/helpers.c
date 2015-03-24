/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <string.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // Return false is n is a negative int
    if (n < 1)
    {
        return false;
    }
    
    // Iterate through every position in values[]
    // Return true if value is found
    for (int i = 0; i < n; i++)
    {
        if (values[i] == value)
        {
            return true;
        }

    }
    // Return false if value is not in the array values[]    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    return;
}
