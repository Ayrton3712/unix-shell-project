#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "../include/parser.h"
#include "../include/executor.h"

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

        // Tokenization
        char *tokens[MAX_TOKENS];
        tokenizer(tokens, input);

        // Parsing
        Command cmd = parse(tokens);

        // Handling built-in commands
        // cd
        if (strcmp(cmd.name, "cd") == 0){
            if (cmd.argc == 1){
                printf("Directory not provided\n");
                continue;
            }
            else {
                if (chdir(cmd.args[1]) != -1){
                    getcwd(cwd, sizeof(cwd));   // Updating cwd with getcwd
                }
                else {
                    printf("Failed to change directory\n");
                    continue;
                }
            }
        }
        // pwd (print working directory)
        if (strcmp(cmd.name, "pwd") == 0){
            printf("%s", cwd);
        }
        // exit
        else if (strcmp(cmd.name, "exit") == 0) break;
        else executor(cmd);
    }

    return 0;
}