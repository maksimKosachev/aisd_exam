# Флаги для компиляции
CC = gcc
CFLAGS = -I../../include -Wall -Wextra -Wpedantic -g

# Пути
BUILD_OBJ = ../../../build/obj
BUILD_BIN = ../../../build/bin
VECTOR_LIB = $(BUILD_BIN)/libstack_vector.a
LIST_LIB = $(BUILD_BIN)/libstack_list.a

# Название объектных файлов
OBJ_LIST = $(BUILD_OBJ)/stack_list.o
OBJ_VECTOR = $(BUILD_OBJ)/stack_vector.o

# Сборка стека на списке
list: $(OBJ_LIST)
	@mkdir -p $(BUILD_BIN)
	@ar rcs $(LIST_LIB) $(OBJ_LIST)

# Сборка стека на векторе
vector: $(OBJ_VECTOR)
	@mkdir -p $(BUILD_BIN)
	@ar rcs $(VECTOR_LIB) $(OBJ_VECTOR)

# Компиляция объектных файлов
$(OBJ_LIST): list/stack.c
	@mkdir -p $(BUILD_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_VECTOR): vector/stack.c
	@mkdir -p $(BUILD_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка 
clean:
	rm -f $(OBJ_LIST) $(OBJ_VECTOR) $(LIB)

.PHONY: list vector clean