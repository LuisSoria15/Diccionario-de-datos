#include "main.h"

int main(int argc, char** argv) 
{
    char name[50];

    printf("\nEnter a dictionary Name: ");

    fgets(name, sizeof(name), stdin);

    FILE* dataDictionary = initializeDataDictionary(name);

    ENTITY newEntity;

    printf("\nEnter the entity name:");

    fgets(newEntity.name, sizeof(name), stdin);
    newEntity.dataPointer = EMPTY_POINTER;
    newEntity.attributesPointer = EMPTY_POINTER;
    newEntity.nextEntity = EMPTY_POINTER;

    long entityDirection = appendEntity(dataDictionary, newEntity);
    reorderEntities(dataDictionary, newEntity, entityDirection);

    fclose(dataDictionary);

    return 0;
}