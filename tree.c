#include "tree.h"

TreeNode* newnode(){
    TreeNode* Res = (TreeNode*) malloc(sizeof(TreeNode));
    Res->item = newitem(NULL, NULL);
    Res->alf_children = init_AVL();
    Res->hist_children = init_LL();
    return Res;
}

int desc_compare(TreeNode* A, TreeNode* B){
    return desc_itemcompare(A->item, B->item);
}

int val_compare(TreeNode* A, TreeNode* B){
    return val_itemcompare(A->item, B->item);
}

TreeNode* addchildren(TreeNode* parent, Item* item){
    TreeNode* new_node = newnode();
    new_node->item = item;
    addnode_AVL(parent->alf_children, new_node);
    push_LL(parent->hist_children, new_node);
    return new_node;
}

TreeNode* findchildren(TreeNode* parent, Item* item){
    AVLNode* Res;
    Res = findnode_AVL(parent->alf_children, item);
    if(Res == NULL) return NULL;
    return Res->node;
}

void deletenode(TreeNode* node){
    if(node == NULL) return;
    if(!empty_AVL(node->alf_children)){
        destroy_LL(node->hist_children);
        destroy_AVL(node->alf_children);
    }
    deleteitem(node->item);
    free(node);
}

void destroy_Tree(TreeNode* root){
    deletenode(root);
}