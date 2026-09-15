CC      := clang
CFLAGS  := -std=c23 -Wall -Wextra -Werror -g
SRCDIR  := 02-practice
BINDIR  := build/bin

SOURCES := $(shell find $(SRCDIR) -name '*.c' -type f)
TARGETS := $(addprefix $(BINDIR)/,$(notdir $(SOURCES:.c=)))

.PHONY: all clean

all: $(TARGETS)

define compile_rule
$(BINDIR)/$(notdir $(1:.c=)): $(1)
	@mkdir -p $(BINDIR)
	$$(CC) $$(CFLAGS) $$< -o $$@
endef

$(foreach src,$(SOURCES),$(eval $(call compile_rule,$(src))))

clean:
	rm -rf $(BINDIR)
