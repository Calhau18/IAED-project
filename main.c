#include "main.h"

void set(TreeNode* root){
    char path[MAX_DESCRIPTION], value[MAX_DESCRIPTION]; char* token;
    TreeNode* current_node = root, * new_node;
    Item* item = newitem(NULL, NULL);
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

char* find(TreeNode* root){
    char path[MAX_DESCRIPTION];
    Item* item = newitem(NULL, NULL);
    TreeNode* node;
    scanf("%s", path);
    if((node = findnode(root, path)) == NULL) return NOT_FOUND;
    return node->item->value == NULL ? NO_DATA : node->item->value;
}

void list(TreeNode* root){
    char path[MAX_DESCRIPTION];
    TreeNode* node;
    scanf("%s", path);
    if((node = findnode(root, path)) == NULL) printf("%s\n", NOT_FOUND);
    print_LL(node->hist_children);
}

void delete(TreeNode* root){
    char path[MAX_DESCRIPTION];
    TreeNode* node;
    scanf("%s", path);
    if((node = findnode(root, path)) == NULL) printf("%s\n", NOT_FOUND);
    destroy_Tree(node);
}

int main(){
    /* Comando lido. */
    char command[7], * string;
    /* Árvore que guarda os componentes do sistema, de acordo com a sua 
    hierarquia. */
    TreeNode* Root = newnode();
    while(scanf("%s", command) == 1){
        if(!strcmp(command, "help")){
            printf("%s%s%s%s%s%s%s%s", HELP_TEXT, QUIT_TEXT, SET_TEXT, 
            PRINT_TEXT, FIND_TEXT, LIST_TEXT, SEARCH_TEXT, DELETE_TEXT);
        }if(!strcmp(command, "quit")){
            destroy_Tree(Root);
            break;
        }if(!strcmp(command, "set")){
            set(Root);
        }if(!strcmp(command, "print")){

        }if(!strcmp(command, "find")){
            printf("%s\n", find(Root));
        }if(!strcmp(command, "list")){
            list(Root);
        }if(!strcmp(command, "search")){
            
        }if(!strcmp(command, "delete")){
            delete(Root);
        }
    }
    /*destroy_Tree(Root);*/
    return 0;
}
