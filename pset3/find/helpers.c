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
        printf("the midpoint is %d\n", midpoint);
        return midpoint;
    }
    
    return -1;
}

int binarySearch(int key, int array[], int min, int max)
{
     
    if (max < min)
    {
        return -1;
    }
    else
    {
        int midpoint = findMidPoint(min, max);
        printf("this midpoint with in the binarySearch funciont is %d\n", midpoint);
        if (array[midpoint] < key)
        {
            binarySearch(key, array, midpoint + 1, max);
           
        }
        else if (array[midpoint] > key)
        {
            binarySearch(key, array, min, midpoint -1);
        }
        else
        {
            printf("key is found at the index %d, and is %d\n", midpoint, array[midpoint]);
            midpoint = array[midpoint];
            return array[midpoint];
        }


    printf("why does this print everytime?");
 //   printf("%d\n", midpoint);

      return -1;
      }
    
}

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // return false;
    
    // Return false if n is a negative int
    if (n < 0)
    {
        return false;
    }
    else
    {
        int ifFound = binarySearch(value, values, 0, n);
        printf("%d\n", ifFound);
        
        
        if (ifFound == value)
        {
            printf("it was found, see: %d\n", ifFound);
            return true;
        }
   
/*        // Linear Search O(n)        */
/*        for (int i = 0; i < n; i++)*/
/*        {*/
/*            if (values[i] == value)*/
/*            {*/
/*                return true;*/
/*            }*/
/*        }   */
        else
        {
        // Return false if value is not in the array values[]    
        return false;
        }
        
       // return 1;
       
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
    
    for (i = 0; i < n; i++)
    {
        printf("%d\n", values[i]);
    }
    return;
}
