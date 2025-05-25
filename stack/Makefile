CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -Wpedantic -g
SRC_LIST = list/stack_list.c
OBJ_LIST = list/stack_list.o
LIB = libstack.a

list: $(OBJ_LIST)
	ar rcs $(LIB) $(OBJ_LIST)

compile:
	$(CC) $(CFLAGS) -L. main.c -lstack -o prog

run:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./prog

cycle_list: list compile run

