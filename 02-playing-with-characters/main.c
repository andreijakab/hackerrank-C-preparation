#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_LEN 100

int main()
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // variable definition
    char ch;
    char s[MAX_LEN];
    char sen[MAX_LEN];

    // obtain user input
    scanf("%c%*c", &ch);      // read one character, dump the second one which is a newline
    scanf("%s%*c", &s);       // read a string, dump the last character which will be a newline
    scanf("%[^\n]%*c", &sen); // read a sentence up until a newline character is encountered, which will be dumped

    // display user input
    printf("%c\n", ch);
    printf("%s", s); // no newline character needed since %s format specieifer added one during scanf execution
    printf("%s\n", sen);

    return 0;
}