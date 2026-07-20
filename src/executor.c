#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/wait.h>

#include "../include/executor.h"

void executor(Command cmd){
    pid_t pid = fork();

    if (pid == 0){ // Child path
        execvp(cmd.name, cmd.args);
        perror(cmd.name);
        exit(EXIT_FAILURE);
    }
    else if (pid == -1){ // Fork error path
        perror("fork");
    }
    else{ // Parent path
        waitpid(pid, NULL, 0);
    }
}