# Флаги для компиляции
CC = gcc
CFLAGS = -I../../include -Wall -Wextra -Wpedantic -g

# Пути
BUILD_OBJ = ../../../build/obj
BUILD_BIN = ../../../build/bin
RECTANGULAR_LIB = $(BUILD_BIN)/libmatrix_rectangular.a
JAGGED_LIB = $(BUILD_BIN)/libmatrix_jagged.a

# Название объектных файлов
OBJ_RECTANGULAR = $(BUILD_OBJ)/matrix_rectangular.o
OBJ_JAGGED = $(BUILD_OBJ)/matrix_jagged.o

# Сборка прямоугольной матрицы
rectangular: $(OBJ_RECTANGULAR)
	@mkdir -p $(BUILD_BIN)
	@ar rcs $(RECTANGULAR_LIB) $(OBJ_RECTANGULAR)

# Сборка зубчатого массива
jagged: $(OBJ_JAGGED)
	@mkdir -p $(BUILD_BIN)
	@ar rcs $(JAGGED_LIB) $(OBJ_JAGGED)

# Компиляция объектных файлов
$(OBJ_RECTANGULAR): rectangular/matrix.c
	@mkdir -p $(BUILD_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_JAGGED): jagged/matrix.c
	@mkdir -p $(BUILD_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка 
clean:
	rm -f $(OBJ_RECTANGULAR) $(OBJ_VECTOR) $(RECTANGULAR_LIB) $(JAGGED_LIB)


.PHONY: rectangular jagged clean