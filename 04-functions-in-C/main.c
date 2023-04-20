#include <stdio.h>

int max_of_four(int a, int b, int c, int d)
{
    int ret = a;

    // check whether b is the largest value
    if (b > ret)
        ret = b;

    // check whether c is the largest value
    if (c > ret)
        ret = c;

    // check whether d is the largest value
    if (d > ret)
        ret = d;

    return ret;
}

int main()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);

    return 0;
}