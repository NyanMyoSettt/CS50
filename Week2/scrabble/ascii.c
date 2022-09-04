// Explicitly casts chars to ints

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int total = 0;

int main(void)
{
    string s = get_string("String: ");
    for (int i = 0; i < strlen(s); i++)
    {
        int x = (int) s[i];
        x -= 97;
        // printf("%c %i\n", s[i], x);

        int c = POINTS[x];
        // printf("%i\n" , c);

        total += c;
    }
    printf("%i\n" , total);
}