/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:47:43 by ygille            #+#    #+#             */
/*   Updated: 2025/01/21 19:38:54 by ygille           ###   ########.fr       */
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
	ft_printf("      a    b    s\n\n");
	while (i <= list->stack_a->maxp)
	{
		if (i >= list->stack_a->minp)
			a = ft_itoa(list->stack_a->stack[i]);
		else
			a = " ";
		if (i >= list->stack_b->minp)
			b = ft_itoa(list->stack_b->stack[i]);
		else
			b = " ";
		ft_printf("[%d]   %s    %s    %d\n\n", i, a, b, list->sorted[i]);
		i++;
	}
	ft_printf("\n");
}

/*
** Print the quartile borders and infos
*/
void	print_quartile_info(t_slist *list)
{
	ft_printf("q_size: %d\n", list->q_size);
	ft_printf("last_q_size: %d\n", list->last_q_size);
	ft_printf("q_borders:\n");
	ft_printf("1: %d - %d\n", list->q_borders[0][0], list->q_borders[0][1]);
	ft_printf("2: %d - %d\n", list->q_borders[1][0], list->q_borders[1][1]);
	ft_printf("3: %d - %d\n", list->q_borders[2][0], list->q_borders[2][1]);
	ft_printf("4: %d - %d\n", list->q_borders[3][0], list->q_borders[3][1]);
}

/*
** Print the insert infos
*/
void	print_insert_info(t_slist *list, t_insert insert)
{
	ft_printf("value: %d\n", insert.value);
	ft_printf("spot: %d\n", insert.spot);
	ft_printf("stack[spot]: %d\n", list->stack_a->stack[insert.spot]);
	ft_printf("cost: %d\n", insert.cost);
}
