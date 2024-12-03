.PHONY	:	clean fclean re all

NAME		=   push_swap

#			GCC

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I $(INCLUDE) -I $(LIBFT)include
INCLUDE 	=	.

#			PUSH_SWAP

SRC_FILES	=	push_swap \
				parse
SRC 		= 	$(addsuffix .c, $(SRC_FILES))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

#			COMMON

OBJ_DIR		=	obj/

#			LIBFT

LIBFT		=	libft_ex
LIBFT_A		=	$(LIBFT)/libft_ex.a

#			RULES

all				:	$(NAME)

$(NAME)			:	$(LIBFT_A) $(OBJ_DIR) $(OBJ)
				$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft_ex -o $(NAME)

$(LIBFT_A)		:
				$(MAKE) -C $(LIBFT)

$(OBJ_DIR)		:
				mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o	: 	%.c push_swap.h
				$(CC) $(CFLAGS) -c $< -o $@

clean			:
				$(RM) -rf $(OBJ_DIR)
				$(MAKE) clean -s -C $(LIBFT)

fclean			:	clean
				$(RM) -f $(NAME)
				$(MAKE) fclean -s -C $(LIBFT)

re				:	fclean all