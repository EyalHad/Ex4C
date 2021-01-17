#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "freq.h"

// typedef enum
// {
//     FALSE = 0,
//     TRUE = 1
// } boolean;

// typedef struct node
// {
//     char letter;
//     long unsigned int count;
//     boolean endWord;
//     struct node *child[NUM_LETTERS];
// } node;

struct node *getnode()
{
    struct node *node = (struct node *)malloc(sizeof(struct node));

    for (int i = 0; i < NUM_LETTERS; i++)
    {
        node->child[i] = NULL;
    }
    node->endWord = FALSE;
    return node;
}

void inputWord(node **root, char *word)
{
    if (word[0] == ' ' || word[0] == '\n' || word[0] == '\t')
        return;
    int len = strlen(word);
    node *printNode = *root;
    for (int i = 0; i < len; i++)
    {
        char c = word[i];
        if (c >= 'a' && c <= 'z')
        {
            int index = c - 'a';

            if (printNode->child[index] == NULL)
            {
                printNode->child[index] = getnode();
                printNode = printNode->child[index];
            }
            else
            {
                printNode = printNode->child[index];
            }
            printNode->letter = c;
        }
    }
    printNode->endWord = TRUE;
    printNode->count++;
}

void printDefult(node *printNode, char *str, int level)
{
    if (printNode->endWord == TRUE)
    {
        str[level] = '\0';
        printf("%s \t %ld \n", str, printNode->count);
    }
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        if (printNode->child[i] != NULL)
        {
            str[level] = i + 'a';
            printDefult(printNode->child[i], str, level + 1);
        }
    }
}

void printReverse(node *pNode, char *str, int level)
{

    for (int i = NUM_LETTERS - 1; i > -1; i--)
    {
        if (pNode->child[i])
        {
            str[level] = i + 'a';
            printReverse(pNode->child[i], str, level + 1);
        }
    }
    if (pNode->endWord == TRUE)
    {
        str[level] = '\0';
        printf("%s \t %ld \n", str, pNode->count);
    }
}

void delete (node *toDelete)
{

    for (int i = 0; i < NUM_LETTERS; i++)
    {
        if (toDelete->child[i])
            delete (toDelete->child[i]);
    }
    free(toDelete);
}

void lowerLetter(char *word)
{

    for (int i = 0; i < strlen(word); i++)
    {
        word[i] = tolower(word[i]);
    }
}
