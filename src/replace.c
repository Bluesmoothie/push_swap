/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:47:08 by ygille            #+#    #+#             */
/*   Updated: 2025/01/20 16:38:39 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
