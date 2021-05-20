#include "main.h"

void set(TreeNode* root){
    char path[MAX_DESCRIPTION], value[MAX_DESCRIPTION]; char* token;
    TreeNode* current_node = root, * new_node;
    Item* new_item;
    scanf("%s", path);
    token = strtok(path, "/");
    while(token != NULL){
        new_item = newitem(token, NULL);
        if((new_node = findchildren(current_node, new_item)) == NULL){
            new_node = addchildren(current_node, new_item);
        }
        current_node = new_node;
        token = strtok(NULL, "/");
    }
    fgets(value, MAX_DESCRIPTION, stdin);
    current_node->item->value = strdup(value);
}

/*char* find(TreeNode* root);
Lembrar de retornar NOT_FOUND se findAVL == NULL e NO_DATA se valor==NULL*/

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
            /*printf("%s\n", find(Root));*/
        }if(!strcmp(command, "list")){
            
        }if(!strcmp(command, "search")){
            
        }if(!strcmp(command, "delete")){
            
        }
    }
    /*destroy_Tree(Root);*/
    return 0;
}
