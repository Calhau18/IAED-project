#include "main.h"

TreeNode* newnode(){
    TreeNode* Res = (TreeNode*) malloc(sizeof(TreeNode));
    Res->item = NULL;
    Res->parent = NULL;
    Res->alf_children = NULL;
    Res->first = NULL;
    Res->last = NULL;
    return Res;
}

int desc_compare(TreeNode* A, TreeNode* B){
    if(A == NULL || B == NULL) return (A == NULL && B == NULL);
    return desc_itemcompare(A->item, B->item);
}

int val_compare(TreeNode* A, TreeNode* B){
    if(A == NULL || B == NULL) return A == NULL && B == NULL;
    return val_itemcompare(A->item, B->item);
}

TreeNode* addchildren(TreeNode* parent, Item* item){
    TreeNode* new_node = newnode();
    new_node->item = copyitem(item);
    new_node->parent = parent;
    parent->alf_children = addnode_AVL(parent->alf_children, new_node);
    parent->last = addnode_LL(parent->last, new_node);
    if(parent->first == NULL) parent->first = parent->last;
    return new_node;
}

TreeNode* findchildren(TreeNode* parent, Item* item){
    AVLNode* Res;
    Res = findnode_AVL(parent->alf_children, item);
    if(Res == NULL) return NULL;
    return Res->node;
}

TreeNode* findnode(TreeNode* root, char* path){
    TreeNode* current_node = root, * new_node;
    Item* item = newitem();
    char* token = strtok(path, "/");
    while(token != NULL){
        changeitemdesc(item, token);
        if((new_node = findchildren(current_node, item)) == NULL){
            deleteitem(item);
            return NULL;
        }
        current_node = new_node;
        token = strtok(NULL, "/");
    }
    deleteitem(item);
    return current_node;
}

void deletenode(TreeNode* node){
    if(node == NULL) return;
    if(node->alf_children != NULL){
        destroy_LL(node->first);
        destroy_AVL(node->alf_children);
    }
    deleteitem(node->item);
    free(node);
}

void destroy_Tree(TreeNode* root){
    deletenode(root);
}