#ifndef LINKEDLIST
#define LINKEDLIST

/* #include "item.h" */

typedef struct {
    Item item;
    LLNode* next;
} LLNode;

typedef struct {
    LLNode* start;
    LLNode* end;
} LinkedList;

LinkedList* push_LL(LinkedList*, Item);
LinkedList* deletenode_LL(LinkedList*, Item);