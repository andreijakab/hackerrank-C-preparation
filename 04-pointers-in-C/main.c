#include <stdio.h>

void update(int *a, int *b)
{
    int aTemp = *a;

    // calculate sum and assign value to *a
    *a = *a + *b;

    // calculate differnece and assign value to *b
    if (aTemp > *b)
        *b = aTemp - *b;
    else
        *b = *b - aTemp;
}

int main()
{
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}