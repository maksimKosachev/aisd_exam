# Флаги компиляции
CC = gcc
CFLAGS = -Isrc -Wall -Wextra -Wpedantic -g


# Поддерживаемые структуры и реализации в каждом разделе
UNITS = elementary
elementary_STRUCTURES = stack linear_queue circular_queue matrix deque
IMPLEMENTATIONS = list vector rectangular


# Макрос для создания целей вида elementary/stack/list
define make_unit_target
$(unit)/$(structure)/$(implementation):
	@echo "📦 Собираем библиотеку: $(unit)/$(structure)/$(implementation)"
	@$(MAKE) --silent -C src/$(unit)/$(structure) -f Makefile $(implementation)
	@echo "💅 Библиотека собрана"
endef

# Генерируем все возможные цели
$(foreach unit,$(UNITS), \
    $(foreach structure,$($(unit)_STRUCTURES), \
        $(foreach implementation,$(IMPLEMENTATIONS), \
            $(eval $(call make_unit_target,$(unit),$(structure),$(implementation))) \
        ) \
    ) \
)

# Шаблон тестовой цели
test/%:
	@echo "🕵️  Тестируем: $*"
	
	@set -- $(subst /, , $*); \
	SECTION=$$1; STRUCTURE=$$2; IMPLEMENTATION=$$3; \
	$(MAKE) --silent $$SECTION/$$STRUCTURE/$$IMPLEMENTATION; \
	FILE=$${STRUCTURE}_$${IMPLEMENTATION}_test; \
	TEST_SRC=tests/$$SECTION/$$STRUCTURE/$$FILE.c; \
	if [ ! -f $$TEST_SRC ]; then \
	echo "❌ Файл теста не найден: $$TEST_SRC"; exit 1; fi; \
	TEST_OBJ=build/tests/obj/$$FILE.o; \
	TEST_BIN=build/tests/bin/$$FILE; \
	LIB="-Lbuild/bin -l$${STRUCTURE}_$${IMPLEMENTATION}"; \
	mkdir -p build/tests/obj build/tests/bin; \
	echo "🧰 Компилируем $$TEST_SRC"; \
	$(CC) $(CFLAGS) -c $$TEST_SRC -o $$TEST_OBJ; \
	echo "🧱 Линкуем $$TEST_OBJ"; \
	$(CC) $(CFLAGS) $$TEST_OBJ $$LIB -o $$TEST_BIN; \
	echo "🚀 Запуск"; \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes $$TEST_BIN;\
	echo "💅 Тест завершён"

# Очистка
clean:
	@echo "🔥 Полная очистка build/"
	@rm -rf build/


# Генерация фиктивных целей
PHONY_TARGETS := \
	$(foreach unit,$(UNITS), \
		$(foreach structure,$($(unit)_STRUCTURES), \
			$(foreach implementation,$(IMPLEMENTATIONS), \
				$(unit)/$(structure)/$(implementation) \
			) \
		) \
	)

.PHONY: clean test $(PHONY_TARGETS)