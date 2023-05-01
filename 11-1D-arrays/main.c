/**
 * \file		main.c
 * \since		01-May-2023
 * \author		Andrei Jakab
 */

//----------------------------------------------------------------------------------------------------------
//   								Includes
//----------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//----------------------------------------------------------------------------------------------------------
//   								Macros
//----------------------------------------------------------------------------------------------------------
// debug macros
#define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(x) printf x
#else
#define DEBUG_PRINT(x) \
    do                 \
    {                  \
    } while (0)
#endif

//----------------------------------------------------------------------------------------------------------
//   								Prototypes
//----------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------
//   								Code
//----------------------------------------------------------------------------------------------------------
int main()
{
    // variable declaration
    int i = 0;        // loop counter
    int n = 0;        // number of integers that will be scanned
    int *arr = NULL;  // array where the integers will be stored
    int arraySum = 0; // holds the sum of the array elements

    // read from STDIN number of integers that are to be stored and summed
    scanf("%d%*c", &n);

    // create dynamic array that will be used to store integers
    arr = (int *)calloc(n, sizeof(int));
    if (arr == NULL)
    {
        perror("malloc() failed");
        exit(1);
    }

    // read & store the integers in dynamic array
    for (i = 0; i < n; i++)
    {
        scanf("%d%*c", arr + i);
    }

    // sum array members
    arraySum = 0;
    for (i = 0; i < n; i++)
    {
        arraySum += arr[i];
    }

    // print sum of array members to STDOUT
    printf("%d\n", arraySum);

    // free dynamic array
    free(arr);

    return 0;
}