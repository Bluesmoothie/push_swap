/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:28:53 by ygille            #+#    #+#             */
/*   Updated: 2025/01/17 19:35:30 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Find the toppest number from to_find in the stack
*/
int	find_top(t_stack *stack, int *to_find, int chunk_size)
{
	int	i;

	i = stack->minp;
	while (i < stack->size)
	{
		if (intchr(to_find, chunk_size, stack->stack[i]))
			return (i);
		i++;
	}
	return (0);
}

/*
** Find the bottomest number from to_find in the stack
*/
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

/*
** Generate the numbers of the chunk that are in the stack
*/
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

/*
** Calculate the width of the chunk
*/
void	calc_chunck(t_slist	*list, int chunks)
{
	int		total_width;

	total_width = list->stack_a->maxval - list->stack_a->minval;
	list->chunck_width = total_width / chunks;
}

/*
** Rotate or reverse rotate the stack to put the chunk at the top
*/
void	r_or_rr_chunk(t_slist *list, int chunk_size)
{
	int	bottom;
	int	pos;

	bottom = 0;
	pos = list->stack_a->minp;
	while (list->sorted[bottom] != list->sorted_chunk[chunk_size - 1])
		bottom++;
	bottom--;
	while (list->stack_a->stack[pos] != list->sorted[bottom])
		pos++;
	if (pos - list->stack_a->minp <= list->stack_a->maxp + 1 - pos)
	{
		while (list->sorted[bottom]
			!= list->stack_a->stack[list->stack_a->maxp])
			inst_decoder(RA, list);
	}
	else
	{
		while (list->sorted[bottom]
			!= list->stack_a->stack[list->stack_a->maxp])
			inst_decoder(RRA, list);
	}
}
