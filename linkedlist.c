#include <stdio.h>
#include "linkedlist.h"

/* Cria um novo (LL)nó com valor node e a apontar para NULL. 
   Devolve um ponteiro para o novo nó. */
LLNode* newnode_LL(TreeNode* node){
    LLNode* new_node = (LLNode*) malloc(sizeof(LLNode));
    new_node->node = node;
    new_node->next = NULL;
    return new_node;
}

/* Cria uma linked list sem nós. Devolve um ponteiro para a mesma. */
LinkedList* init_LL(){
    LinkedList* L = (LinkedList*) malloc(sizeof(LinkedList));
    L->start = NULL;
    L->end = NULL;
    return L;
}

int empty_LL(LinkedList* L){
    return L->start == NULL;
}

/* Insere um (LL)nó na linked list L com valor node. Devolve um ponteiro para
   a linked list em que o novo nó foi inserido. */
LinkedList* push_LL(LinkedList* L, TreeNode* node){
    if(L->start == NULL){ 
        L->start = newnode_LL(node);
        L->end = L->start;
    }else{
        L->end->next = newnode_LL(node);
        L->end = L->end->next;
    }
    return L;
}

void print_LL(LinkedList* L){
    LLNode* x = L->start;
    while(x != NULL){
        printf("%s\n", x->node->item->description);
        x = x->next;
    }
}

/* Apaga o nó da linked list L com o valor node. Se não encontrar tal nó devolve 
   NULL, caso contrário devolve um ponteiro para L. */
LinkedList* deletenode_LL(LinkedList* L, TreeNode* node){
    LLNode* x = L->start, * prev = NULL;
    while(x != NULL){
        prev = x;
        if(desc_compare(x->node, node))
            x = x->next;
        else{
            if(x != L->start) prev->next = x->next;
            else L->start = L->start->next;
            deletenode(x->node);
            free(x);
            return L;
        }
    }
    return NULL;
}

/* Liberta toda a memória associada à linked list L. */
void destroy_LL(LinkedList* L){
    while(L->start != NULL) 
        deletenode_LL(L, L->start->node);
    free(L); L = NULL;
}
