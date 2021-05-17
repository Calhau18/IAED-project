#ifndef AVL
#define AVL

/* #include "item.h" */

typedef struct {
    Item item;
    int depth;
    AVLNode *left, *right;
} AVLNode;

AVLNode* addnode_AVL(AVLNode*, char*, Value);
AVLNode* findnode_AVL(AVLNode*, AVLNode*);
AVLNode* findmin_AVL(AVLNode*);
AVLNode* findmax_AVL(AVLNode*);
AVLNode* deletenode_AVL(AVLNode*, AVLNode*);

#endif