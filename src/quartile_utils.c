/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartile_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:39:55 by ygille            #+#    #+#             */
/*   Updated: 2025/01/21 19:37:27 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Calculate the best move to insert a number from the stack_b
*/
t_insert	calc_less_op(t_slist *list, int quartile)
{
	int			i;
	t_insert	insert;
	t_insert	tmp;

	i = list->stack_b->minp;
	insert.cost = -1;
	while (i <= list->stack_b->maxp)
	{
		if (list->stack_b->stack[i] >= list->q_borders[quartile][0]
			&& list->stack_b->stack[i] <= list->q_borders[quartile][1])
		{
			tmp.value = list->stack_b->stack[i];
			tmp.spot = find_spot(list->stack_a, tmp.value);
			tmp.cost = best_move(list->stack_a, tmp.spot)
				+ best_move(list->stack_b, tmp.value);
			if (insert.cost == -1)
				insert = tmp;
			else if (tmp.cost < insert.cost)
				insert = tmp;
		}
		i++;
	}
	return (insert);
}

/*
** Find the best spot to insert a number from the stack_b
*/
int	find_spot(t_stack *stack, int value)
{
	int	i;
	int	j;

	i = value + 1;
	while (i <= stack->maxp)
	{
		j = stack->minp;
		while (j <= stack->maxp)
		{
			if (stack->stack[j] == i)
				return (stack->stack[j]);
			j++;
		}
		i++;
	}
	return (find_max_on_bot(stack));
}

/*
** Find what value need to be on the top of the stack
** to get the max value at the bottom
*/
int	find_max_on_bot(t_stack *stack)
{
	int	i;
	int	maxi;

	i = stack->minp;
	maxi = i;
	while (i <= stack->maxp)
	{
		if (stack->stack[i] > stack->stack[maxi])
			maxi = i;
		i++;
	}
	if (maxi == stack->maxp)
		return (stack->stack[stack->minp]);
	else
		return (stack->stack[maxi + 1]);
}

/*
** Calculate the cost of the best move to insert a number
*/
int	best_move(t_stack *stack, int value)
{
	int	cost;
	int	pos;

	pos = stack->minp;
	while (stack->stack[pos] != value)
		pos++;
	if (pos - stack->minp < stack->maxp - pos)
		cost = pos - stack->minp;
	else
		cost = stack->maxp - pos;
	return (cost);
}
