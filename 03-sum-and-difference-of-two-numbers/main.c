#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    // variable declaration
    int firstIntNumber = 0, secondIntNumber = 0;
    float firstFltNumber = 0, secondFltNumber = 0;

    // obtain user input
    scanf("%d %d", &firstIntNumber, &secondIntNumber);
    scanf("%f %f", &firstFltNumber, &secondFltNumber);

    // print sum and difference of the two int variables on a new line
    printf("%d %d\n", firstIntNumber + secondIntNumber, firstIntNumber - secondIntNumber);

    // print sum and difference of the two float variables on a new line
    printf("%2.1f %2.1f\n", firstFltNumber + secondFltNumber, firstFltNumber - secondFltNumber);

    return 0;
}