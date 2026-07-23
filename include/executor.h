#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "../include/parser.h"

// Executes the program whose name is stored in the first entry of the args array field of the Command passed
void executor(Command);

// Helper for output and input redirection
void setup_redirect(const char*, int, int);

#endif