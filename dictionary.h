#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAIN_ENTITY_POINTER 0
#define EMPTY_POINTER -1
#define DATA_BLOCK_SIZE 50

typedef struct Entity
{
    char name[DATA_BLOCK_SIZE];
    long dataPointer;
    long attributesPointer;
    long nextEntity;
}ENTITY;

typedef struct Attribute
{
    char name[DATA_BLOCK_SIZE];
    bool isPrimary;
    long type;
    long size;
    long nextAttribute;
}ATTRIBUTE;

FILE* initializeDataDictionary(const char *dictionaryName);

int appendEntity(FILE *dataDictionary, ENTITY newEntity);
void reorderEntities(FILE* dataDictionary, long currentEntityPointer, const char* NewEntityName, long newEntityDirection);

int appendAttribute(FILE *dataDictionary, ATTRIBUTE newAttribute);
void reorderAttributes(FILE *dataDictionary, long currentAttributePointer, const char*newAttributeName, long newAttributeDirection);

#endif