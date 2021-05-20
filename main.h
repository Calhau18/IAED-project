#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

/* Textos para o comando help. */
#define HELP_TEXT "help: Imprime os comandos disponíveis.\n"
#define QUIT_TEXT "quit: Termina o programa.\n"
#define SET_TEXT "set: Adiciona ou modifica o valor a armazenar.\n"
#define PRINT_TEXT "print: Imprime todos os caminhos e valores.\n"
#define FIND_TEXT "find: Imprime o valor armazenado.\n"
#define LIST_TEXT "list: Lista todos os componentes de um caminho.\n"
#define SEARCH_TEXT "search: Procura o caminho dado um valor.\n"
#define DELETE_TEXT "delete: Apaga um caminho e todos os subcaminhos.\n"
/* Textos de erro. */
#define NOT_FOUND "not found"
#define NO_DATA "no data"
/* Numero maximo de caracteres para o valor de um caminho. */
#define MAX_DESCRIPTION 65535+1
