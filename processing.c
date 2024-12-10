/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:38:51 by ygille            #+#    #+#             */
/*   Updated: 2024/12/10 13:21:15 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_process(t_slist *list)
{
	if (list->stack_a->size == 2)
		inst_decoder(SA, list);
	else if (list->stack_a->size == 3)
		process_small(list);
	else if (list->stack_a->size <= 5)
		process_mid(list);
	else if (list->stack_a->size <= 100)
		process_big(list);
	else
		process_rbig(list);
}

int	is_sorted(t_slist *list)
{
	int	i;

	i = 0;
	while (i <= list->stack_a->maxp)
	{
		if (list->stack_a->stack[i] != list->sorted[i])
			return (0);
		i++;
	}
	return (1);
}

void	r_or_rr(t_stack *stack, int to_find, t_slist *list)
{
	int	pos;

	pos = stack->minp;
	while (stack->stack[pos] != to_find)
		pos++;
	if (pos - stack->minp <= stack->maxp + 1 - pos)
	{
		while (stack->minp < pos)
		{
			inst_decoder(RA, list);
			pos--;
		}
	}
	else
	{
		while (pos < stack->size)
		{
			inst_decoder(RRA, list);
			pos++;
		}
	}
}
