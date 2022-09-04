// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <string.h>
#include <ctype.h>
#include <strings.h>
#include <ctype.h>
#include <stdlib.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int hash_value = hash(word);
    node* cursor = table[hash_value];

    while (cursor != 0)
    {
        if(strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    char firstLetter = toupper(word[0]);
    char secondLetter = toupper(word[1]);
    int count = 0;
    int x = ((int) firstLetter) - 65; // x and y are ascii values of two letter
    int y = ((int) secondLetter) - 65;// I'm just bored to think how to name those haha

    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            count++;
            if((x = i) && (y = j)){
                break;
            }
        }
    }
    return count;
}
unsigned int word_count = 0;
unsigned int hash_value = 0;
// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen("dictionaries/large", "r");
    if (file == NULL)
    {
        return 1;
    }
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, word);
        hash_value = hash(word);
        n->next = table[hash_value];
        table[hash_value] = n;
        word_count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if(word_count > 0){
        return word_count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for(int i = 0; i < N; i++)
    {
        node* cursor = table[i];
        while(cursor)
        {
            node* tmp = cursor;
            free(tmp);
            cursor = cursor->next;
        }
        if(cursor == NULL)
        {
            return true;
        }
    }
    return false;
}
