#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "../include/parser.h"

int main(){
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));

    char input[100];
    // Continuous shell loop
    while(1){
        printf("mysh:%s> ", cwd);               // Shell prompt
        
        fgets(input, sizeof(input), stdin);     // Reading user input with fgets

        // Replacing trailing \n with \0
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') input[len - 1] = '\0';
        
        // Edge case: Empty input
        // If the first character is the null character, the input is empty, so the loop is restarted.
        if (input[0] == '\0') continue;

        // Exit condition
        if (strcmp(input, "exit") == 0) break;

        // Tokenization
        char **tokens[MAX_TOKENS];
        tokenizer(tokens, input);

        // Test loop to see the contents of tokens after tokenization
        int i = 0;
        while (tokens[i] != NULL){
            printf("%s ", tokens[i]);
            ++i;
        }
    }

    return 0;
}