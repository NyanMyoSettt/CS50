#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command line arguments! \n");
        return 1;
    }
    // rotate('A', 1);
    int key = atoi(argv[1]); // atoi converts string to int
    if (key != 0)            // if it is a non-digit, this will be 0.
    {
        string plainText = get_string("Plain text : ");
        printf("cipherext: ");
        for (int i = 0; i < strlen(plainText); i++)
        {
            char cipherCode = rotate(plainText[i], key);
            printf("%c" , cipherCode);
        }
        printf("\n");
    }

    else
    {
        printf("Usage: ./caesar key\n");
    }
}

char rotate(char c, int n)
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
            char a = c - 65;      // Converts to alphabetical index, a will 1; b will 2.
            int b = (a + n) % 26; // Formula to cipherText
            char d = b + 64;      // Converts to ASCII Chart
            return d;
        }
        else
        {
            char a = c - 97; // Same as above this is converting lower case letter
            int b = (a + n) % 26;
            char d = b + 96;
            return d;
        }
    }
    return c;
}
