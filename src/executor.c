#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/wait.h>   // for waitpid()
#include <fcntl.h>      // for open()

#include "../include/executor.h"

void executor(Command cmd){
    pid_t pid = fork();

    if (pid == 0){ // Child path
        // Output redirection
        if (cmd.output_file != NULL){
            setup_redirect(cmd.output_file, O_CREAT | O_WRONLY | O_TRUNC, STDOUT_FILENO);
        }
        // Input redirection
        if (cmd.input_file != NULL){
            setup_redirect(cmd.input_file, O_RDONLY, STDIN_FILENO);
        }

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

void setup_redirect(const char* filename, int flags, int target_fd){
    int file_fd = open(filename, flags);

    // Open failure path
    if (file_fd == -1){
        perror(filename);
        exit(EXIT_FAILURE);
    }

    // Rewire stdin to file_fd while handling dup2 failure
    if(dup2(file_fd, target_fd) == -1){
        perror("dup2");
        exit(EXIT_FAILURE);
    }

    // Drop file_fd while handling close failure
    if(close(file_fd) == -1){
        perror("close");
        exit(EXIT_FAILURE);
    }
}