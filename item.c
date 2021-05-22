#include "main.h"

/* Creates a new item with NULL value and description. */
Item* newitem(){
    Item* Res = (Item*) malloc(sizeof(Item));
    Res->description = NULL;
    Res->value = NULL;
    return Res;
}

/* !!!!!!!!!!! */
/* Changes item's description to desc. */
void changeitemdesc(Item* item, char* desc){
    item->description = (char*) realloc(item->description, sizeof(char)*(strlen(desc)+1));
    strcpy(item->description, desc);
}

/* !!!!!!!!!!! */
/* Changes item's value to val. */
void changeitemval(Item* item, char val[]){
    item->value = (char*) realloc(item->value, sizeof(char)*(strlen(val)+1));
    strcpy(item->value, val);
}

/* !!!!!!!!!!! */
/* Returns a copy of item. */
Item* copyitem(Item* item){
    char* desc = item->description, * val = item->value;
    Item* copy = (Item*) malloc(sizeof(Item));
    if(desc == NULL) copy->description = NULL;
    else{
        copy->description = (char*) malloc(sizeof(char)*(strlen(desc)+1));
        strcpy(copy->description, desc);
    }
    if(val == NULL) copy->value = NULL;
    else{
        copy->value = (char*) malloc(sizeof(char)*(strlen(val)+1));
        strcpy(copy->value, val);
    }
    return copy;
}

/* Compares two items' descriptions. */
int desc_itemcompare(Item* A, Item* B){
    if(A->description == NULL || B->description == NULL)
        return (A->description == NULL && B->description == NULL);
    return strcmp(A->description, B->description);
}

/* Compares two items' values. */
int val_itemcompare(Item* A, Item* B){
    if(A->value == NULL || B->value == NULL)
        return (A->value == NULL && B->value == NULL);
    return strcmp(A->value, B->value);
}

/* Deletes item, releasing the memory allocated to hold it. */
void deleteitem(Item* item){
    if(item == NULL) return;
    free(item->description); item->description = NULL;
    free(item->value); item->value = NULL;
    free(item);
}