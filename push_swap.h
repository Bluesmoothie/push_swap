/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:17:10 by ygille            #+#    #+#             */
/*   Updated: 2024/12/06 18:03:34 by ygille           ###   ########.fr       */
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
}	t_slist;

enum e_instructions
{
	SA = 11,
	SB = 12,
	SS = 13,
	PA = 21,
	PB = 22,
	RA = 31,
	RB = 32,
	RR = 33,
	RRA = 41,
	RRB = 42,
	RRR = 43
};

//push_swap.c
void	error(t_slist *list, int error);
t_slist	*list_init(void);
// void	print_state(t_slist *list);

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

//processing.c
void	choose_process(t_slist *list);
int		is_sorted(t_slist *list);
void	r_or_rr(t_stack *stack, int to_find, t_slist *list);
// void	process_basic(t_slist *list);

//processor.c
void	process_small(t_slist *list);
void	process_mid(t_slist *list);
void	process_big(t_slist *list);
void	process_rbig(t_slist *list);

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

#endif