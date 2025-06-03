# Флаги для компиляции
CC = gcc
CFLAGS = -I../../include -Wall -Wextra -Wpedantic -g

# Пути
BUILD_OBJ = ../../../build/obj
BUILD_BIN = ../../../build/bin
VECTOR_LIB = $(BUILD_BIN)/libindex_vector.a

# Название объектных файлов
OBJ_VECTOR = $(BUILD_OBJ)/index_vector.o

# Сборка Сборка просматриваемой таблицы на векторе
vector: $(OBJ_VECTOR)
	@mkdir -p $(BUILD_BIN)
	@ar rcs $(VECTOR_LIB) $(OBJ_VECTOR)

$(OBJ_VECTOR): vector/index.c
	@mkdir -p $(BUILD_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка 
clean:
	rm -f $(OBJ_VECTOR) $(LIB)

.PHONY: vector clean