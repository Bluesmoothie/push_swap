.PHONY	:	clean fclean re all bonus

NAME		=   push_swap

#			GCC

CC			=	clang
CFLAGS		=	-g -Wall -Wextra -Werror $(INCLUDE)
INCLUDE 	=	-I include -I $(LIBFT)/includes

#			PUSH_SWAP

SRC_FILES	=	free					\
				ft_atol					\
				instructions_decoder	\
				instructions			\
				parse					\
				processing				\
				processor				\
				processor_utils			\
				quartile				\
				quartile_utils			\
				replace					\
				push_swap				\
				sort					\
				tests					\

BONUS_SRC_FILES	=	checker_bonus		\

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
BONUS_SRC 	= 	$(addprefix $(BONUS_SRC_DIR), $(addsuffix .c, $(BONUS_SRC_FILES)))
BONUS_OBJ 	= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(BONUS_SRC_FILES)))

#			COMMON

OBJ_DIR		=	obj/
SRC_DIR		=	src/
BONUS_SRC_DIR		=	src_bonus/

#			LIBFT

LIBFT		=	libft
LIBFT_A		=	$(LIBFT)/libft_ex.a

#			RULES

all				:	$(NAME)

bonus			:	checker

checker			:	$(LIBFT_A) $(OBJ_DIR) $(OBJ) $(BONUS_OBJ)
				$(CC) $(CFLAGS) -D BONUS_MODE=1 $(OBJ) $(BONUS_OBJ) -L$(LIBFT) -lft_ex -o checker

$(NAME)			:	$(LIBFT_A) $(OBJ_DIR) $(OBJ)
				$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft_ex -o $(NAME)

$(LIBFT_A)		:
				$(MAKE) -C $(LIBFT)

$(OBJ_DIR)		:
				mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o	: 	$(SRC_DIR)%.c include/push_swap.h
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o	: 	$(BONUS_SRC_DIR)%.c include/push_swap.h include/push_swap_bonus.h
				$(CC) $(CFLAGS) -c $< -o $@

clean			:
				$(RM) -rf $(OBJ_DIR)
				$(MAKE) clean -s -C $(LIBFT)

fclean			:	clean
				$(RM) -f $(NAME)
				$(MAKE) fclean -s -C $(LIBFT)

re				:	fclean all