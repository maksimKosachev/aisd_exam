UNITS = elementary

# Поддерживаемые структуры и реализации в каждом разделе
elementary_STRUCTURES = stack queue
IMPLEMENTATIONS = list vector

# Цель по умолчанию
all:
    @echo "Используй: make <раздел>/<структура>/<реализация>"
    @echo "Например: make elementary/stack/list"

# Макрос для создания целей вида elementary/stack/list
define make_unit_target
$(unit)/$(structure)/$(implementation):
	$(MAKE) -C src/$(unit)/$(structure) -f Makefile $(implementation)
endef

# Генерируем все возможные цели
$(foreach unit,$(UNITS), \
    $(foreach structure,$($(unit)_STRUCTURES), \
        $(foreach implementation,$(IMPLEMENTATIONS), \
            $(eval $(call make_unit_target,$(unit),$(structure),$(implementation))) \
        ) \
    ) \
)

# Список всех сгенерированных целей
GENERATED_TARGETS = \
    $(foreach s,$(UNITS), \
        $(foreach t,$($(s)_STRUCTURES), \
            $(foreach i,$(IMPLEMENTATIONS), \
                $(s)/$(t)/$(i) \
            ) \
        ) \
    )

# Очистка
clean:
	rm -rf build/

# Все фиктивные цели
.PHONY: all clean $(GENERATED_TARGETS)