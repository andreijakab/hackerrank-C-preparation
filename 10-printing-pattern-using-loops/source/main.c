/**
 * \file		main.c
 * \since		21-Apr-2023
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
// macros for boolean data type
#define BOOL char /*!< Set the primitive data type */
#define TRUE 1    /*!< Define the numeric value of TRUE. */
#define FALSE 0   /*!< Define the numeric value of FALSE. */

//----------------------------------------------------------------------------------------------------------
//   								Data Structures
//----------------------------------------------------------------------------------------------------------
/**
 * Stores the coordinates of a point.
 */
typedef struct
{
    int x; ///< x coordinate
    int y; ///< y coordinate
} point;

/**
 * Stores the coordinates of a square.
 */
typedef struct
{
    point topLeft;     ///< top left corner
    point bottomRight; ///< bottom right corner
} square;

//----------------------------------------------------------------------------------------------------------
//   								Prototypes
//----------------------------------------------------------------------------------------------------------
square calculateSquareCoordinates(int, int);
int getLevel(point, int, int, int);
BOOL isPointOnSquare(point, square);

//----------------------------------------------------------------------------------------------------------
//   								Code
//----------------------------------------------------------------------------------------------------------
/**
 * \brief		Program entry point.
 *
 * \return		0
 */
int main()
{
    // read max level from user
    int n;
    scanf("%d", &n);

    // calculate size of the number matrix to be printed
    int matrixSize = 2 * n - 1;

    // print number matrix
    int currentLevel;
    point currentPoint;
    for (int y = 1; y <= matrixSize; y++)
    {
        currentLevel = n;
        for (int x = 1; x <= matrixSize; x++)
        {
            // set current point
            currentPoint.x = x;
            currentPoint.y = y;

            // print the appropriate number
            currentLevel = getLevel(currentPoint, currentLevel, n, matrixSize);
            printf("%d", currentLevel);

            // print the appropriate whitespace character
            if (currentPoint.x != matrixSize)
            {
                printf(" ");
            }
            else
            {
                printf("\n");
            }
        }
    }

    return 0;
}

/**
 * \brief		Calculate the coordinates of the square associated with the given matrix level.
 *
 * \param[in]	currentLevel	level within the number matrix
 * \param[in]	maxLevel	    maximum level entered by the user
 *
 * \return		Coordinates of the square.
 */
square calculateSquareCoordinates(int currentLevel, int maxLevel)
{
    square currentSquare;

    currentSquare.topLeft.x = currentSquare.topLeft.y = maxLevel - currentLevel + 1;
    currentSquare.bottomRight.x = currentSquare.bottomRight.y = currentSquare.topLeft.x + 2 * currentLevel - 2;

    return currentSquare;
}

/**
 * \brief		Detemines the numeric level associated with a given point within the number matrix.
 *
 * \param[in]	currentPoint	point the level of which is to be determined
 * \param[in]	currentLevel	current level within the number matrix
 * \param[in]	maxLevel	    maximum level entered by the user
 * \param[in]	matrixSize	    size of the number matrix
 *
 * \return		Level associated with the point.
 */
int getLevel(point currentPoint, int currentLevel, int maxLevel, int matrixSize)
{
    square currentSquare;

    // get coordinates of squre associated with current level
    currentSquare = calculateSquareCoordinates(currentLevel, maxLevel);

    // check whether level has changed
    if (isPointOnSquare(currentPoint, currentSquare))
    {
        // point is on square => level is the same
        return currentLevel;
    }
    else
    {
        // point is not on square => level has changed
        if (currentPoint.x <= ((int)round(matrixSize / 2.0)))
        {
            // point's x coordinate is before the matrix' center => level has decreased
            return --currentLevel;
        }
        else
        {
            // point's x coordinate is after the matrix' center => level has increased
            return ++currentLevel;
        }
    }
}

/**
 * \brief		Checks whether a point is on a square.
 *
 * \param[in]	pointToCheck    point that needs to be checked
 * \param[in]	square          square to be used during check
 *
 * \return		TRUE if point is on the square, FALSE otherwise.
 */
BOOL isPointOnSquare(point pointToCheck, square currentSquare)
{
    BOOL retValue;

    if (((pointToCheck.x == currentSquare.topLeft.x) && (pointToCheck.y >= currentSquare.topLeft.y) && (pointToCheck.y <= currentSquare.bottomRight.y)) ||
        ((pointToCheck.x == currentSquare.bottomRight.x) && (pointToCheck.y >= currentSquare.topLeft.y) && (pointToCheck.y <= currentSquare.bottomRight.y)) ||
        ((pointToCheck.y == currentSquare.topLeft.y) && (pointToCheck.x >= currentSquare.topLeft.x) && (pointToCheck.x <= currentSquare.bottomRight.x)) ||
        ((pointToCheck.y == currentSquare.bottomRight.y) && (pointToCheck.x >= currentSquare.topLeft.x) && (pointToCheck.x <= currentSquare.bottomRight.x)))
    {
        retValue = TRUE;
    }
    else
    {
        retValue = FALSE;
    }

    return retValue;
}
