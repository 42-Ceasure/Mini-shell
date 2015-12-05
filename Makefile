# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/16 14:40:47 by cglavieu          #+#    #+#              #
#    Updated: 2015/05/19 19:11:17 by cglavieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean, fclean, re

CC = gcc

CFLAG = -Wall -Wextra -Werror

NAME = shell

SRCDIR=		./src/
SRC=		main.c\
			swagg.c\
			env.c\
			parse_cmd.c\
			select_do.c\
			setenv.c\
			unsetenv.c\
			builtin_env.c\
			builtin_cd.c\
			sig.c\
			tildminus.c

SRCFIL=		$(addprefix $(SRCDIR),$(SRC))

OBJ = $(SRC:.c=.o)
OBJDIR = ./obj/

LIBFT = ./inc/libft/

LIBFTEXE = $(LIBFT)libft.a

INC = ./inc/

INC_LIBFT = ./inc/libft/inc/

all:    $(NAME)

$(NAME): $(addprefix $(OBJDIR),$(OBJ)) $(LIBFTEXE)
		@$(CC) $(CFLAG) -o $(NAME)\
		$(addprefix $(OBJDIR), $(OBJ)) -L $(LIBFT) -lft


$(OBJDIR)%.o: $(SRCDIR)%.c
		@mkdir -p $(OBJDIR)
		@$(CC) $(CFLAG) -I $(INC) -I  $(INC_LIBFT) -o $@ -c $<

$(LIBFTEXE): $(LIBFT)
		@make -k -s -C $(LIBFT)

clean:	
		@rm -Rf  $(OBJ)
		@make -C $(LIBFT) clean

fclean: 
		@rm -Rf  $(OBJDIR)
		@rm -f $(NAME)
		@make -C $(LIBFT) fclean

re:		fclean all
