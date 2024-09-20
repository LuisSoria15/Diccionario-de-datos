#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char value[50];
    long next;
    //In-memory pointer.
    //struct Node *next;
    //File pointer.
}NODE;

#define EMPTY_POINTER -1

int initializeDataDictionary(const char *dictionaryName);

#endif