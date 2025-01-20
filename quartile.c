/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:53:32 by ygille            #+#    #+#             */
/*   Updated: 2025/01/20 19:31:49 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	move_outer(t_slist *list)
{
	int	pos;
	int	i;

	i = 0;
	while (i < list->q_size + list->last_q_size)
	{
		pos = find_nearest2(list, list->q_borders[0], list->q_borders[3]);
		if (pos < 0)
		{
			pos *= -1;
			r_or_rr(list->stack_a, list->stack_a->stack[pos], list, XA);
			inst_decoder(PB, list);
			inst_decoder(RB, list);
		}
		else
		{
			r_or_rr(list->stack_a, list->stack_a->stack[pos], list, XA);
			inst_decoder(PB, list);
		}
		i++;
	}
}

void	move_inner(t_slist *list)
{
	int	pos;
	int	i;

	i = 0;
	while (i < list->q_size * 2)
	{
		pos = find_nearest2(list, list->q_borders[1], list->q_borders[2]);
		if (pos < 0)
		{
			pos *= -1;
			r_or_rr(list->stack_a, list->stack_a->stack[pos], list, XA);
			inst_decoder(PB, list);
			inst_decoder(RB, list);
		}
		else
		{
			r_or_rr(list->stack_a, list->stack_a->stack[pos], list, XA);
			inst_decoder(PB, list);
		}
		i++;
	}
}

void	sort_outer(t_slist *list)
{
	(void)list;
}

void	sort_inner(t_slist *list)
{
	(void)list;
}
