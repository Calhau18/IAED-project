#ifndef AVL
#define AVL

#include "tree.h"

typedef struct treenode TreeNode;
typedef struct item Item;

typedef struct avlnode {
    struct treenode* node;
    int depth;
    struct avlnode *left, *right;
} AVLNode;

AVLNode* init_AVL();
int empty_AVL(AVLNode*);
AVLNode* addnode_AVL(AVLNode*, TreeNode*);
AVLNode* findnode_AVL(AVLNode*, Item*);
AVLNode* findmin_AVL(AVLNode*);
AVLNode* findmax_AVL(AVLNode*);
AVLNode* deletenode_AVL(AVLNode*, TreeNode*);
void destroy_AVL(AVLNode*);

#endif