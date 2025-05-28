# Флаги для компиляции
CC = gcc
CFLAGS = -I../../include -Wall -Wextra -Wpedantic -g

# Пути
BUILD_OBJ = ../../../build/obj
BUILD_BIN = ../../../build/bin
RECTANGULAR_LIB = $(BUILD_BIN)/libmatrix_rectangular.a

# Название объектных файлов
OBJ_RECTANGULAR = $(BUILD_OBJ)/matrix_rectangular.o

# Сборка прямоугольной матрицы
rectangular: $(OBJ_RECTANGULAR)
	@mkdir -p $(BUILD_BIN)
	@ar rcs $(RECTANGULAR_LIB) $(OBJ_RECTANGULAR)


# Компиляция объектных файлов
$(OBJ_RECTANGULAR): rectangular/matrix.c
	@mkdir -p $(BUILD_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@


# Очистка 
clean:
	rm -f $(OBJ_RECTANGULAR) $(RECTANGULAR_LIB)


.PHONY: rectangular clean