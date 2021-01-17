#define NUM_LETTERS ((int)26)

typedef enum
{
    FALSE = 0,
    TRUE = 1
} boolean;

typedef struct node
{
    char letter;
    long unsigned int count;
    int endWord;
    struct node *child[NUM_LETTERS];
} node;

struct node *getnode();
void inputWord(node **root, char *word);
void printDefult(node *printNode, char *str, int level);
void printReverse(node *pNode, char *str, int level);
void delete (node *toDelete);
void lowerLetter(char *word);