CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Specify the target executable
TARGET = main

# Specify source files
SRCS = main.c student.c

# Specify object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to link object files into the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)
