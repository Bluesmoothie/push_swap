/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:23:44 by ygille            #+#    #+#             */
/*   Updated: 2024/12/06 19:51:32 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_mov(t_slist *list)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		pos;

	stack_a = list->stack_a;
	stack_b = list->stack_b;
	if (stack_b->stack[stack_b->minp] == list->sorted[0])
	{
		r_or_rr(stack_a, list->sorted[stack_b->size - 1], list);
		inst_decoder(PA, list);
	}
	else
	{
		pos = 1;
		while (stack_b->stack[stack_b->minp] != list->sorted[pos])
			pos++;
		pos++;
		r_or_rr(stack_a, list->sorted[pos], list);
		inst_decoder(PA, list);
	}
}
