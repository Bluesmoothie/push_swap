/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:16:38 by ygille            #+#    #+#             */
/*   Updated: 2024/12/06 13:27:51 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inst_swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->stack[stack->minp];
	stack->stack[stack->minp] = stack->stack[stack->minp + 1];
	stack->stack[stack->minp + 1] = tmp;
}

void	inst_push(t_stack *src, t_stack *dst)
{
	if (src->size == 0)
		return ;
	dst->stack[dst->minp - 1] = src->stack[src->minp];
	dst->minp--;
	src->minp++;
	dst->size++;
	src->size--;
}

void	inst_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	tmp = stack->stack[stack->minp];
	i = stack->minp;
	while (i < stack->maxp)
	{
		stack->stack[i] = stack->stack[i + 1];
		i++;
	}
	stack->stack[stack->maxp] = tmp;
}

void	inst_rev_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	tmp = stack->stack[stack->maxp];
	i = stack->maxp;
	while (i > stack->minp)
	{
		stack->stack[i] = stack->stack[i - 1];
		i--;
	}
	stack->stack[stack->minp] = tmp;
}
