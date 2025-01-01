/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:47:43 by ygille            #+#    #+#             */
/*   Updated: 2025/01/01 14:06:59 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Print the state of the stacks
*/
void	print_state(t_slist *list)
{
	int		i;
	char	*a;
	char	*b;

	i = 0;
	ft_printf("a    b    s\n\n");
	while (i <= list->stack_a->maxp)
	{
		if (i >= list->stack_a->minp)
			a = ft_itoa(list->stack_a->stack[i]);
		else
			a = "X";
		if (i >= list->stack_b->minp)
			b = ft_itoa(list->stack_b->stack[i]);
		else
			b = "X";
		ft_printf("%s    %s    %d\n", a, b, list->sorted[i]);
		i++;
	}
	ft_printf("\n");
}

/*
** Print a chunk
*/
void	print_chunk(int *chunk, int size)
{
	int	i;

	i = 0;
	ft_printf("chunk = \n");
	while (i < size)
	{
		ft_printf("%d\n", chunk[i]);
		i++;
	}
}
