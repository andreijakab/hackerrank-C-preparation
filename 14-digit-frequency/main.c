/**
 * \file		main.c
 * \since		03-May-2023
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
// constants
#define STRING_LENGTH 1000 // maximum length of input string
#define ASCII_CODE_0 48    // ASCII code for the digit 0
#define ASCII_CODE_9 57    // ASCII code for the digit 9

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
//   								Code
//----------------------------------------------------------------------------------------------------------
int main()
{
    // variable declaration
    char currentCharacter;                                    // character of input string being checked
    char inputString[STRING_LENGTH];                          // input string
    char digitFrequency[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // digit frequencies
    int i = 0;                                                // loop counter
    // read input string from STDIN
    scanf("%s", inputString);
    DEBUG_PRINT(("Input string: %s\n", inputString));

    // iterate through each character of the string
    for (i = 0; i < strlen(inputString); i++)
    {
        currentCharacter = inputString[i];
        if (currentCharacter >= ASCII_CODE_0 && currentCharacter <= ASCII_CODE_9)
        {
            // increase array element in the digit frequency array
            digitFrequency[currentCharacter - ASCII_CODE_0] += 1;
        }
    }

    // display digit frequency
    for (i = 0; i < 10; i++)
    {
        printf("%d", digitFrequency[i]);
        if (i != 9)
        {
            printf(" ");
        }
        else
        {
            printf("\n");
        }
    }

    return 0;
}
