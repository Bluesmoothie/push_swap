/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:38:51 by ygille            #+#    #+#             */
/*   Updated: 2024/12/05 18:55:38 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process(int *stack_a, int *stack_b, int *sorted, int max_pos)
{
	int	minp_a;
	int	minp_b;

	minp_a = 0;
	minp_b = max_pos + 1;
	while (minp_a < max_pos)
	{
		if (stack_a[minp_a] == sorted[max_pos - minp_a])
			pb(&stack_a[minp_a], &stack_b[minp_b - 1], &minp_a, &minp_b);
		else
			r_rr(stack_a, minp_a, max_pos, sorted[max_pos - minp_a]);
	}
	while (minp_b <= max_pos)
		pa(&stack_a[minp_a - 1], &stack_b[minp_b], &minp_a, &minp_b);
}

int	is_sorted(int *stack, int *sorted, int max_pos)
{
	int	i;

	i = 0;
	while (i <= max_pos)
	{
		if (stack[i] != sorted[max_pos - i])
			return (0);
		i++;
	}
	return (1);
}

void	r_rr(int *stack_a, int minp_a, int max_pos, int to_find)
{
	int	pos;

	pos = minp_a;
	while (stack_a[pos] != to_find)
		pos++;
	if (pos - minp_a <= max_pos - pos)
	{
		while (minp_a <= pos)
		{
			ra(stack_a, minp_a, max_pos);
			pos--;
		}
	}
	else
	{
		while (pos <= max_pos)
		{
			rra(stack_a, minp_a, max_pos);
			pos++;
		}
	}
}
