CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -Wpedantic -g
SRC_LIST = list/stack.c
OBJ_LIST = list/stack.o
SRC_VECTOR = vector/stack.c
OBJ_VECTOR = vector/stack.o
LIB = libstack.a

list: $(OBJ_LIST)
	ar rcs $(LIB) $(OBJ_LIST)

vector: $(OBJ_VECTOR)
	ar rcs $(LIB) $(OBJ_VECTOR)

compile:
	$(CC) $(CFLAGS) -L. main.c -lstack -o prog

run:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./prog

cycle_list: list compile run

cycle_vector: vector compile run

clean:
	rm -f $(OBJ_LIST) $(OBJ_VECTOR) $(LIB) prog

