# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 11:15:47 by cmariot           #+#    #+#              #
#    Updated: 2021/11/30 13:09:48 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                          PROJECT'S DIRECTORIES                               #
# **************************************************************************** #

NAME			= philo
SRCS_DIR		= srcs
INCL_DIR		= includes
OBJS_DIR		= objs/


# **************************************************************************** #
#                         COMPILATION AND LINK FLAGS                           #
# **************************************************************************** #

CC				= gcc

CFLAGS			= -Wall -Wextra -Werror
CFLAGS			+= -I $(INCL_DIR)

LFLAGS			= -Wall -Wextra -Werror

# Debug flag, use with 'make DEBUG=1'
ifeq ($(DEBUG), 1)
	CFLAGS		+= -g3
	LFLAGS		+= -g3
endif


# **************************************************************************** #
#                                SOURCE FILES                                  #
# **************************************************************************** #

SRCS			= main.c \
				  init_rules.c \
				  get_time.c \
				  create_threads.c \
				  routine.c \
				  print_status.c \
				  check_end.c \
				  clean_exit.c

SRC				:= $(notdir $(SRCS))

OBJ				:= $(SRC:.c=.o)

OBJS			:= $(addprefix $(OBJS_DIR), $(OBJ))

VPATH			:= $(SRCS_DIR) $(OBJS_DIR) $(shell find $(SRCS_DIR) -type d)

# **************************************************************************** #
#									COLORS                                     #
# **************************************************************************** #

GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m


# **************************************************************************** #
#                             MAKEFILE'S RULES                                 #
# **************************************************************************** #

all : $(NAME)

# Compiling
srcs_compil :
		@printf "$(YE)Source code compilation ... \n$(RC)"

$(OBJS_DIR)%.o : %.c
		@mkdir -p $(OBJS_DIR)
		@$(CC) $(CFLAGS) -pthread -c $< -o $@
		@printf "$(YE)$(CC) $(CFLAGS) -c $< -o $@ ✅ \n$(RC)"
		
# Linking
#
obj_link :
		@printf "$(YE)$(NAME) compilation success !\n\n$(RC)"
		@printf "$(GR)Object files linking ...\n$(CC) $(LFLAGS) $(OBJS) $(LIB_LFLAGS) $(RC)\n"

$(NAME)	: srcs_compil $(SRCS) $(OBJS) obj_link
		@$(CC) $(LFLAGS) $(OBJS) -pthread -o $(NAME)
		@printf "$(GR)Success !\n$(NAME) is ready.\n\n$(RC)"

# Check 42 norm 
norm :
		@norminette srcs includes

# Remove object files
clean :
		@printf "$(RE)Removing $(OBJS_DIR) ... "
		@rm -rf $(OBJS_DIR)
		@printf "Done\n"

# Remove object and binary files
fclean :
		@printf "$(RE)Removing $(OBJS_DIR) ... "
		@rm -rf $(OBJS_DIR)
		@printf "Done\n"
		@printf "$(RE)Removing $(NAME) ... "
		@rm -f $(NAME)
		@printf "Done\n"

# Remove all and recompile
re :	 fclean all

.PHONY : clean fclean
