#include <string.h> 

#include "../include/parser.h"

void tokenizer(char **tokens, char *input){
    char *tok = strtok(input, " \t\n");
    
    int i = 0;
    while (tok != NULL){
        tokens[i] = tok;
        tok = strtok(NULL, " \t\n");
    }
}