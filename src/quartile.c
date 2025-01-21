/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:53:32 by ygille            #+#    #+#             */
/*   Updated: 2025/01/21 19:55:18 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Calculate the size of the quartiles
*/
void	calc_q_size(t_slist *list)
{
	list->q_size = list->stack_a->size / 4;
	list->last_q_size = list->stack_a->size - list->q_size * 3;
	list->q_borders[0][0] = 0;
	list->q_borders[0][1] = list->q_size - 1;
	list->q_borders[1][0] = list->q_size;
	list->q_borders[1][1] = list->q_size * 2 - 1;
	list->q_borders[2][0] = list->q_size * 2;
	list->q_borders[2][1] = list->q_size * 3 - 1;
	list->q_borders[3][0] = list->q_size * 3;
	list->q_borders[3][1] = list->q_size * 3 + list->last_q_size - 1;
}

/*
** Move the numbers from the outer quartiles to the stack_b
*/
void	move_outer(t_slist *list)
{
	int		i;
	t_stack	*stack;

	i = 0;
	stack = list->stack_b;
	while (i < list->q_size + list->last_q_size - 3)
	{
		inst_decoder(PB, list);
		if (stack->stack[stack->minp] < list->q_borders[2][0])
			inst_decoder(RB, list);
		i++;
	}
}

/*
** Move the numbers from the inner quartiles to the stack_b
*/
void	move_inner(t_slist *list)
{
	int		i;
	t_stack	*stack;

	i = 0;
	stack = list->stack_a;
	while (i < list->q_size * 2)
	{
		if (stack->stack[stack->minp] >= list->q_borders[1][0]
			&& stack->stack[stack->minp] <= list->q_borders[1][1])
		{
			inst_decoder(PB, list);
			inst_decoder(RB, list);
		}
		else if (stack->stack[stack->minp] >= list->q_borders[2][0]
			&& stack->stack[stack->minp] <= list->q_borders[2][1])
			inst_decoder(PB, list);
		else
		{
			inst_decoder(RA, list);
			i--;
		}
		i++;
	}
}

/*
** Sort the quartiles to the stack_a
*/
void	sort_quartile(t_slist *list)
{
	t_insert	to_insert;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (list->stack_a->minp != 0)
	{
		to_insert = calc_less_op(list, j);
		if (to_insert.cost == -1)
		{
			i = 0;
			j++;
		}
		else
		{
			r_or_rr(list->stack_b, to_insert.value, list, XB);
			r_or_rr(list->stack_a, to_insert.spot, list, XA);
			inst_decoder(PA, list);
			i++;
		}
	}
	r_or_rr(list->stack_a, 0, list, XA);
}
