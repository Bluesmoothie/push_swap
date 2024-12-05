/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:40:48 by ygille            #+#    #+#             */
/*   Updated: 2024/12/05 18:33:57 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(int *a, int *b, int *minp_a, int *minp_b)
{
	*a = *b;
	*b = 0;
	(*minp_a)--;
	(*minp_b)++;
	ft_printf("pa\n");
}

void	pb(int *a, int *b, int *minp_a, int *minp_b)
{
	*b = *a;
	*a = 0;
	(*minp_a)++;
	(*minp_b)--;
	ft_printf("pb\n");
}

void	ra(int *stack_a, int minp_a, int max_pos)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack_a[minp_a];
	while (i < max_pos - minp_a)
	{
		stack_a[minp_a + i] = stack_a[minp_a + i + 1];
		i++;
	}
	stack_a[max_pos] = tmp;
	ft_printf("ra\n");
}

void	rra(int *stack_a, int minp_a, int max_pos)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack_a[max_pos];
	while (i < max_pos - minp_a)
	{
		stack_a[max_pos - i] = stack_a[max_pos - i - 1];
		i++;
	}
	stack_a[minp_a] = tmp;
	ft_printf("rra\n");
}

void	sa(int *stack_a, int minp_a)
{
	int	tmp;

	tmp = stack_a[minp_a];
	stack_a[minp_a] = stack_a[minp_a + 1];
	stack_a[minp_a + 1] = tmp;
	ft_printf("sa\n");
}
