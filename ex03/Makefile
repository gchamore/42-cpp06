# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 16:41:00 by gchamore          #+#    #+#              #
#    Updated: 2024/11/06 17:09:11 by gchamore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = form

CC = c++

CFLAGS = -g -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

OBJ_DIR = objs

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

DEPS = $(OBJS:.o=.d)

TO_DELETE = Fred_shrubbery

GREEN = \033[1;32m
YELLOW = \033[1;33m
ORANGE = \033[38;5;214m
RESET = \033[0m
CHECK_MARK = \033[1;32m✔\033[0m

all: first_header $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) && printf "\n$(CHECK_MARK) $(GREEN)Compilation Succeeded$(RESET)\n\n\n"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(TO_DELETE)

re: fclean all

.PHONY: all clean fclean re

info: header

-include $(DEPS)

first_header:
	@echo "\n $$FIRST_HEADER \n"

define FIRST_HEADER
$(ORANGE)██████╗██████╗ ██████╗      ██████╗ ███████╗
██╔════╝██╔══██╗██╔══██╗    ██╔═████╗██╔════╝
██║     ██████╔╝██████╔╝    ██║██╔██║███████╗
██║     ██╔═══╝ ██╔═══╝     ████╔╝██║╚════██║
╚██████╗██║     ██║         ╚██████╔╝███████║
 ╚═════╝╚═╝     ╚═╝          ╚═════╝ ╚══════╝$(RESET) 

$(YELLOW)EX 03$(RESET)
endef
export FIRST_HEADER

header:
	@echo "$$FIRST_HEADER"
