/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:17:10 by ygille            #+#    #+#             */
/*   Updated: 2024/12/05 17:06:49 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <ft_printf.h>
# include <limits.h>

//push_swap.c
void	error(void);

//parse.c
int		*parse_args(int argc, char **argv);
int		verify_arg(char *arg, int *stack, int size);
int		*alt_parse_args(int	*argc, char *arg);
int		*fill_stack(char **split, int size);

//ft_atol.c
long	ft_atol(const char *nptr);

//sort.c
int		*sort(int *stack, int size);
int		*dup_stack(int *stack, int size);

//processing.c
void	process(int *stack_a, int *stack_b, int *sorted, int max_pos);
int		is_sorted(int *stack, int *sorted, int max_pos);
int		basic_sort(int *stack, int max_pos);
int		r_rr(int *stack, int max_pos, int r, int rr);

//instructions.c
void	pa(int *a, int *b, int *minp_a, int *minp_b);
void	pb(int *a, int *b, int *minp_a, int *minp_b);
void	ra(int *stack_a, int minp_a, int max_pos);
void	rra(int *stack_a, int minp_a, int max_pos);

#endif