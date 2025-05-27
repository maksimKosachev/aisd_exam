# Флаги для компиляции
CC = gcc
CFLAGS = -I../../include -Wall -Wextra -Wpedantic -g

# Пути
BUILD_OBJ = ../../../build/obj
BUILD_BIN = ../../../build/bin
LIB = $(BUILD_BIN)/liblinear_queue.a

# Название объектных файлов
OBJ_LIST = $(BUILD_OBJ)/linear_queue_list.o
OBJ_VECTOR = $(BUILD_OBJ)/linear_queue_vector.o

# Сборка стека на списке
list: $(OBJ_LIST)
	@mkdir -p $(BUILD_BIN)
	@ar rcs $(LIB) $(OBJ_LIST)

# Сборка стека на векторе
vector: $(OBJ_VECTOR)
	@mkdir -p $(BUILD_BIN)
	@ar rcs $(LIB) $(OBJ_VECTOR)

# Компиляция объектных файлов
$(OBJ_LIST): list/linear_queue.c
	@mkdir -p $(BUILD_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_VECTOR): vector/linear_queue.c
	@mkdir -p $(BUILD_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка 
clean:
	rm -f $(OBJ_LIST) $(OBJ_VECTOR) $(LIB)

.PHONY: list vector clean