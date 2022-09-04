#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

float countLetters(string s);
float countWords(string s);
float countSentences(string s);

int main(void)
{
    string text = get_string("Text: "); // Get input from user

    float L = countLetters(text); // counting letters in a text

    float W = countWords(text); // counting words in a text

    float S = countSentences(text); // counting sentences in a text

    // float lettersPerWords100 = ((L / W) * 100);
    // printf("%f\n" , lettersPerWords100);

    // Calculating readability of grade by Coleman-Liau formula
    float index = 0.0588 * (L / W * 100) - 0.296 * (S / W * 100) - 15.8;
    int grade = (int)round(index);

    // Printing outputs
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

float countLetters(string s)
{
    int totalLetters = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]))
        {
            totalLetters++;
        }
    }
    return totalLetters;
}

float countWords(string s)
{
    int totalWords = 1;
    for (int i = 0; i < strlen(s); i++)
    {
        if (isspace(s[i]))
        {
            totalWords++;
        }
    }
    return totalWords;
}

float countSentences(string s)
{
    int totalSentence = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            totalSentence++;
        }
    }
    return totalSentence;
}
