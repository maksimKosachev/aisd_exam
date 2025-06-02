#include "../../../src/tables/regular/list/regular.h"
#include <assert.h>


int main() {
    Table *t = new_table();
    assert(t != NULL); // Таблица должна успешно выделиться

    // Тест 1: Вставка уникальных ключей
    assert(insert_node(t, 1, 100) == ALL_GOOD);
    assert(insert_node(t, 2, 200) == ALL_GOOD);
    assert(insert_node(t, 3, 300) == ALL_GOOD);

    // Тест 2: Повторная вставка ключа — ошибка
    assert(insert_node(t, 2, 222) == KEY_ALREADY_EXISTS);

    // Тест 3: Поиск существующего ключа
    Node *n = find_node(t, 3);
    assert(n != NULL);
    assert(n->info == 300);

    // Тест 4: Поиск несуществующего ключа
    assert(find_node(t, 9999) == NULL);

    // Тест 5: Удаление существующего ключа
    assert(erase_node(t, 2) == ALL_GOOD);
    assert(find_node(t, 2) == NULL);

    // Тест 6: Удаление несуществующего ключа
    assert(erase_node(t, 9999) == KEY_NOT_FOUND);

    // Тест 7: Вставка некорректного ключа (0 и отрицательное)
    assert(insert_node(t, 0, 123) == INCORRECT_KEY);
    assert(insert_node(t, -5, 456) == INCORRECT_KEY);

    // Тест 8: Удаление из пустой таблицы
    Table *empty = new_table();
    assert(empty != NULL);
    assert(erase_node(empty, 1) == MEMORY_ERROR);
    free_table(empty);

    free_table(t);

    printf("✅ Все тесты пройдены успешно!\n");
    return 0;
}
