/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:28:53 by ygille            #+#    #+#             */
/*   Updated: 2024/12/10 16:24:21 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_top(t_stack *stack, int *to_find, int chunk_size)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (intchr(to_find, chunk_size, stack->stack[i]))
			return (i);
		i++;
	}
	return (0);
}

int	find_bottom(t_stack *stack, int *to_find, int chunk_size)
{
	int	i;

	i = stack->maxp;
	while (i >= stack->minp)
	{
		if (intchr(to_find, chunk_size, stack->stack[i]))
			return (i);
		i--;
	}
	return (0);
}

int	chunk_nums_gen(t_slist *list, int chunk)
{
	int	max;
	int	start;
	int	i;

	list->chunck_nums = malloc(sizeof(int) * list->chunck_width);
	if (!list->chunck_nums)
		error(list, 1);
	i = 0;
	start = list->stack_a->minval + (list->chunck_width * (chunk - 1));
	max = list->stack_a->minval + (list->chunck_width * chunk);
	while (start < max)
	{
		if (intchr(list->stack_a->stack, list->stack_a->size, start))
		{
			list->chunck_nums[i] = start;
			i++;
		}
		start++;
	}
	return (i);
}

void	calc_chunck(t_slist	*list, int chunks)
{
	int		total_width;

	total_width = list->stack_a->maxval - list->stack_a->minval;
	list->chunck_width = total_width / chunks;
}

void	r_or_rr_chunk(t_slist *list)
{
	int		gap_size;
	int		i;
	int		tmp;
	int		pos;
	t_stack	*stack_a;

	stack_a = list->stack_a;
	i = stack_a->minp;
	gap_size = INT_MAX;
	while (i < stack_a->size)
	{
		tmp = stack_a->stack[i] - list->sorted_chunk[0];
		if (tmp < gap_size && tmp > 0)
		{
			gap_size = tmp;
			pos = i;
		}
		i++;
	}
	r_or_rr(stack_a, stack_a->stack[pos], list, XA);
}
