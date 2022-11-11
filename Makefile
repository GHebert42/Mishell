NAME 	=	minishell

CC 		= 	gcc
CFLAGS 	=	-Wall -Wextra -Werror
RM 		=	rm -rf

H_SRC 	=	minishell.h 
H_DIR	= 	includes/
HEADER	=	$(addprefix $(H_DIR), $(H_SRC))

SRCS 	=	check.c signal.c

#prompt.c signal.c parse.c subsplit.c check.c \
			get_next_line.c get_next_line_utils.c #main.c 
S_DIR	= 	srcs/
S_PTH	= 	$(addprefix $(S_DIR), $(SRCS))
OBJ_S 	=	$(S_PTH:.c=.o)

	


SRCF	= 	
F_DIR	=	libft/
F_PTH	= 	$(addprefix $(F_DIR), $(SRCF))
OBJ_F	= 	$(F_PTH:.c=.o)

%.o: %.c $(HEADER) Makefile
				@$(CC) $(CFLAGS)  -I$(H_DIR) -I$(F_DIR) -c $< -o $@

$(NAME)	:	$(OBJ_S)
				$(CC)  $(OBJ_S) -o $(NAME)  -lcurses readline/libhistory.a readline/libreadline.a libft/libft.a 

all		:	$(NAME)

clean	:
				$(RM) $(OBJ_F) 
				$(RM) $(OBJ_S) 

fclean	:	clean
				$(RM) $(NAME)

re		:	fclean all

.PHONY	:	clean fclean re bonus
