NAME = cpp
AUTHOR = mhabbal
COMP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJS = $(addprefix objs/, $(SRC:.cpp=.o))

SHELL := /bin/bash

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

.PHONY: all header clean fclean re

all:
	@$(MAKE) --no-print-directory header
	@$(MAKE) $(NAME)

header:
	@printf "%b" "$(OK_COLOR)"
	@echo ".------..------."
	@echo "|4.--. ||2.--. |"
	@echo "| :/\: || (\/) |"
	@echo "| :\/: || :\/: |"
	@echo "| '--'4|| '--'2|"
	@echo "'------''------'"
	@echo "MHABBAL"
	@printf "$(OBJ_COLOR)Author:   $(WARN_COLOR)$(AUTHOR)$(NO_COLOR)\n"
	@printf "$(OBJ_COLOR)Compiler: $(WARN_COLOR)$(COMP)$(NO_COLOR)\n"
	@printf "$(OBJ_COLOR)Flags:    $(WARN_COLOR)$(FLAGS)$(NO_COLOR)\n"

objs/%.o: %.cpp
	@mkdir -p $(dir $@)
	@printf "%b" "$(OBJ_COLOR)Compiling: $(NO_COLOR)$<\n"
	@$(COMP) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@printf "%b" "$(OBJ_COLOR)Linking:   $(NO_COLOR)$(NAME)\n"
	@$(COMP) $(FLAGS) -o $(NAME) $(OBJS)
	@printf "$(OK_COLOR)$(NAME) compiled successfully!$(NO_COLOR)\n"

clean:
	@rm -rf objs
	@printf "$(OBJ_COLOR)Objects removed$(NO_COLOR)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(OBJ_COLOR)$(NAME) removed$(NO_COLOR)\n"

re: fclean all
