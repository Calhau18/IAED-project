#ifndef TREE
#define TREE

#include "item.h"
#include "AVL.h"
#include "linkedlist.h"

typedef struct avlnode AVLNode;
typedef struct linkedlist LinkedList;
typedef struct item Item;

typedef struct treenode {
    struct item* item;
    struct avlnode* alf_children;
    struct linkedlist* hist_children;
} TreeNode;

TreeNode* newnode();
int desc_compare(TreeNode*, TreeNode*);
int val_compare(TreeNode*, TreeNode*);
TreeNode* addchildren(TreeNode*, Item*);
TreeNode* findchildren(TreeNode*, Item*);
void deletenode(TreeNode*);
void destroy_Tree(TreeNode*);

#endif