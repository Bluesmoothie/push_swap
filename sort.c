/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:59:05 by ygille            #+#    #+#             */
/*   Updated: 2024/12/10 13:37:12 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort(t_stack *stack, t_slist *list)
{
	int	*sorted;
	int	i;
	int	tmp;

	sorted = dup_stack(stack->stack, stack->size, list);
	i = 0;
	while (i < stack->maxp)
	{
		if (sorted[i] > sorted[i + 1])
		{
			tmp = sorted[i];
			sorted[i] = sorted[i + 1];
			sorted[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return (sorted);
}

int	*dup_stack(int *stack, int size, t_slist *list)
{
	int	*dup;
	int	i;

	dup = malloc(sizeof(int) * size);
	if (!dup)
		error(list, 1);
	i = 0;
	while (i < size)
	{
		dup[i] = stack[i];
		i++;
	}
	return (dup);
}

void	sort_chunk(t_slist *list, int chunk_size)
{
	int	i;
	int	tmp;

	i = 0;
	list->sorted_chunk = dup_stack(list->chunck_nums, chunk_size, list);
	while (i < chunk_size)
	{
		if (list->sorted_chunk[i] < list->sorted_chunk[i + 1])
		{
			tmp = list->sorted_chunk[i];
			list->sorted_chunk[i] = list->sorted_chunk[i + 1];
			list->sorted_chunk[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}
