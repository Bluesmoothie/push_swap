/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:23:44 by ygille            #+#    #+#             */
/*   Updated: 2024/12/09 14:19:33 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_mov(t_slist *list)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		pos;

	stack_a = list->stack_a;
	stack_b = list->stack_b;
	if (stack_b->stack[stack_b->minp] == list->sorted[list->stack_a->maxp])
	{
		r_or_rr(stack_a, list->sorted[0], list);
		inst_decoder(PA, list);
	}
	else
	{
		pos = 0;
		while (stack_b->stack[stack_b->minp] != list->sorted[pos])
			pos++;
		pos++;
		if (list->sorted[pos] == stack_b->stack[stack_b->maxp])
			pos++;
		if (pos > stack_b->maxp)
			pos = 0;
		r_or_rr(stack_a, list->sorted[pos], list);
		inst_decoder(PA, list);
	}
}

void	calc_chunck(t_slist	*list, int chunks)
{
	int		total_width;

	total_width = list->stack_a->maxval - list->stack_a->minval;
	list->chunck_width = total_width / chunks;
}

void	chunk_move(t_slist *list, int chunk)
{
	int	start;
	int	end;
	int	r;
	int	rr;

	start = list->chunck_width * (chunk - 1) + stack_a->minval;
	end = list->chunck_width * chunk + stack_a->minval;
	while (start <= end)
	{
		r = -1;
		rr = -1;
		while (
		start++;
	}
}
