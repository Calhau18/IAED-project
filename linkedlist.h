#ifndef LINKEDLIST
#define LINKEDLIST

#include "tree.h"

typedef struct treenode TreeNode;

typedef struct llnode {
    struct treenode* node;
    struct llnode* next;
} LLNode;

typedef struct linkedlist {
    LLNode* start;
    LLNode* end;
} LinkedList;

LinkedList* init_LL();
int empty_LL(LinkedList*);
LinkedList* push_LL(LinkedList*, TreeNode*);
void print_LL(LinkedList*);
LinkedList* deletenode_LL(LinkedList*, TreeNode*);
void destroy_LL(LinkedList*);

#endif