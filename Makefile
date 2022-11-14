# NAME 	=	minishell

# CC 		= 	gcc
# CFLAGS 	=	-Wall -Wextra -Werror
# RM 		=	rm -rf

# LIBFT	=	libft/libft.a

# H_SRC 	=	minishell.h 
# H_DIR	= 	incs/
# HEADER	=	$(addprefix $(H_DIR), $(H_SRC))

# SRCS 	=	main.c prompt.c signal.c parse.c subsplit.c update.c
# S_DIR	= 	srcs/
# S_PTH	= 	$(addprefix $(S_DIR), $(SRCS))
# OBJ_S 	=	$(S_PTH:.c=.o)


# %.o: %.c $(HEADER) Makefile
# 				@$(CC) $(CFLAGS)  -I$(H_DIR) -I$(F_DIR) -c $< -o $@

# $(NAME)	:	$(OBJ_F) $(OBJ_S)
# 				$(CC) $(LIBFT) $(OBJ_S) -o $(NAME)  -lcurses  readline/libreadline.a readline/libhistory.a

# all		:	$(NAME)

# clean	:
# 				$(RM) $(OBJ_F) 
# 				$(RM) $(OBJ_S) 

# fclean	:	clean
# 				$(RM) $(NAME)

# re		:	fclean all

# .PHONY	:	clean fclean re bonus


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


<<<<<<< HEAD
SRCS 	=	main.c prompt.c signal.c parse.c subsplit.c update.c 
=======
SRCS 	=	check.c signal.c parse.c prompt.c subsplit.c \
<<<<<<< HEAD
			divide.c update.c #expand.c 
>>>>>>> 0899604fbd76ebb5d884b258fef592fcc32fd7f1
=======
			divide.c update.c expand.c  trimm_all.c redir.c 
>>>>>>> refs/remotes/caliss/master
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

<<<<<<< HEAD
.PHONY	:	clean fclean re bonus
=======
.PHONY	:	clean fclean re bonus

>>>>>>> 0899604fbd76ebb5d884b258fef592fcc32fd7f1
