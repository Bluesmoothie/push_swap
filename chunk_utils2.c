/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:34:49 by ygille            #+#    #+#             */
/*   Updated: 2025/01/17 19:35:40 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	last_chunk_nums_gen(t_slist *list, int chunk)
{
	int	max;
	int	start;
	int	i;

	list->chunck_nums = malloc(sizeof(int) * list->chunck_width * 5);
	if (!list->chunck_nums)
		error(list, 1);
	start = list->stack_a->minval + (list->chunck_width * (chunk - 1));
	max = list->stack_a->maxval;
	i = 0;
	while (start < max)
	{
		if (intchr(list->stack_a->stack, list->stack_a->size, start))
		{
			list->chunck_nums[i] = start;
			i++;
		}
		start++;
	}
	return (i);
}

int	find_min(t_stack *stack, int *to_find, int chunk_size)
{
	int	i;
	int	min;

	i = 0;
	min = -1;
	while (i < chunk_size)
	{
		min = intschr(stack, to_find[i]);
		if (min >= 0)
			return (min);
		i++;
	}
	return (0);
}

int	find_max(t_stack *stack, int *to_find, int chunk_size)
{
	int	i;
	int	max;

	i = chunk_size - 1;
	while (i >= 0)
	{
		max = intschr(stack, to_find[i]);
		if (max >= 0)
			return (max);
		i--;
	}
	return (0);
}
