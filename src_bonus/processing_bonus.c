/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:38:51 by ygille            #+#    #+#             */
/*   Updated: 2025/01/22 13:36:27 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*
** Check if the stack is sorted
*/
int	is_sorted(t_slist *list)
{
	int	i;

	i = 0;
	while (i <= list->stack_a->maxp)
	{
		if (list->stack_a->stack[i] != list->sorted[i])
			return (0);
		i++;
	}
	return (1);
}
