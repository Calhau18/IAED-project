#include "item.h"

Item* newitem(char* desc, char* val){
    Item* Res = (Item*) malloc(sizeof(Item));
    if(val != NULL){
        Res->value = (char*) malloc(sizeof(char)*(strlen(val)+1));
        strcpy(Res->value, val);
    }else Res->value = NULL;
    if(desc != NULL){
        Res->description = (char*) malloc(sizeof(char)*(strlen(desc)+1));
        strcpy(Res->description, desc);
    }else Res->description = NULL;
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

int desc_itemcompare(Item* A, Item* B){
    return strcmp(A->description, B->description);
}

int val_itemcompare(Item* A, Item* B){
    return strcmp(A->value, B->value);
}

void deleteitem(Item* item){
    free(item->description);
    free(item->value);
    free(item);
}