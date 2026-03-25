CC = gcc
CFLAGS = -Wall -Wextra

mysh: main.c
	$(CC) $(CFLAGS) main.c -o mysh

clean:
	rm -f mysh