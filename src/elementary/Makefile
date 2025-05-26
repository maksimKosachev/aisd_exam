STRUCTURES = stack
IMPLEMENTATIONS = list vector

# Цель по умолчанию
all:
	@echo "Используй: make <структура>/<реализация>"
	@echo "Например: make stack/list"

# Автоматически объявляем цели вида stack/list и делегируем их
define make_target
$(structure)/$(implementation):
	$(MAKE) -C $(structure) -f Makefile $(implementation)
endef

# Генерация всех целей
$(foreach structure,$(STRUCTURES), \
  $(foreach implementation,$(IMPLEMENTATIONS), \
    $(eval $(call make_target,$(structure),$(implementation))) \
  ) \
)

# Очистка
clean:
	$(foreach structure,$(STRUCTURES),$(MAKE) -C $(structure) clean;)


GENERATED_TARGETS = $(foreach s,$(STRUCTURES),$(foreach i,$(IMPLEMENTATIONS),$(s)/$(i)))

.PHONY: all clean $(GENERATED_TARGETS)