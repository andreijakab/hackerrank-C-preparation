#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int a, b;
    scanf("%d\n%d", &a, &b);

    // Complete the code.
    for (int index = a; index <= b; index++)
    {
        if (index == 1)
        {
            printf("one\n");
        }
        else if (index == 2)
        {
            printf("two\n");
        }
        else if (index == 3)
        {
            printf("three\n");
        }
        else if (index == 4)
        {
            printf("four\n");
        }
        else if (index == 5)
        {
            printf("five\n");
        }
        else if (index == 6)
        {
            printf("six\n");
        }
        else if (index == 7)
        {
            printf("seven\n");
        }
        else if (index == 8)
        {
            printf("eight\n");
        }
        else if (index == 9)
        {
            printf("nine\n");
        }
        else
        {
            if (index % 2 == 0)
            {
                printf("even\n");
            }
            else
            {
                printf("odd\n");
            }
        }
    }

    return 0;
}
