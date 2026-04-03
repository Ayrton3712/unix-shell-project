#include <string.h> 

#include "../include/parser.h"

// Function to tokenize an input string using strtok and store each token in the array tokens
void tokenizer(char **tokens, char *input){
    char *tok = strtok(input, " \t\n"); // First token
    
    // Storing non-NULL tokens into the array
    int i = 0;
    while (tok != NULL){
        // Storing token only if i is within bounds of tokens, excluding the last entry
        if (i < MAX_TOKENS - 1){
            tokens[i] = tok;
            ++i;
        }
        
        tok = strtok(NULL, " \t\n");    // Processing next token
    }

    tokens[i] = NULL;   // Making the last entry of tokens NULL
}