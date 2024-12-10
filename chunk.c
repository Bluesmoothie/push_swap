/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:20:05 by ygille            #+#    #+#             */
/*   Updated: 2024/12/10 13:52:28 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			r_or_rr(list->stack_a, list->stack_a->stack[top], list);
		else
			r_or_rr(list->stack_a, list->stack_a->stack[bottom], list);
		inst_decoder(PB, list);
	}
}

void	process_chunk(t_slist *list, int chunk)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	i = 0;
	stack_a = list->stack_a;
	stack_b = list->stack_b;
	while (stack_b->minp < stack_b->maxp)
	{
		if (stack_b->stack[stack_b->minp] == list->sorted_chunk[stack_b->minp])
			inst_decoder(PA, list);
		else
			r_or_rr(stack_b, list->sorted_chunk[stack_b->minp], list);
		i++;
	}
	if (chunk > 1)
		r_or_rr_chunk(list);
	while (stack_a->minp >= 0)
		inst_decoder(PB, list);
}
