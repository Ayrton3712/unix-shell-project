#include <stdio.h>
#include <unistd.h>

int main(){
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    
    // Basic shell prompt
    
    printf("mysh:%s> \n", cwd);
    return 0;
}