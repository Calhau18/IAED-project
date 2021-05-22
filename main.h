#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Textos para o comando help. */
#define HELP_TEXT "help: Imprime os comandos disponíveis.\n"
#define QUIT_TEXT "quit: Termina o programa.\n"
#define SET_TEXT "set: Adiciona ou modifica o valor a armazenar.\n"
#define PRINT_TEXT "print: Imprime todos os caminhos e valores.\n"
#define FIND_TEXT "find: Imprime o valor armazenado.\n"
#define LIST_TEXT "list: Lista todos os componentes imediatos de um sub-caminho.\n"
#define SEARCH_TEXT "search: Procura o caminho dado um valor.\n"
#define DELETE_TEXT "delete: Apaga um caminho e todos os subcaminhos.\n"
/* Textos de erro. */
#define NOT_FOUND "not found\n"
#define NO_DATA "no data\n"
/* Numero maximo de caracteres para o valor de um caminho. */
#define MAX_DESCRIPTION 65535+1

struct avlnode;
struct llnode;

typedef struct item {
    char* description;
    char* value;
} Item;

typedef struct treenode {
    struct treenode* parent;
    struct item* item;
    struct avlnode* alf_children;
    struct llnode* first, * last;
} TreeNode;

typedef struct avlnode {
    struct treenode* node;
    int depth;
    struct avlnode *left, *right;
} AVLNode;

typedef struct llnode {
    struct treenode* node;
    struct llnode* next;
} LLNode;

/* Funções sobre árvores e nós de árvores. */
TreeNode* newnode();
int desc_compare(TreeNode*, TreeNode*);
int val_compare(TreeNode*, TreeNode*);
TreeNode* addchildren(TreeNode*, Item*);
TreeNode* findchildren(TreeNode*, Item*);
TreeNode* findnode(TreeNode*, char*);
void deletenode(TreeNode*);
void destroy_Tree(TreeNode*);

/* Funções sobre AVL's e nós de AVL's. */
AVLNode* addnode_AVL(AVLNode*, TreeNode*);
AVLNode* findnode_AVL(AVLNode*, Item*);
void print_AVL(AVLNode*);
AVLNode* findmin_AVL(AVLNode*);
AVLNode* findmax_AVL(AVLNode*);
AVLNode* deletenode_AVL(AVLNode*, TreeNode*);
void destroy_AVL(AVLNode*);

/* Funções sobre linked lists e nós de linked lists. */
LLNode* addnode_LL(LLNode*, TreeNode*);
void print_LL(LLNode*);
LLNode* deletenode_LL(LLNode*, TreeNode*);
void destroy_LL(LLNode*);

/* Funções sobre items. */
Item* newitem();
void changeitemdesc(Item*, char*);
void changeitemval(Item*, char*);
Item* copyitem(Item*);
int desc_itemcompare(Item*, Item*);
int val_itemcompare(Item*, Item*);
void deleteitem(Item*);