#include "main.h"

/* Cria um novo (LL)nó com valor node e a apontar para NULL. 
   Devolve um ponteiro para o novo nó. */
LLNode* newnode_LL(TreeNode* node){
    LLNode* new_node = (LLNode*) malloc(sizeof(LLNode));
    new_node->node = node;
    new_node->next = NULL;
    return new_node;
}

/* Insere um nó numa linked list com valor node, a seguir a L. Devolve um 
   ponteiro para o nó inserido. */
LLNode* addnode_LL(LLNode* L, TreeNode* node){
    LLNode* new_node = newnode_LL(node);
    if(L == NULL) L = new_node;
    else{
        new_node->next = L->next;
        L->next = new_node;
    }
    return new_node;
}

/* Imprime a descrição de todos os nós na linked list a partir de node. */
void print_LL(LLNode* node){
    while(node != NULL){
        printf("%s\n", node->node->item->description);
        node = node->next;
    }
}

/* Apaga o nó da linked list L com o valor node. Se não encontrar tal nó devolve 
   NULL, caso contrário devolve um ponteiro para L. */
LLNode* deletenode_LL(LLNode* L, TreeNode* node){
    if(L == NULL) return NULL;
    if(!desc_compare(L->node, node)){
        LLNode* X = L->next;
        /*deletenode(L->node);*/
        free(L);
        L = NULL;
        return X;
    }
    L->next = deletenode_LL(L->next, node);
    return L;
}

/* Liberta toda a memória da linked list a partir de L. */
void destroy_LL(LLNode* L){
    if(L==NULL) return;
    destroy_LL(L->next);
    deletenode_LL(L, L->node);
}
