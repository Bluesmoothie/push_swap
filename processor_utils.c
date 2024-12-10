/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:23:44 by ygille            #+#    #+#             */
/*   Updated: 2024/12/10 16:13:22 by ygille           ###   ########.fr       */
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
		r_or_rr(stack_a, list->sorted[0], list, XA);
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
		r_or_rr(stack_a, list->sorted[pos], list, XA);
		inst_decoder(PA, list);
	}
}

int	intchr(int *tab, int size, int to_find)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == to_find)
			return (1);
		i++;
	}
	return (0);
}
