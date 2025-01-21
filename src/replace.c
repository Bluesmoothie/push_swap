/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:47:08 by ygille            #+#    #+#             */
/*   Updated: 2025/01/21 19:38:21 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Replace the numbers in the stack_a by their index in the sorted array
*/
void	replace_numbers(t_slist *list)
{
	int	i;
	int	j;

	i = 0;
	while (i < list->stack_a->size)
	{
		j = 0;
		while (list->stack_a->stack[j] != list->sorted[i])
			j++;
		list->stack_a->stack[j] = i;
		i++;
	}
}
