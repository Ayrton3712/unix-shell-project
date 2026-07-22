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
            int file_fd = open(cmd.output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);  // Open output file and store its fd
            
            dup2(file_fd, STDOUT_FILENO);   // Rewire stdout to file_fd
            close(file_fd); // Drop file_fd
        }
        // Input redirection
        if (cmd.input_file != NULL){
            int file_fd = open(cmd.input_file, O_RDONLY);   // Open input file and store its fd
            
            dup2(file_fd, STDIN_FILENO);    // Rewire stdin to file_fd
            close(file_fd); // Drop file_fd
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