#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    string key = argv[1];

    if (argc != 2)
    {
        printf("Usage : ./substitution key.\n");
        return 1;
    }

    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < strlen(key); i++)
    {
        if (isdigit(key[i]))
        {
            printf("Key must contain alphabetic characters!\n");
            return 1;
        }
    }

    // char sampleChar = key[0];

    // for (int i = 1; i < strlen(key); i++)
    // {
    //     if (key[i] == sampleChar)
    //     {
    //         printf("Key must not contain repeated characters.\n");
    //         return 1;
    //     }
    // }
    for(int i=0; i < strlen(key); i++){
        for(int j = i + 1; j < strlen(key); j++){
            if(key[i] == key[j]){
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    string plainText = get_string("Plain Text : ");

    printf("ciphertext: ");

    for(int i=0; i < strlen(key); i++)
    {
        if(islower(key[i])){
            key[i] = key[i] - 32;
        }
    }

    for (int i = 0; i < strlen(plainText); i++)
    {
        if (isupper(plainText[i]))
        {
            int letter = plainText[i] - 65;
            printf("%c" , key[letter]);
        } else if(islower(plainText[i]))
        {
            int letter = plainText[i] - 97;
            printf("%c" , key[letter] + 32);
        } else
        {
            printf("%c", plainText[i]);
        }
    }
    printf("\n");
}
