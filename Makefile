CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC_DIR = src
BUILD_DIR = build

TARGET = $(BUILD_DIR)/mysh

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/parser.c $(SRC_DIR)/executor.c
OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/parser.o $(BUILD_DIR)/executor.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET)