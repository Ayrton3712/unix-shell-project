# unix-shell-project

A Unix shell written in C.

# Milestones
## Basic shell loop:
Prints a basic shell prompt showing the current working directory and takes user input until the user types "exit".

<img width="385" height="67" alt="image" src="https://github.com/user-attachments/assets/a1f65c93-5317-431d-9c7e-15cec2a3b39b" />

## Tokenization and parsing:
User inputs are split into tokens and parsed into a Command struct.

<img width="385" height="70" alt="image" src="https://github.com/user-attachments/assets/1ef03e5e-215d-4ce0-a223-3b81e1156779" />
<br>
<img width="376" height="100" alt="image" src="https://github.com/user-attachments/assets/8f5350f8-56e7-4d7c-9448-754c2840af95" />

## Process execution:
An executor function creates a child process with fork(). The child process becomes the file whose name is specified in the name field of the Command struct via execvp(), while the parent shell waits for the child process to finish via waitpid(). Example of execution with ls -l:

<img width="441" height="114" alt="image" src="https://github.com/user-attachments/assets/b7013c74-f0fb-42d9-b074-b1d8475a4ca8" />
