#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 17:53:38 by maurodri          #+#    #+#              #
#    Updated: 2025/07/01 18:21:20 by maurodri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

MANDATORY_DIR := ./

FILES := main.cpp \
	Bureaucrat.cpp \
	AForm.cpp \
	ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp \
	Intern.cpp


OBJ_DIR := ./obj/
MANDATORY_OBJS := $(addprefix $(OBJ_DIR), $(patsubst %.cpp, %.o, $(FILES)))
DEP_FLAGS := -MP -MD
VPATH := $(MANDATORY_DIR)
CFLAGS := -g3 -std=c++98 -Wall -Wextra -Werror
CC := c++

NAME := bureau
INCLUDES := -I $(MANDATORY_DIR)
OBJS := $(MANDATORY_OBJS)
ETAGS_BASE := $(MANDATORY_DIR)

DEP_FILES := $(patsubst %.o, %.d, $(OBJS))

all: $(NAME)

$(NAME): $(OBJS)
	etags $$(find . -name '*.[ch]pp')
	$(CC) $(CFLAGS) $^ $(INCLUDES) -o $@

$(OBJS): $(OBJ_DIR)%.o : %.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DEP_FLAGS) -o $@ -c $< $(INCLUDES)

$(OBJ_DIR):
	@mkdir -p $@

.PHONY: all clean fclean re bonus

clean:
	rm -fr $(OBJ_DIR) **/*~ *~ **/.#*

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP_FILES)
