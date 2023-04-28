#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

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

// Complete the following function.
void calculate_the_maximum(int n, int k)
{
    // variable declarations
    int i = 0, j = 0;                               // loop counters
    int maxAnd = 0, maxOr = 0, maxXor = 0;          // maximum comparison values
    int andResult = 0, orResult = 0, xorResult = 0; // comparison results

    // find maximums
    DEBUG_PRINT(("i\tj\t\tand\tor\txor\n"));
    for (i = 1; i < n; i++)
    {
        for (j = i + 1; j <= n; j++)
        {
            // calcalate result of bitwise operations
            andResult = i & j;
            orResult = i | j;
            xorResult = i ^ j;

            // determine if new maximum has been reached for and operation
            if (andResult < k && andResult > maxAnd)
                maxAnd = andResult;

            // determine if new maximum has been reached for or operation
            if (orResult < k && orResult > maxOr)
                maxOr = orResult;

            // determine if new maximum has been reached for xor operation
            if (xorResult < k && xorResult > maxXor)
                maxXor = xorResult;

            // output debug line
            DEBUG_PRINT(("%d\t%d\t\t%d\t%d\t%d\n", i, j, andResult, orResult, xorResult));
        }
    }

    // display results
    printf("%d\n", maxAnd);
    printf("%d\n", maxOr);
    printf("%d\n", maxXor);
}

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);

    return 0;
}
