#include "AVL.h"

AVLNode* newnode(Item item, AVLNode* l, AVLNode* r){
    AVLNode* new_node = (AVLNode*) malloc(sizeof(AVLNode));
    new_node->item = item;
    new_node->depth = 0;
    new_node->left = l;
    new_node->right = r;
    return new_node;
}

int max(int a, int b){
    return a>b ? a : b;
}

int depth(AVLNode* node){
    return node == NULL ? -1 : node->depth;
}

int balance_factor(AVLNode* node){
    if(h == NULL) return 0;
    return depth(node->left) - depth(node->right);
}

AVLNode* rotate_left(AVLNode* node){
    AVLNode* x = node->right;
    node->right = x->left;
    x->left = node;
    node->depth = max(node->right->depth, node->left->depth)+1;
    x->depth = max(x->right->depth, x->left->depth)+1;
    return x;
}

AVLNode* rotate_right(AVLNode* node){
    AVLNode* x = node->left;
    node->left = x->right;
    x->right = node;
    node->depth = max(node->right->depth, node->left->depth)+1;
    x->depth = max(x->right->depth, x->left->depth)+1;
    return x;
}

AVLNode* rotate_LR(AVLNode* node){
    node->left = rotate_left(node->left);
    return rotate_right(node);
}

AVLNode* rotate_RL(AVLNode* node){
    node->right = rotate_right(node->right);
    return rotate_left(node);
}

AVLNode* balance(AVLNode* tree){
    if(tree == NULL) return tree;
    if(balance_factor(tree) > 1){
        if(balance_factor(tree->left) >= 0)
            tree = rotate_right(tree);
        else
            tree = rotate_LR(tree);
    }if(balance_factor(tree) < -1){
        if(balance_factor(tree->right) <= 0) 
            tree = rotate_left(tree);
        else
            tree = rotate_RL(tree);
    }else{
        tree->depth = max(depth(tree->left), depth(tree->right))+1;    
    }
    return tree;   
}

AVLNode* addnode_AVL(AVLNode* tree, Item item){
    if(tree == NULL){
        return newnode(item, NULL, NULL);
    }else if(compare(item, tree->item)==0){
        return newnode(item, tree->left, tree->right);
    }else if(compare(item, tree->item)>0){
        tree->right = addnode(tree->right, new);
    }else if(compare(item, tree->item)<0){
        tree->left = addnode(tree->left, new);
    }
    return balance(tree);
}

AVLNode* findnode_AVL(AVLNode* tree, AVLNode* node){
    AVLNode* x = tree;
    while(x!=NULL && compare(x, node))
        if(compare(x, node)<0)
            x = x->right;
        else
            x = x->left;
    return x;
}

AVLNode* findmin_AVL(AVLNode* tree){
    while(tree->left!=NULL){
        tree = tree->left;
    }
    return tree;
}

AVLNode* findmax_AVL(AVLNode* tree){
    while(tree->right!=NULL){
        tree = tree->right;
    }
    return tree;
}

AVLNode* deletenode_AVL(AVLNode* tree, AVLNode* node){
    AVLNode M, delete;
    if(tree == NULL) 
        return tree;
    else if(compare(node, tree)>0) 
        tree->right = deletenode(tree->right, node);
    else if(compare(node, tree)<0) 
        tree->left = deletenode(tree->left, node);
    else{
        if(tree->left != NULL && tree->right != NULL){
            M = findmax(tree->left);
            tree->item = M->item;
            tree->left = deletenode(tree->left, M);
        }else{
            delete = tree;
            if(tree->left != NULL)
                tree = tree->left;
            tree = tree->right;
            deleteItem(delete->item);
            free(delete);
        }
    }
    return tree;
}