# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gehebert <gehebert@42quebec.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 06:36:32 by gehebert          #+#    #+#              #
#    Updated: 2022/02/02 10:39:59 by gehebert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# _*_ Makefile _*_

NAME = libft.a
CC = gcc
CFLAGS = -g -fsanitize=address -Wall -Wextra -Werror -I $(HEADER)
RM = rm -rf

HEADER = ./

# Color Aliases
DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Make variables
PRINTF = LC_NUMERIC="en_US.UTF-8" printf
CC = gcc -MD
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
HEADER = libft.h

SRCS_DIR		= srcs
OBJS_DIR		= objs

INCS_DIR		:= incs

SRC_DIR := file
SRC_DIR += ft_to
SRC_DIR += ft_is
SRC_DIR += ft_mem
SRC_DIR += ft_str
SRC_DIR += ft_put
SRC_DIR += ft_lst
SRC_DIR += ft_mx

BIN_DIR = bin
BIN = libft.a
NAME = libft

FT_IS = ft_abs.c	\
	ft_getnbr.c		\
	ft_intcpy.c		\
	ft_intlen.c		\
	ft_isalnum.c	\
	ft_isalpha.c	\
	ft_isascii.c	\
	ft_isdigit.c	\
	ft_isnbr.c		\
	ft_isprint.c	\
	ft_isspace.c	\
	ft_iswall.c		\
	it_t.c

FT_TO =	ft_atoi.c 	ft_itoa.c 	\
	 ft_tolower.c	ft_toupper.c 

FT_MEM = ft_bzero.c ft_calloc.c \
		ft_memalloc.c ft_memccpy.c \
		ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memdel.c \
		ft_memmove.c ft_memset.c \
		ft_vcalloc.c

FT_PUT = ft_exit.c	ft_putchar_fd.c	\
		ft_putchar.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_putnbr.c	\
		ft_putstr_fd.c ft_putstr.c

FT_STR = ft_addchar.c ft_addstr.c ft_char_str.c \
		ft_findchar.c ft_split.c ft_str_char.c \
		ft_strchr.c ft_strcmp.c ft_strcpy.c \
		ft_strdup.c ft_striteri.c ft_strjoin.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c \
		ft_strmapi.c ft_strncmp.c ft_strncpy.c \
		ft_strnstr.c ft_strrchr.c ft_strstr.c \
		ft_strtrim.c ft_substr.c

FT_ARR = ft_sort_nbr.c \
	ft_all_spaces.c \
	ft_freearray.c \
	ft_arraylen.c \
	ft_free.c 	

FT_LST = ft_lstadd_back.c	\
	ft_lstadd_front.c	\
	ft_lstclear.c		\
	ft_lstdelone.c		\
	ft_lstiter.c		\
	ft_lstlast.c		\
	ft_lstsize.c		\
	ft_lstnew.c			\
	ft_lstmap.c			\
	mapi_f.c

FT_MX = ft_lst_mx.c ft_mx_dup.c \
	ft_mx_ext.c ft_mx_free.c \
	ft_mx_len.c ft_mx_lst.c \
	ft_mx_rpl.c ft_strchar_i.c \
	ft_strchr_i.c

FILES = $(FT_IS) $(FT_TO) $(FT_MEM) $(FTPUT) $(FT_STR) $(FT_LST) $(FT_MX) $(FT_ARR)

OBJS = $(FILES:%.c=(OBJSDIR)/%.o)

%.o: %.c libft.h

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


# Progress vars

all: $(NAME)

$(NAME): create_dirs $(OBJ) bonus additional
	@$(PRINTF) "\r%100s\r$(GREEN)$(BIN) is up to date!$(DEFAULT)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: create_dirs $(OBJ) $(OBJB)
	@$(AR) $(NAME) $(OBJ) $(OBJB)

$(OBJB_DIR)/%.o: $(SRCB_DIR)/%.c
	@$(eval SRCB_COUNT = $(shell expr $(SRCB_COUNT) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRCB_COUNT) $(SRCB_COUNT_TOT) $(SRCB_PCT)
	@$(CC) $(CFLAGS) -c $< -o $@

additional: create_dirs $(OBJA)
	@$(AR) $(NAME) $(OBJA)

$(OBJA_DIR)/%.o: $(SRCA_DIR)/%.c
	@$(eval SRCA_COUNT = $(shell expr $(SRCA_COUNT) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRCA_COUNT) $(SRCA_COUNT_TOT) $(SRCA_PCT)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(PRINTF) "$(CYAN)Cleaning up object files in libft...$(DEFAULT)\n"
	@$(RM) -r $(OBJ_DIR)
	@$(RM) -r $(OBJB_DIR)
	@$(RM) -r $(OBJA_DIR)

fclean: clean
	@$(RM) -r $(BIN_DIR)
	@$(PRINTF) "$(CYAN)Removed $(NAME)$(DEFAULT)\n"

create_dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJB_DIR)
	@mkdir -p $(OBJA_DIR)
	@mkdir -p $(BIN_DIR)

norminette:
	@$(PRINTF) "$(CYAN)\nChecking norm for libft...$(DEFAULT)\n"
	@norminette -R CheckForbiddenSourceHeader $(SRC_DIR) $(SRCB_DIR) $(SRCA_DIR) inc/libft.h

re: fclean
	@make all

git:
	git add .
	git commit
	git push

-include $(OBJ_DIR)/*.d
-include $(OBJB_DIR)/*.d
-include $(OBJA_DIR)/*.d

.PHONY: all bonus additional clean fclean git norminette create_dirs re i 

