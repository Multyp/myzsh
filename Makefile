##
## EPITECH PROJECT, 2024
## zsh
## File description:
## Makefile
##

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -pthread
CPPFLAGS = -iquote includes

SRCDIR = src
BUILDDIR = build

TARGET = myzsh

SRCS := $(wildcard $(SRCDIR)/*.c) \
        $(wildcard $(SRCDIR)/*/*.c) \
        $(wildcard $(SRCDIR)/*/*/*.c)
OBJS := $(SRCS:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)
DEPS := $(OBJS:.o=.d)

# ANSI color codes
COLOR_GREEN = $$(tput setaf 2)
COLOR_YELLOW = $$(tput setaf 3)
COLOR_RESET = $$(tput sgr0)

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "$$(tput bold)$(COLOR_GREEN)Building \
	$(TARGET)$(COLOR_RESET)"

	@$(CC) $(CFLAGS) $(OBJS) -o $@

	@echo "$$(tput bold)$(COLOR_GREEN)$(TARGET) \
	built successfully$(COLOR_RESET)"

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$$(tput bold)$(COLOR_YELLOW)Compiling $<$(COLOR_RESET)"

	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

	@echo "$$(tput bold)$(COLOR_YELLOW)$@ created successfully$(COLOR_RESET)"
	@echo

clean:
	@echo "$$(tput bold)$(COLOR_YELLOW)Cleaning$(COLOR_RESET)"
	@$(RM) -r $(BUILDDIR)

fclean: clean
	@echo "$$(tput bold)$(COLOR_YELLOW)Full Cleaning$(COLOR_RESET)"
	@$(RM) $(TARGET)

re: fclean all

-include $(DEPS)
