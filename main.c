#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tree.h>
#include <linkedlist.h>

/* Textos para o comando help. */
#define HELP_TEXT "help: Imprime os comandos disponíveis.\n"
#define QUIT_TEXT "quit: Termina o programa.\n"
#define SET_TEXT "set: Adiciona ou modifica o valor a armazenar.\n"
#define PRINT_TEXT "print: Imprime todos os caminhos e valores.\n"
#define FIND_TEXT "find: Imprime o valor armazenado.\n"
#define LIST_TEXT "list: Lista todos os componentes de um caminho.\n"
#define SEARCH_TEXT "search: Procura o caminho dado um valor.\n"
#define DELETE_TEXT "delete: Apaga um caminho e todos os subcaminhos.\n"
/* Numero maximo de caracteres para o valor de um caminho. */
#define MAX_VAL_DESCRIPTION 65535

int main(){
    while(1){
        char command[7];
        scanf("%s", command);
        if(!strcmp(command, "help")){
            printf("%s%s%s%s%s%s%s%s", HELP_TEXT, QUIT_TEXT, SET_TEXT, 
            PRINT_TEXT, FIND_TEXT, LIST_TEXT, SEARCH_TEXT, DELETE_TEXT);
        }if(!strcmp(command, "quit")){
            break;
        }if(!strcmp(command, "set")){
            set();
        }if(!strcmp(command, "print")){

        }if(!strcmp(command, "find")){

        }if(!strcmp(command, "list")){

        }if(!strcmp(command, "search")){
            
        }if(!strcmp(command, "delete")){}
    }
    return 0;
}
