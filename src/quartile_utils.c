/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartile_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:39:55 by ygille            #+#    #+#             */
/*   Updated: 2025/01/21 14:58:21 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	find_nearest2(t_slist *list, int *upborders, int *downborders)
{
	t_elem	up;
	t_elem	down;
	int		*stack;

	stack = list->stack_a->stack;
	up.is_up = 1;
	down.is_up = 0;
	up.index = find_nearest(list, upborders);
	down.index = find_nearest(list, downborders);
	if (stack[up.index] >= upborders[0]
		&& stack[up.index] <= upborders[1]
		&& up.index >= list->stack_a->minp)
		up.found = 1;
	else
		up.found = 0;
	if (stack[down.index] >= downborders[0]
		&& stack[down.index] <= downborders[1]
		&& down.index >= list->stack_a->minp)
		down.found = 1;
	else
		down.found = 0;
	if ((up_is_nearest(list, up, down) && up.found) || !down.found)
		return (up);
	return (down);
}

int	find_nearest(t_slist *list, int *borders)
{
	int	i;
	int	j;

	i = list->stack_a->minp;
	j = list->stack_a->maxp;
	while (i <= list->stack_a->size / 2)
	{
		if (list->stack_a->stack[i] >= borders[0]
			&& list->stack_a->stack[i] <= borders[1])
			break ;
		i++;
	}
	while (j >=	list->stack_a->size / 2)
	{
		if (list->stack_a->stack[j] >= borders[0]
			&& list->stack_a->stack[j] <= borders[1])
			break ;
		j--;
	}
	if (i - list->stack_a->minp < list->stack_a->maxp - j
		&& list->stack_a->stack[i] >= borders[0]
		&& list->stack_a->stack[i] <= borders[1])
		return (i);
	return (j);
}

int	up_is_nearest(t_slist *list, t_elem up, t_elem down)
{
	int	uptotop;
	int	uptobot;
	int	downtotop;
	int	downtobot;

	uptotop = up.index - list->stack_a->minp;
	uptobot = list->stack_a->maxp - up.index;
	downtotop = down.index - list->stack_a->minp;
	downtobot = list->stack_a->maxp - down.index;
	if ((uptotop < downtotop && uptotop < downtobot)
		|| (uptobot < downtotop && uptobot < downtobot))
		return (1);
	return (0);
}

int	nearest_between(t_slist *list, int up, int down)
{
	int	i;
	int	j;

	i = list->stack_b->minp;
	j = list->stack_b->maxp;
	while (list->stack_b->stack[i] != up)
		i++;
	while (list->stack_b->stack[j] != down)
		j--;
	if (i - list->stack_b->minp <= list->stack_b->maxp - j)
		return(1);
	return (0);
}
