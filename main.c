#include "main.h"

/* Reads a path and a value. Adds a folder with such path and such value to
   the tree rooted at root, if there is none, or modifies the value of the 
   folder with such path, otherwise. */
void set(TreeNode* root){
    char path[MAX_DESCRIPTION], value[MAX_DESCRIPTION]; char* token;
    TreeNode* current_node = root, * new_node;
    Item* item = newitem();
    scanf("%s", path);
    token = strtok(path, "/");
    while(token != NULL){
        changeitemdesc(item, token);
        if((new_node = findchildren(current_node, item)) == NULL){
            new_node = addchildren(current_node, item);
        }
        current_node = new_node;
        token = strtok(NULL, "/");
    }
    deleteitem(item);
    getchar(); fgets(value, MAX_DESCRIPTION, stdin);
    changeitemval(current_node->item, value);
}

/* Prints all paths and values by creation order of every component. */
void print(TreeNode* root, char* path){
    LLNode* x = root->first; Item* item;
    char* new_path = NULL;
    while(x != NULL){
        item = x->node->item;
        new_path = (char*) realloc(new_path, 
            sizeof(char)*(strlen(path)+strlen(item->description)+2));
        strcpy(new_path, path); strcat(new_path, "/"); 
        strcat(new_path, item->description);
        if(item->value != NULL)
            printf("%s %s", new_path, item->value);
        print(x->node, new_path);
        x = x->next;
    }
    free(new_path);
}

/* Reads a path and looks for a node with such path in the tree rooted at root.
   Returns the value of that node, if there is such, NO_DATA if there is such
   node but it has no value, and NOT_FOUND if there is no such node. */
char* find(TreeNode* root){
    char path[MAX_DESCRIPTION];
    TreeNode* node;
    scanf("%s", path);
    if((node = findnode(root, path)) == NULL) return NOT_FOUND;
    return node->item->value == NULL ? NO_DATA : node->item->value;
}

/* Reads a path and looks for a node with such path in the tree rooted at root.
   Prints the description of the children of that node (in alphabetical order), 
   if there is such, and NOT_FOUND otherwise. */
void list(TreeNode* root){
    char path[MAX_DESCRIPTION];
    TreeNode* node;
    if(getchar() == '\n'){
        print_AVL(root->alf_children);
        return;
    }
    scanf("%s", path);
    if((node = findnode(root, path)) == NULL)
        printf("%s", NOT_FOUND);
    else print_AVL(node->alf_children);
}

/* Looks for a node with the given value. Returns a string with it's path if 
   there is such node, and NOT_FOUND otherwise. */
char* search(TreeNode* root, char* value, char* path){
    char* new_path = NULL, * res;
    LLNode* x = root->first; Item* item;
    while(x != NULL){
        item = x->node->item;
        new_path = (char*) realloc(new_path, 
            sizeof(char)*(strlen(path)+strlen(item->description)+2));
        strcpy(new_path, path); strcat(new_path, "/");
        strcat(new_path, item->description);
        if(item->value != NULL && !strcmp(item->value, value)){
            new_path = realloc(new_path, sizeof(char)*(strlen(new_path)+2));
            strcat(new_path, "\n");
            return new_path;
        }
        if(strcmp((res = search(x->node, value, new_path)), NOT_FOUND))
            return res;
        x = x->next;
    }
    free(new_path);
    return NOT_FOUND;
}

/* Reads a path and looks for a tree node with such path. If there is such, 
   deletes it and all it's offspring, and prints NOT_FOUND otherwise. */
void delete(TreeNode** root){
    char path[MAX_DESCRIPTION];
    TreeNode* node;
    if(getchar() == '\n'){
        destroy_Tree(*root);
        *root = newnode();
        return;
    }
    scanf("%s", path);
    if((node = findnode(*root, path)) == NULL){
        printf("%s", NOT_FOUND); 
        return;
    }
    if(node->parent != NULL){
        node->parent->first = deletenode_LL(node->parent->first, node);
        node->parent->alf_children = deletenode_AVL(node->parent->alf_children, node);
    }else{
        destroy_Tree(node);
    }
}

int main(){
    /* Strings to hold the command and a value for the command search. */
    char command[7], value[MAX_DESCRIPTION];
    /* Tree that holds all directories in the system and their hierarchy. */
    TreeNode* Root = newnode();
    while(scanf("%s", command) == 1){
        if(!strcmp(command, "help")){
            printf("%s%s%s%s%s%s%s%s", HELP_TEXT, QUIT_TEXT, SET_TEXT, 
            PRINT_TEXT, FIND_TEXT, LIST_TEXT, SEARCH_TEXT, DELETE_TEXT);
        }else if(!strcmp(command, "quit")){
            destroy_Tree(Root);
            break;
        }else if(!strcmp(command, "set")){
            set(Root);
        }else if(!strcmp(command, "print")){
            print(Root, "");
        }else if(!strcmp(command, "find")){
            printf("%s", find(Root));
        }else if(!strcmp(command, "list")){
            list(Root);
        }else if(!strcmp(command, "search")){
            getchar(); fgets(value, MAX_DESCRIPTION, stdin);
            printf("%s", search(Root, value, ""));
        }else if(!strcmp(command, "delete")){
            delete(&Root);
        }
    }
    return 0;
}
