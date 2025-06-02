#include <assert.h>
#include "../../../src/tables/regular/vector/regular.h"


int main() {
    Table *t = new_table(3);
    assert(t != NULL);
    assert(t->capacity == 3);
    assert(t->size == 0);

    // Вставка
    assert(insert_node(t, 1, 100) == ALL_GOOD);
    assert(insert_node(t, 2, 200) == ALL_GOOD);
    assert(insert_node(t, 1, 999) == KEY_ALREADY_EXISTS);  // дубликат

    // Поиск
    assert(find_node(t, 1) != -1);
    assert(find_node(t, 2) != -1);
    assert(find_node(t, 3) == -1);

    // Удаление
    assert(erase_node(t, 2) == ALL_GOOD);
    assert(find_node(t, 2) == -1);
    assert(erase_node(t, 999) == KEY_NOT_FOUND);


    assert(insert_node(t, 3, 300) == ALL_GOOD);
    print_table(t);
    assert(insert_node(t, 4, 400) == ALL_GOOD);
    print_table(t);


    assert(insert_node(t, 5, 500) == FULL_STRUCTURE);  // после collect_garbage

    // Убедимся, что всё осталось корректно
    assert(find_node(t, 1) != -1);
    assert(find_node(t, 3) != -1);
    assert(find_node(t, 5) == -1);

    free_table(t);

    printf("✅ Все тесты пройдены успешно.\n");
    return 0;
}
