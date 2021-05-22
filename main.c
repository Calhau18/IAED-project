#include "main.h"

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

char* find(TreeNode* root){
    char path[MAX_DESCRIPTION];
    TreeNode* node;
    scanf("%s", path);
    if((node = findnode(root, path)) == NULL) return NOT_FOUND;
    return node->item->value == NULL ? NO_DATA : node->item->value;
}

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

char* search(TreeNode* root, char* value, char* path){
    char* new_path = NULL, * res;
    LLNode* x = root->first; Item* item;
    while(x != NULL){
        item = x->node->item;
        new_path = (char*) realloc(new_path, 
            sizeof(char)*(strlen(path)+strlen(item->description)+2));
        strcpy(new_path, path); strcat(new_path, "/");
        strcat(new_path, item->description);
        if(item->value != NULL && !strcmp(item->value, value))
            return new_path;
        if(strcmp((res = search(x->node, value, new_path)), NOT_FOUND))
            return res;
        x = x->next;
    }
    free(new_path);
    return NOT_FOUND;
}

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
    /* note-se que o deletenode_AVL destroi a diretoria. */
}

int main(){
    /* Comando lido. */
    char command[7], value[MAX_DESCRIPTION];
    /* Árvore que guarda os componentes do sistema, de acordo com a sua 
    hierarquia. */
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
            printf("%s\n", search(Root, value, ""));
        }else if(!strcmp(command, "delete")){
            delete(&Root);
        }
    }
    return 0;
}
