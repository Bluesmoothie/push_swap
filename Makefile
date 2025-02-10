.PHONY	:	clean fclean re all bonus FORCE norme

NAME			=   push_swap

#			GCC

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -MMD -MP $(INCLUDE)
INCLUDE 		=	-I include -I $(LIBFT)/include

#			COMMON

BUILD_DIR		=	.build/
BONUS_BUILD_DIR	=	.build_bonus/
SRC_DIR			=	src/
BONUS_SRC_DIR	=	src_bonus/

#			PUSH_SWAP

SRC_FILES		=	free							\
					ft_atol							\
					instructions_decoder			\
					instructions					\
					parse							\
					processing						\
					processor						\
					quartile						\
					quartile_utils					\
					replace							\
					push_swap						\
					sort							\
					tests							\

BONUS_SRC_FILES	=	checker_bonus					\
					free_bonus						\
					ft_atol_bonus					\
					instructions_bonus				\
					instructions_decoder_bonus		\
					operations_bonus				\
					operations_decode_bonus			\
					parse_bonus						\
					processing_bonus				\
					sort_bonus						\

SRC 			= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 			= 	$(addprefix $(BUILD_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS			=	$(addprefix $(BUILD_DIR), $(addsuffix .d, $(SRC_FILES)))
BONUS_SRC 		= 	$(addprefix $(BONUS_SRC_DIR), $(addsuffix .c, $(BONUS_SRC_FILES)))
BONUS_OBJ 		= 	$(addprefix $(BONUS_BUILD_DIR), $(addsuffix .o, $(BONUS_SRC_FILES)))
BONUS_DEPS		=	$(addprefix $(BONUS_BUILD_DIR), $(addsuffix .d, $(BONUS_SRC_FILES)))


#			LIBFT

LIBFT		=	libft
LIBFT_A		=	$(LIBFT)/libft_ex.a

#			RULES

all						:	$(NAME)

$(NAME)					:	$(LIBFT_A) $(BUILD_DIR) $(OBJ)
						$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft_ex -o $(NAME)

bonus					:	checker

checker					:	$(LIBFT_A) $(BONUS_BUILD_DIR) $(BONUS_OBJ)
						$(CC) $(CFLAGS) $(BONUS_OBJ) -L$(LIBFT) -lft_ex -o checker

$(LIBFT_A)				:	FORCE
						$(MAKE) -C $(LIBFT)

FORCE					:

$(BUILD_DIR)			:
						mkdir -p $(BUILD_DIR)

$(BUILD_DIR)%.o			: 	$(SRC_DIR)%.c
						$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

$(BONUS_BUILD_DIR)		:
						mkdir -p $(BONUS_BUILD_DIR)

$(BONUS_BUILD_DIR)%.o	: 	$(BONUS_SRC_DIR)%.c
						$(CC) $(CFLAGS) -c $< -o $@

-include $(BONUS_DEPS)

norme					:
						norminette $(SRC_DIR) $(BONUS_SRC_DIR) include

clean					:
						rm -rf $(BUILD_DIR) $(BONUS_BUILD_DIR)
						$(MAKE) clean -C $(LIBFT)

fclean					:	clean
						rm -f $(NAME) checker
						$(MAKE) fclean -C $(LIBFT)

re						:	fclean all