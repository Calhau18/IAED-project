#include "main.h"

/* Creates a tree node with NULL in all components. */
TreeNode* newnode(){
    TreeNode* Res = (TreeNode*) malloc(sizeof(TreeNode));
    Res->item = NULL;
    Res->parent = NULL;
    Res->alf_children = NULL;
    Res->first = NULL;
    Res->last = NULL;
    return Res;
}

/* Compares two tree nodes' descriptions. */
int desc_compare(TreeNode* A, TreeNode* B){
    return desc_itemcompare(A->item, B->item);
}

/* Compares two tree nodes' values. */
int val_compare(TreeNode* A, TreeNode* B){
    return val_itemcompare(A->item, B->item);
}

/* Adds a children to the tree node parent with item's value and description. */
TreeNode* addchildren(TreeNode* parent, Item* item){
    TreeNode* new_node = newnode();
    new_node->item = copyitem(item);
    new_node->parent = parent;
    parent->alf_children = addnode_AVL(parent->alf_children, new_node);
    parent->last = addnode_LL(parent->last, new_node);
    if(parent->first == NULL) parent->first = parent->last;
    return new_node;
}

/* Looks for a children of the tree node parent with the same description as
   item. Returns that node if there is such, and NULL otherwise. */
TreeNode* findchildren(TreeNode* parent, Item* item){
    AVLNode* Res = findnode_AVL(parent->alf_children, item);
    if(Res == NULL) return NULL;
    return Res->node;
}

/* Looks for a tree node in the tree rooted at root with a path given by the
   string path. Returns that node if there is such, and NULL otherwise. */
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

/* Deletes the tree node node and all it's offspring. */
void deletenode(TreeNode* node){
    if(node == NULL) return;
    if(node->alf_children != NULL){
        destroy_LL(node->first);
        destroy_AVL(node->alf_children);
    }
    deleteitem(node->item);
    free(node);
}

/* Destroys the tree rooted at root. */
void destroy_Tree(TreeNode* root){
    deletenode(root);
}