#include <stdio.h>
#include <stdlib.h>

int main()
{
    // variable declaration
    int num;            // number of array elements
    int *originalArray; // pointer to original array
    int *reversedArray; // pointer to reversed array
    int i;              // loop counter

    // read number of array elements
    scanf("%d", &num);

    // allocate memory for original array
    originalArray = (int *)malloc(num * sizeof(int));
    if (originalArray == NULL)
    {
        perror("malloc() failed");
        exit(1);
    }

    // read array from STDIN
    for (i = 0; i < num; i++)
    {
        scanf("%d", originalArray + i);
    }

    // allocate memory for reversed array
    reversedArray = (int *)malloc(num * sizeof(int));
    if (reversedArray == NULL)
    {
        perror("malloc() failed");
        exit(1);
    }

    // reverse the array
    for (i = 0; i < num; i++)
    {
        reversedArray[i] = originalArray[num - i - 1];
    }

    // print reversed array to STDOUT
    for (i = 0; i < num; i++)
        printf("%d ", *(reversedArray + i));

    // free allocated memory
    free(originalArray);
    free(reversedArray);

    return 0;
}