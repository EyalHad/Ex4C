#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "freq.h"

int main(int argc, char *argv[])
{

    node *head = getnode();

    char c;
    size_t n;
    char *word;
    n = 0;
    word = (char *)malloc(sizeof(char));
    word[n++] = '\0';

    c = getchar();
    int i = 0;
    while (c != EOF )
    {
        while (c != EOF && c != ' ' && c != '\t' && c != '\n') 
        {
            word = realloc(word, (n + 1) * sizeof(char));

            word[n - 1] = c;
            word[n++] = '\0';
            c = getchar();
            i++;
        }
        i++;
        lowerLetter(word);

        inputWord(&head, word);
        free(word);

        c = getchar();
        if (c == EOF)
            break;

        n = 1;
        word = (char *)malloc(sizeof(char));

        word[0] = c;
    }

    char *str = (char *)malloc(sizeof(char));
    if (argc == 1)
    {
        printf("Defult \n");
        printDefult(head, str, 0);
    }
    else if (argv[1][0] == 'r')
    {
        printf("Reverse \n");
        printReverse(head, str, 0);
    }
    free(str);
    delete (head);
}