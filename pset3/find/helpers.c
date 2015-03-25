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
#include <stdio.h>

#include "helpers.h"

int findMidPoint(int min, int max)
{
    int midpoint;
    
    if (max < min)
    {
        // Return error
        return -1;
    }
    else
    {
        // Find the midpoint at the position of the average of max and min
        midpoint = (max + min) / 2;
        return midpoint;
    }
    
    // Return error if midpoint cannot be found
    return -1;
}

int binarySearch(int key, int array[], int min, int max)
{
     
    // 
    if (max < min)
    {
        return -1;
    }
    else
    {
        int midpoint = findMidPoint(min, max);
        
        if (array[midpoint] < key)
        {
            return binarySearch(key, array, midpoint + 1, max);
           
        }
        else if (array[midpoint] > key)
        {
            return binarySearch(key, array, min, midpoint - 1);
        }
        else
        {
            // Return the value at the index of midpoint, which equals your key
            return array[midpoint];
        }

        // Return an error if key cannot be found in values[]
        return -1;
      } 
}

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // Return false if n is a negative int
    if (n < 0)
    {
        return false;
    }
    else
    {
        // Execute binarySearch and compare it to your value (key)
        if (binarySearch(value, values, 0, n) == value)
        {
            return true;
        }

        else
        {
        // Return false if value is not in the array values[]    
            return false;
        }
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // Implement Insertion Sort
    
    int i = 0;
    int j;
    int temp;
    int new_min;
    
    while (i < n)
    {
        j = i;
        new_min = values[i];
        
        while (j < n)
        {
            if (values[j] < new_min)
            {
                new_min = values[j];

                temp = values[i];
                values[i] = new_min;
                values[j] = temp;
                j++;
            }
            else
            {
                j++;
            }
        }
 
        i++;
    }

    return;
}
