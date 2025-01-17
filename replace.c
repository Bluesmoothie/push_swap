/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:47:08 by ygille            #+#    #+#             */
/*   Updated: 2025/01/17 20:06:47 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	replace_numbers(t_slist *list)
{
	int	i;
	int	last;
	int	smallest;

	i = 0;
	last = INT_MIN;
	// print_state(list);
	// ft_printf("stack size = %d\n", list->stack_a->size);
	while (i < list->stack_a->size)
	{
		smallest = find_smallest(list->stack_a, last);
		// ft_printf("smallest = %d\n", smallest);
		last = list->stack_a->stack[smallest];
		list->stack_a->stack[smallest] = i;
		i++;
	}
}

int	find_smallest(t_stack *stack, int last)
{
	int i;
	int	smallest;

	i = 0;
	smallest = -1;
	while (i < stack->size)
	{
		if (stack->stack[i] > last)
			if (smallest == -1 || stack->stack[i] < stack->stack[smallest])
			smallest = i;
		i++;
	}
	return (smallest);
}
