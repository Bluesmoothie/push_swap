/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:38:51 by ygille            #+#    #+#             */
/*   Updated: 2024/12/05 12:46:29 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process(int *stack_a, int *stack_b, int *sorted, int max_pos)
{
	int	minp_a;
	int	minp_b;

	minp_a = 0;
	minp_b = max_pos + 1;
	while (minp_a <= max_pos)
	{
		if (stack_a[minp_a] == sorted[max_pos - minp_a])
			pb(&stack_a[minp_a], &stack_b[minp_b - 1], &minp_a, &minp_b);
		else
			ra(stack_a, minp_a, max_pos);
	}
	while (minp_b <= max_pos)
		pa(&stack_a[minp_a - 1], &stack_b[minp_b], &minp_a, &minp_b);
}
