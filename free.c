/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:29:53 by ygille            #+#    #+#             */
/*   Updated: 2024/12/10 13:32:19 by ygille           ###   ########.fr       */
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
		free(list->chunck_nums);
	if (list->sorted_chunk)
		free(list->sorted_chunk);
}
