#include "main.h"

int main(int argc, char** argv) 
{
    char name[50];

    printf("\nEnter a dictionary Name: ");

    fgets(name, sizeof(name), stdin);//scanf

    FILE* dataDictionary = initializeDataDictionary(name);

    createEntity(dataDictionary);

    ENTITY currentEntity;
    currentEntity.dataPointer = 58;
    currentEntity.attributesPointer = 66;
    currentEntity.nextEntity = 74;

    CreateAttribute(dataDictionary, currentEntity);
    CreateAttribute(dataDictionary, currentEntity);

    fclose(dataDictionary);

    return 0;
}

void createEntity(FILE* dataDictionary)
{
    ENTITY newEntity;

    printf("\nEnter the entity name:");

    fgets(newEntity.name, sizeof(newEntity.name), stdin);//scanf
    newEntity.dataPointer = EMPTY_POINTER;
    newEntity.attributesPointer = EMPTY_POINTER;
    newEntity.nextEntity = EMPTY_POINTER;

    long entityDirection = appendEntity(dataDictionary, newEntity);
    reorderEntities(dataDictionary, MAIN_ENTITY_POINTER, newEntity.name, entityDirection);
}

void CreateAttribute(FILE* dataDictionary, ENTITY currentEntity)
{
    ATTRIBUTE newAttribute;

    printf("\nEnter the entity name:");

    fgets(newAttribute.name, sizeof(newAttribute.name), stdin);
    newAttribute.isPrimary = false;
    newAttribute.type = 1;
    newAttribute.size = sizeof(int);
    newAttribute.nextAttribute= EMPTY_POINTER;

    long attributeDirection = appendAttribute(dataDictionary, newAttribute);
    reorderAttributes(dataDictionary, currentEntity.attributesPointer, newAttribute.name, attributeDirection);

}