#ifndef PARSER_H
#define PARSER_H

#define MAX_TOKENS 64

typedef struct Command{
    char *name;             // Pointer to args[0], the command name
    char *args[MAX_TOKENS]; // Stores all tokens
    int   argc;             // Stores token count
    char *output_file;      // Stores filename for output redirection
    char *input_file;       // Stores filename for input redirection
} Command;

int tokenizer(char **, char *);
Command parse(char **);

#endif