#include "main.h"

/* Creates an AVL node with children l and r and value node. */
AVLNode* newnode_AVL(TreeNode* node, AVLNode* l, AVLNode* r){
    AVLNode* new_node = (AVLNode*) malloc(sizeof(AVLNode));
    new_node->node = node;
    new_node->depth = 0;
    new_node->left = l;
    new_node->right = r;
    return new_node;
}

/* Returns the bigger of integers a and b. */
int max(int a, int b){
    return a>b ? a : b;
}

/* Returns the depth of AVL node node. */
int depth(AVLNode* node){
    return node == NULL ? -1 : node->depth;
}

/* Returns the balance factor of AVL node node. */
int balance_factor(AVLNode* node){
    return depth(node->left) - depth(node->right);
}

/* AVL left rotation on AVL node node. */
AVLNode* rotate_left(AVLNode* node){
    AVLNode* x = node->right;
    node->right = x->left;
    x->left = node;
    node->depth = max(depth(node->right), depth(node->left))+1;
    x->depth = max(depth(x->right), depth(x->left))+1;
    return x;
}

/* AVL right rotation on AVL node node. */
AVLNode* rotate_right(AVLNode* node){
    AVLNode* x = node->left;
    node->left = x->right;
    x->right = node;
    node->depth = max(depth(node->right), depth(node->left))+1;
    x->depth = max(depth(x->right), depth(x->left))+1;
    return x;
}

/* AVL left-right rotation on AVL node node. */
AVLNode* rotate_LR(AVLNode* node){
    if(node == NULL) return node;
    node->left = rotate_left(node->left);
    return rotate_right(node);
}

/* AVL right-left rotation on AVL node node. */
AVLNode* rotate_RL(AVLNode* node){
    if(node == NULL) return node;
    node->right = rotate_right(node->right);
    return rotate_left(node);
}

/* Balances the AVL with tree as root. */
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

/* Adds a node with value node to the AVL with root at tree. */
AVLNode* addnode_AVL(AVLNode* tree, TreeNode* node){
    int dif;
    if(tree == NULL) return newnode_AVL(node, NULL, NULL);
    else if((dif = desc_compare(node, tree->node)) == 0)
        return newnode_AVL(node, tree->left, tree->right);
    else if(dif > 0)
        tree->right = addnode_AVL(tree->right, node);
    else if(dif < 0)
        tree->left = addnode_AVL(tree->left, node);
    return balance(tree);
}

/* Finds a node in the AVL with rooted at tree with the same description as item. */
AVLNode* findnode_AVL(AVLNode* tree, Item* item){
    AVLNode* x = tree; int dif;
    while(x != NULL && (dif = desc_itemcompare(x->node->item, item)))
        if(dif<0) x = x->right;
        else      x = x->left;
    return x;
}

/* Prints the description of all nodes in the AVL rooted at root in 
   alphabetical order. */
void print_AVL(AVLNode* root){
    if(root == NULL) return;
    print_AVL(root->left);
    printf("%s\n", root->node->item->description);
    print_AVL(root->right);
}

/* Finds the node with the biggest value in the AVL rooted at root, following
   the comparison criterium for the AVL. */
AVLNode* findmax_AVL(AVLNode* root){
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

/* Creates and returns a duplicate of string string. */
char* strdup(char* string){
    char * res = (char*) malloc(sizeof(char)*(strlen(string)+1));
    strcpy(res, string);
    return res;
}

/* Deletes the AVL node holding node from the AVL rooted at avl. */
AVLNode* deletenode_AVL(AVLNode* avl, TreeNode* node){
    AVLNode *M, *delete; int dif;
    if(avl == NULL) return NULL;
    else if((dif = desc_compare(node, avl->node))>0) 
        avl->right = deletenode_AVL(avl->right, node);
    else if(dif<0) 
        avl->left = deletenode_AVL(avl->left, node);
    else{
        if(avl->left != NULL && avl->right != NULL){
            deletenode(avl->node);
            M = findmax_AVL(avl->left);
            avl->node = M->node;
            M->node = newnode();
            M->node->item = newitem();
            M->node->item->description = strdup(avl->node->item->description);
            avl->left = deletenode_AVL(avl->left, M->node);
        }else{
            delete = avl;
            if(avl->left != NULL) avl = avl->left;
            else avl = avl->right;
            deletenode(delete->node);
            delete->node = NULL;
            free(delete);
        }
    }
    return balance(avl);
}

/* Destroys the AVL rooted at root (deletes the root and all it's children). */
void destroy_AVL(AVLNode* root){
    if(root == NULL) return;
    destroy_AVL(root->left); root->left = NULL;
    destroy_AVL(root->right); root->right = NULL;
    deletenode_AVL(root, root->node);
}