#include <string.h> 

#include "../include/parser.h"

// Function to tokenize an input string using strtok and store each token in the array tokens
void tokenizer(char **tokens, char *input){
    char *tok = strtok(input, " \t\n"); // First token
    
    // Storing non-NULL tokens into the array
    int i = 0;
    while (tok != NULL){
        // Boundary check. Inserting token only if i is within the bounds of "tokens"
        if (i < MAX_TOKENS){
            tokens[i] = tok;
            tok = strtok(NULL, " \t\n");

            ++i;
        }
        else break;
    }

    tokens[i < MAX_TOKENS ? i : MAX_TOKENS - 1] = NULL;   // Making the last entry of tokens NULL
}