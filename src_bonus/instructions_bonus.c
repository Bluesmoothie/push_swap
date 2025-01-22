/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:16:38 by ygille            #+#    #+#             */
/*   Updated: 2025/01/01 14:12:34 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Swap the first two elements of the stack
*/
void	inst_swap(t_stack *stack)
{
	int	tmp;

	if (stack->minp >= stack->maxp)
		return ;
	tmp = stack->stack[stack->minp];
	stack->stack[stack->minp] = stack->stack[stack->minp + 1];
	stack->stack[stack->minp + 1] = tmp;
}

/*
** Push the first element of src to dst
*/
void	inst_push(t_stack *src, t_stack *dst)
{
	if (src->minp == src->size)
		return ;
	dst->stack[dst->minp - 1] = src->stack[src->minp];
	dst->minp--;
	src->minp++;
}

/*
** Rotate the stack
*/
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

/*
** Reverse rotate the stack
*/
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
