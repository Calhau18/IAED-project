#include "linkedlist.h"

LLNode* newnode(Item item){
    LLNode* node = (LLNode*) malloc(sizeof(LLNode));
    node.item = item;
    node.next = NULL;
    return node;
}

LinkedList* push_LL(LinkedList* L, Item item){
    if(L->start == NULL){ 
        L->start = newnode(item);
        L->end = L->start;
    }else{
        L->end->next = newnode(item);
        L->end->next = L->end;
    }
    return L;
}

LinkedList* delete_LL(LinkedList* L, Item item){
    LLNode* x = L->start, * prev = NULL;
    while(x != NULL){
        prev = x;
        if(compare(x->item, item)!=0)
            x = x->next;
        else{
            deleteItem(x->item);
            prev->next = x->next;
            free(x);
            return L;
        }
    }
    return x;
}