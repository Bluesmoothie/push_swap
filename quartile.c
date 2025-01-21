/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:53:32 by ygille            #+#    #+#             */
/*   Updated: 2025/01/21 13:43:21 by ygille           ###   ########.fr       */
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
	t_elem	elem;
	int		i;

	ft_printf("outer\n");
	i = 0;
	while (i < list->q_size + list->last_q_size)
	{
		elem = find_nearest2(list, list->q_borders[0], list->q_borders[3]);
		r_or_rr(list->stack_a, list->stack_a->stack[elem.index], list, XA);
		inst_decoder(PB, list);
		if (elem.is_up)
			inst_decoder(RB, list);
		i++;
	}
}

void	move_inner(t_slist *list)
{
	t_elem	elem;
	int		i;

	ft_printf("inner\n");
	i = 0;
	while (i < list->q_size * 2)
	{
		elem = find_nearest2(list, list->q_borders[1], list->q_borders[2]);
		r_or_rr(list->stack_a, list->stack_a->stack[elem.index], list, XA);
		inst_decoder(PB, list);
		if (elem.is_up)
			inst_decoder(RB, list);
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
