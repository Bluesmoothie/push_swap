/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:20:05 by ygille            #+#    #+#             */
/*   Updated: 2025/01/17 19:37:50 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Move the chunk to the stack_b
*/
void	chunk_move(t_slist *list, int chunk_size)
{
	int	top;
	int	bottom;
	int	i;

	i = 0;
	while (i < chunk_size)
	{
		top = find_top(list->stack_a, list->chunck_nums, chunk_size);
		bottom = find_bottom(list->stack_a, list->chunck_nums, chunk_size);
		if (top - list->stack_a->minp <= list->stack_a->maxp - bottom)
			r_or_rr(list->stack_a, list->stack_a->stack[top], list, XA);
		else
			r_or_rr(list->stack_a, list->stack_a->stack[bottom], list, XA);
		inst_decoder(PB, list);
		i++;
	}
}

/*
** Sort the chunk
*/
void	process_chunk(t_slist *list, int chunk, int chunk_size)
{
	t_stack	*stack_b;
	int		i;
	int		min;
	int		max;

	i = 0;
	stack_b = list->stack_b;
	if (chunk > 1)
		r_or_rr_chunk(list, chunk_size);
	// print_chunk(list->chunck_nums, chunk_size);
	while (i < chunk_size)
	{
		min = find_min(stack_b, list->chunck_nums, chunk_size);
		max = find_max(stack_b, list->chunck_nums, chunk_size);
		// ft_printf("sort %i\n", i);
		// ft_printf("min = %d, max = %d\n", min, max);
		// print_state(list);
		if (min - list->stack_b->minp >= list->stack_b->maxp - max)
		{
			r_or_rr(stack_b, stack_b->stack[max], list, XB);
			inst_decoder(PA, list);
		}
		else
		{
			r_or_rr(stack_b, stack_b->stack[min], list, XB);
			inst_decoder(PA, list);
			inst_decoder(RA, list);
		}
		// print_state(list);
		i++;
	}
}
