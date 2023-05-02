#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    // variable declaration
    char *s;
    int i; // loop counter

    // read string from STDIN
    s = malloc(1024 * sizeof(char));
    if (s == NULL)
    {
        perror("malloc() failed");
        exit(1);
    }

    // read string from STDIN
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);

    // print each word in the senetence on a new line
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            // replace space with newline
            printf("\n");
        }
        else
        {
            // print character
            printf("%c", s[i]);
        }
    }

    return 0;
}