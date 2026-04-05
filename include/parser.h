#ifndef PARSER_H
#define PARSER_H

#define MAX_TOKENS 64

struct Command{
    char *name;             // Pointer to args[0], the command name
    char *args[MAX_TOKENS]; // Stores all tokens
    int   argc;             // Stores token count
};

void tokenizer(char **, char *);

#endif