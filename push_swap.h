/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:17:10 by ygille            #+#    #+#             */
/*   Updated: 2025/01/14 22:14:44 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <ft_printf.h>
# include <limits.h>

typedef struct s_stack
{
	int	*stack;
	int	size;
	int	minp;
	int	maxp;
	int	maxval;
	int	minval;
}	t_stack;

typedef struct s_slist
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*sorted;
	int		chunck_width;
	int		*chunck_nums;
	int		*sorted_chunk;
}	t_slist;

enum e_instructions
{
	XA = 1,
	XB = 2,
	XR = 3,
	SX = 10,
	SA = 11,
	SB = 12,
	SS = 13,
	PX = 20,
	PA = 21,
	PB = 22,
	RX = 30,
	RA = 31,
	RB = 32,
	RR = 33,
	RRX = 40,
	RRA = 41,
	RRB = 42,
	RRR = 43
};

//push_swap.c
void	error(t_slist *list, int error);
t_slist	*list_init(void);

//free.c
void	free_stack(t_stack *stack);
void	free_chunk(t_slist *list);

//parse.c
t_stack	*parse_args(int argc, char **argv, t_slist *list);
int		verify_arg(char *arg, t_stack *stack);
t_stack	*alt_parse_args(int	*argc, char *arg, t_slist *list);
t_stack	*fill_stack(char **split, int size, t_slist *list);
t_stack	*init_stack(int size, t_slist *list);

//ft_atol.c
long	ft_atol(const char *nptr);

//sort.c
int		*sort(t_stack *stack, t_slist *list);
int		*dup_stack(int *stack, int size, t_slist *list);
void	sort_chunk(t_slist *list, int chunk_size);

//processing.c
void	choose_process(t_slist *list);
int		is_sorted(t_slist *list);
void	r_or_rr(t_stack *stack, int to_find, t_slist *list, int stack_mask);

//processor.c
void	process_small(t_slist *list);
void	process_mid(t_slist *list);
void	process_big(t_slist *list);
void	process_rbig(t_slist *list);
void	process_wchunk(t_slist *list, int chunk_num);

//processor_utils.c
void	calc_mov(t_slist *list);
int		intchr(int *tab, int size, int to_find);

//chunk.c
void	chunk_move(t_slist *list, int chunk_size);
void	process_chunk(t_slist *list, int chunk, int chunk_size);

//chunk_utils.c
int		find_top(t_stack *stack, int *to_find, int chunk_size);
int		find_bottom(t_stack *stack, int *to_find, int chunk_size);
int		chunk_nums_gen(t_slist *list, int chunk);
void	calc_chunck(t_slist	*list, int chunks);
void	r_or_rr_chunk(t_slist *list, int chunk_size);

//chunk_utils2.c
int		last_chunk_nums_gen(t_slist *list, int chunk);

//instructions_decoder.c
void	inst_decoder(int inst, t_slist *list);
void	inst_swap_both(t_slist *list);
void	inst_rotate_both(t_slist *list);
void	inst_rev_rotate_both(t_slist *list);
void	inst_print(int inst);

//instructions.c
void	inst_swap(t_stack *stack);
void	inst_push(t_stack *src, t_stack *dst);
void	inst_rotate(t_stack *stack);
void	inst_rev_rotate(t_stack *stack);

//tests.c
void	print_state(t_slist *list);
void	print_chunk(int *chunk, int size);

#endif