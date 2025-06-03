#include "../../../src/tables/index/vector/index.h"
#include <assert.h>


int main() {
    Table *t = new_table(5);
    assert(t != NULL);
    assert(t->size == 0);
    assert(t->capacity == 5);

    // Вставка новых ключей
    assert(insert_node(t, 10, 100) == ALL_GOOD);
    assert(insert_node(t, 5, 50) == ALL_GOOD);
    assert(insert_node(t, 20, 200) == ALL_GOOD);
    assert(t->size == 3);

    // Повторный ключ
    assert(insert_node(t, 10, 999) == KEY_ALREADY_EXISTS);
    assert(t->size == 3);

    // Переполнение
    assert(insert_node(t, 30, 300) == ALL_GOOD);
    assert(insert_node(t, 40, 400) == ALL_GOOD);
    assert(insert_node(t, 50, 500) == FULL_STRUCTURE);

    // Поиск существующих и несуществующих
    assert(find_node(t, 10) != -1);
    assert(find_node(t, 999) == -1);

    // Удаление существующего
    assert(erase_node(t, 10) == ALL_GOOD);
    assert(t->size == 4);
    assert(find_node(t, 10) == -1);

    // Удаление несуществующего
    assert(erase_node(t, 12345) == KEY_NOT_FOUND);

    // Проверка сдвига после удаления
    assert(t->vector[0].key == 5);
    assert(t->vector[1].key == 20);
    assert(t->vector[2].key == 30);
    assert(t->vector[3].key == 40);
    
    print_table(t);
    // Освобождение
    free_table(t);

    printf("✅ Все тесты пройдены успешно!\n");
    return 0;
}