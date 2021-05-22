#include "main.h"

/* Creates a new LL node with value node and pointing to NULL. */
LLNode* newnode_LL(TreeNode* node){
    LLNode* new_node = (LLNode*) malloc(sizeof(LLNode));
    new_node->node = node;
    new_node->next = NULL;
    return new_node;
}

/* Adds a LL node, replacing L if L is NULL and following L otherwise. */
LLNode* addnode_LL(LLNode* L, TreeNode* node){
    LLNode* new_node = newnode_LL(node);
    if(L == NULL) L = new_node;
    else{
        new_node->next = L->next;
        L->next = new_node;
    }
    return new_node;
}

/* Prints the description of every LL node following node. */
void print_LL(LLNode* node){
    while(node != NULL){
        printf("%s\n", node->node->item->description);
        node = node->next;
    }
}

/* Deletes the LL node that follows L and holds a tree node node. Returns L if
   there is such node and NULL otherwise.
   Note: this function shall always be called before a deletenode_AVL call.
   Since, for every tree node X there is a LL and an AVL holding X's children,
   deleting X's children in both structures would be redundant. Line 40 is 
   therefore commented. */
LLNode* deletenode_LL(LLNode* L, TreeNode* node){
    if(L == NULL) return NULL;
    if(!desc_compare(L->node, node)){
        LLNode* X = L->next;
        /* deletenode(L->node); */
        free(L);
        return X;
    }
    L->next = deletenode_LL(L->next, node);
    return L;
}

/* Deletes the linked list starting with the LL node L. */
void destroy_LL(LLNode* L){
    if(L==NULL) return;
    destroy_LL(L->next);
    deletenode_LL(L, L->node);
}
