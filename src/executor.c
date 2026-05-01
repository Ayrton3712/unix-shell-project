#include <unistd.h>
#include <sys/wait.h>

#include "../include/executor.h"

int executor(Command cmd){
    pid_t pid = fork();

    if (pid == 0){
        execvp(cmd.name, cmd.args);
    }
    else if (pid == -1){
        printf("Child process could not be created.\n");
    }
    else{
        waitpid(pid, NULL, 0);
    }
}