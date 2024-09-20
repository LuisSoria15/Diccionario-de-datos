#include "dictionary.h"

int initializeDataDictionary(const char *dictionaryName) 
{
    long mainHeader = EMPTY_POINTER;
    int stringsToSave = 0;

    printf("Initializing Data Dictionary...\n");

    FILE *dictionary = fopen(dictionaryName, "w+");

    fwrite(&mainHeader, sizeof(mainHeader), 1, dictionary);

    printf("How many strings woud you like? ");
    scanf("%d", &stringsToSave);

    for(int counter = 0; counter <stringsToSave; counter++)
    {
        NODE currentNode;

        currentNode.next = EMPTY_POINTER;
        printf("Enter a value for a node #%d: ", counter);
        scanf("%s[^\n]", currentNode.value);

        fwrite(&currentNode, sizeof(currentNode), 1, dictionary);
    }

    return EXIT_SUCCESS;
}   