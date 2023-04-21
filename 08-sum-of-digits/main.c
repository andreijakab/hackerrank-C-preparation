#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n;
    scanf("%d", &n);

    // calculate the sum of the five digits of n
    int sumOfDigits = 0, divisor = 0;
    for (int index = 4; index >= 0; index--)
    {
        divisor = (int)pow(10, index);
        sumOfDigits += n / divisor;
        n %= divisor;
    }

    // display result
    printf("%d\n", sumOfDigits);

    return 0;
}