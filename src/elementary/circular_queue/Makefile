# Флаги для компиляции
CC = gcc
CFLAGS = -I../../include -Wall -Wextra -Wpedantic -g

# Пути
BUILD_OBJ = ../../../build/obj
BUILD_BIN = ../../../build/bin
VECTOR_LIB = $(BUILD_BIN)/libcircular_queue_vector.a
LIST_LIB = $(BUILD_BIN)/libcircular_queue_list.a

# Название объектных файлов
OBJ_LIST = $(BUILD_OBJ)/circular_queue_list.o
OBJ_VECTOR = $(BUILD_OBJ)/circular_queue_vector.o

# Сборка очереди на циклическом списке
list: $(OBJ_LIST)
	@mkdir -p $(BUILD_BIN)
	@ar rcs $(LIST_LIB) $(OBJ_LIST)

# Сборка очереди на векторе
vector: $(OBJ_VECTOR)
	@mkdir -p $(BUILD_BIN)
	@ar rcs $(VECTOR_LIB) $(OBJ_VECTOR)

# Компиляция объектных файлов
$(OBJ_LIST): list/circular_queue.c
	@mkdir -p $(BUILD_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_VECTOR): vector/circular_queue.c
	@mkdir -p $(BUILD_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка 
clean:
	rm -f $(OBJ_LIST) $(OBJ_VECTOR) $(LIB)

.PHONY: list vector clean