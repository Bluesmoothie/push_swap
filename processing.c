/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:38:51 by ygille            #+#    #+#             */
/*   Updated: 2024/12/05 18:39:07 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	process(int *stack_a, int *stack_b, int *sorted, int max_pos)
// {
// 	int	minp_a;
// 	int	minp_b;

// 	minp_a = 0;
// 	minp_b = max_pos + 1;
// 	// if (basic_sort(stack_a, max_pos))
// 	// 	return ;
// 	while (minp_a < max_pos)
// 	{
// 		if (stack_a[minp_a] == sorted[max_pos - minp_a])
// 			pb(&stack_a[minp_a], &stack_b[minp_b - 1], &minp_a, &minp_b);
// 		else
// 			ra(stack_a, minp_a, max_pos);
// 		// if (basic_sort(&stack_a[minp_a], max_pos - minp_a))
// 		// 	break ;
// 	}
// 	while (minp_b <= max_pos)
// 		pa(&stack_a[minp_a - 1], &stack_b[minp_b], &minp_a, &minp_b);
// }

void	process(int *stack_a, int *stack_b, int *sorted, int max_pos)
{
	(void)stack_b;
	while (!is_sorted(stack_a, sorted, max_pos))
	{
		if (stack_a[0] < stack_a[1])
			rra(stack_a, 0, max_pos);
		else
			sa(stack_a, 0);
		// ft_printf("stack_a[0] = %d stack_a[1] = %d\n", stack_a[0], stack_a[1]);
	}
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

int	basic_sort(int *stack, int max_pos)
{
	int	i;
	int	r;
	int	rr;

	i = 0;
	while (i < max_pos)
	{
		if (stack[i] < stack[i + 1])
			i++;
		else
			break ;
	}
	i++;
	r = i;
	while (i < max_pos)
	{
		if (stack[i] < stack[i + 1])
			i++;
		else
			break ;
	}
	if (r == i || i != max_pos)
		return (0);
	rr = i - r + 1;
	ft_printf("r = %i rr = %d max_pos = %i i = %i\n", r, rr, max_pos, i);
	return (r_rr(stack, max_pos, r, rr));
}

int	r_rr(int *stack, int max_pos, int r, int rr)
{
	if (r > rr)
	{
		while (rr--)
			rra(stack, 0, max_pos);
	}
	else
	{
		while (r--)
			ra(stack, 0, max_pos);
	}
	return (1);
}
