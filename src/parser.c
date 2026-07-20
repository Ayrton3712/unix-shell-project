#include <stdio.h>
#include <string.h> 

#include "../include/parser.h"

// Function to tokenize an input string using strtok and store each token in the array tokens
int tokenizer(char **tokens, char *input){
    char *tok = strtok(input, " \t\n"); // First token
    
    // Storing non-NULL tokens into the array
    int i = 0;
    while (tok != NULL){
        // Checking if token limit has been reached
        if (i == MAX_TOKENS - 1){
            printf("Too many arguments (max is %d). Try again with fewer arguments\n", MAX_TOKENS - 1);
            return -1;
        }
        tokens[i] = tok;        
        tok = strtok(NULL, " \t\n");    // Processing next token
        
        ++i;
    }

    tokens[i] = NULL;   // Making the last entry of tokens NULL

    return 0;
}

// Function to parse tokens
Command parse(char **tokens, int *in, int *out){
    // Set flags to 0
    *in = 0;
    *out = 0;
    
    Command cmd = {0};  // Command struct with fields initialized to zero/NULL
    
    // Checking if tokens array is empty first
    if (tokens[0] == NULL) return cmd;
        
    cmd.name = tokens[0];

    // Copying the tokens into args
    int i = 0;
    while (tokens[i] != NULL){
        if (strcmp(tokens[i], ">") != 0){
            cmd.args[i] = tokens[i];
            ++i;
        }
        else if (strcmp(tokens[i], ">") == 0){
            *out = 1;
            ++i;
            cmd.output_file = tokens[i];
            --i;
            break;
        }
    }
    cmd.args[i] = NULL; // Making the last entry of args NULL

    cmd.argc = i; // Storing token count, including name

    return cmd;
}