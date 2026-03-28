#include <stdio.h>
#include <string.h>
#include <unistd.h>

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
        if (input[len - 1] == '\n') input[len - 1] = '\0';

        // Edge case: Empty input
        // TODO

        // Exit condition
        if (strcmp(input, "exit") == 0) break;
    }

    return 0;
}