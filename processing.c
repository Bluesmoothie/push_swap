/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:38:51 by ygille            #+#    #+#             */
/*   Updated: 2024/12/06 13:55:03 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process(t_slist *list)
{
	int	i;

	i = 0;
	while (!is_sorted(list))
	{
		if (list->stack_a->stack[list->stack_a->minp] == list->sorted[list->stack_a->maxp - i])
		{
			inst_push(list->stack_a, list->stack_b);
			ft_printf("pb\n");
		}
		else
		{
			r_or_rr(list->stack_a, list->sorted[list->stack_a->maxp - i]);
			inst_push(list->stack_a, list->stack_b);
			ft_printf("pb\n");
		}
		i++;
	}
	while (list->stack_b->size > 0)
	{
		inst_push(list->stack_b, list->stack_a);
		ft_printf("pa\n");
	}
}

int	is_sorted(t_slist *list)
{
	int	i;

	i = 0;
	while (i <= list->stack_a->maxp)
	{
		if (list->stack_a->stack[i] != list->sorted[list->stack_a->maxp - i])
			return (0);
		i++;
	}
	return (1);
}

void	r_or_rr(t_stack *stack, int to_find)
{
	int	pos;

	pos = stack->minp;
	while (stack->stack[pos] != to_find)
		pos++;
	if (pos - stack->minp <= stack->maxp - pos)
	{
		while (stack->minp <= pos)
		{
			inst_rotate(stack);
			pos--;
		}
	}
	else
	{
		while (pos <= stack->maxp)
		{
			inst_rev_rotate(stack);
			pos++;
		}
	}
}
