/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:29:53 by ygille            #+#    #+#             */
/*   Updated: 2024/12/10 15:54:09 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	if (stack->stack)
		free(stack->stack);
	free(stack);
}

void	free_chunk(t_slist *list)
{
	if (list->chunck_nums)
	{
		free(list->chunck_nums);
		list->chunck_nums = NULL;
	}
	if (list->sorted_chunk)
	{
		free(list->sorted_chunk);
		list->sorted_chunk = NULL;
	}
}
