
NAME 	=	minishell

CC 		= 	gcc
CFLAGS 	=	-Wall -Wextra -Werror ${HEADER}
RM 		=	rm -rf

FSRC	=	
F_DIR 	= 	libft/
F_PTH	= 	$(addprefix $(F_DIR), $(FSRC))
O_DIR 	= 	libft/objs/
LIBFT	= 	libft/libft.a

H_SRC 	=	minishell.h 
H_DIR	= 	includes/
H_PTH	=	$(addprefix $(H_DIR), $(H_SRC))

HEADER	= -I includes/



SRCS 	=	check.c signal.c parse.c prompt.c subsplit.c \
			divide.c update.c expand.c  trimm_all.c redir.c 

S_DIR	= 	srcs/
S_PTH	= 	$(addprefix $(S_DIR), $(SRCS))
OBJ_S 	=	$(S_PTH:.c=.o)


# SRCF	= 	
# F_DIR	=	libft/
# F_PTH	= 	$(addprefix $(F_DIR), $(SRCF))
# OBJ_F	= 	$(F_PTH:.c=.o)

RDPATH = readline/libreadline.a readline/libhistory.a

SRCS_PATH = src/


# %.o: %.c $(HEADER) Makefile
# 				@$(CC) $(CFLAGS)  -I$(F_DIR) -I$(H_DIR) -c $< -o $@

# $(NAME)	:	$(OBJ_S)
# 				$(CC)  $(OBJ_S) -o $(NAME)  -lcurses -lreadline  libft/libft.a 

# OBJS = $(SRCS_FILES:.c=.o)

$(NAME): 	$(OBJ_S)
	-@$(MAKE) -C $(F_DIR) 
	-@$(CC) $(CFLAGS) $(OBJ_S) $(LIBFT) $(RDPATH) -lcurses -lreadline -o $(NAME) 



all		:	$(NAME)

clean	:
				$(RM) $(OBJ_F) 
				$(RM) $(OBJ_S) 
				
fclean	:	clean
				$(RM) $(O_DIR)
				$(RM) $(NAME)

re		:	fclean all

.PHONY	:	clean fclean re bonus
