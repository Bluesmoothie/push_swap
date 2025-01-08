/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:20:05 by ygille            #+#    #+#             */
/*   Updated: 2025/01/08 14:07:08 by ygille           ###   ########.fr       */
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
		ft_printf("top = %d, bottom = %d\n", top, bottom);
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

	i = 0;
	stack_b = list->stack_b;
	if (chunk > 1)
		r_or_rr_chunk(list, list->sorted_chunk[chunk_size - 1]);
	print_chunk(list->sorted_chunk, chunk_size);
	while (i < chunk_size)
	{
		if (stack_b->stack[stack_b->minp] == list->sorted_chunk[i])
		{
			inst_decoder(PA, list);
			i++;
		}
		else
			r_or_rr(stack_b, list->sorted_chunk[i], list, XB);
	}
}
