/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartile_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:39:55 by ygille            #+#    #+#             */
/*   Updated: 2025/01/20 19:39:29 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_nearest2(t_slist *list, int *upborders, int *downborders)
{
	int	up;
	int	down;

	up = find_nearest(list, upborders);
	down = find_nearest(list, downborders);
	if (up_is_nearest(list, up, down))
		return (-up);
	return (down);
}

int	find_nearest(t_slist *list, int *borders)
{
	int	i;
	int	j;

	i = list->stack_a->minp;
	j = list->stack_a->maxp;
	while (i < list->stack_a->maxp / 2)
	{
		if (list->stack_a->stack[i] >= borders[0]
			&& list->stack_a->stack[i] <= borders[1])
			break ;
		i++;
	}
	while (j >=	list->stack_a->maxp / 2)
	{
		if (list->stack_a->stack[j] >= borders[0]
			&& list->stack_a->stack[j] <= borders[1])
			break ;
		j--;
	}
	if (i - list->stack_a->minp < list->stack_a->maxp - j
		&& list->stack_a->stack[i] >= borders[0] && list->stack_a->stack[i] <= borders[1])
		return (i);
	return (j);
}

int	up_is_nearest(t_slist *list, int up, int down)
{
	int	uptotop;
	int	uptobot;
	int	downtotop;
	int	downtobot;

	uptotop = up - list->stack_a->minp;
	uptobot = list->stack_a->maxp - up;
	downtotop = down - list->stack_a->minp;
	downtobot = list->stack_a->maxp - down;
	if ((uptotop < downtotop && uptotop < downtobot) || (uptobot < downtotop && uptobot < downtobot))
		return (1);
	return (0);
}
