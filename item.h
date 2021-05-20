#ifndef ITEM
#define ITEM

#include <stdlib.h>
#include <string.h>
#include "tree.h"

typedef struct item {
    char* description;
    char* value;
} Item;

Item* newitem(char*, char*);
void changeitemdesc(Item*, char*);
void changeitemval(Item*, char*);
int desc_itemcompare(Item*, Item*);
int val_itemcompare(Item*, Item*);
void deleteitem(Item*);

#endif