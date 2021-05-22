#include "main.h"

Item* newitem(){
    Item* Res = (Item*) malloc(sizeof(Item));
    Res->description = NULL;
    Res->value = NULL;
    return Res;
}

void changeitemdesc(Item* item, char* desc){
    item->description = (char*) realloc(item->description, sizeof(char)*(strlen(desc)+1));
    strcpy(item->description, desc);
}

void changeitemval(Item* item, char val[]){
    item->value = (char*) realloc(item->value, sizeof(char)*(strlen(val)+1));
    strcpy(item->value, val);
}

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

int desc_itemcompare(Item* A, Item* B){
    if(A == NULL || B == NULL) return (A == NULL && B == NULL);
    if(A->description == NULL || B->description == NULL)
        return (A->description == NULL && B->description == NULL);
    return strcmp(A->description, B->description);
}

int val_itemcompare(Item* A, Item* B){
    if(A == NULL || B == NULL) return (A == NULL && B == NULL);
    if(A->value == NULL || B->value == NULL)
        return (A->value == NULL && B->value == NULL);
    return strcmp(A->value, B->value);
}

void deleteitem(Item* item){
    if(item == NULL) return;
    free(item->description); item->description = NULL;
    free(item->value); item->value = NULL;
    free(item);
}