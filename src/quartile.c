/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:53:32 by ygille            #+#    #+#             */
/*   Updated: 2025/01/21 16:21:21 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_q_size(t_slist *list)
{
	list->q_size = list->stack_a->size / 4;
	list->last_q_size = list->stack_a->size - list->q_size * 3;
	list->q_borders[0][0] = 0;
	list->q_borders[0][1] = list->q_size - 1;
	list->q_borders[1][0] = list->q_size;
	list->q_borders[1][1] = list->q_size * 2 - 1;
	list->q_borders[2][0] = list->q_size * 2;
	list->q_borders[2][1] = list->q_size * 3 - 1;
	list->q_borders[3][0] = list->q_size * 3;
	list->q_borders[3][1] = list->q_size * 3 + list->last_q_size - 1;
}

void	move_outer(t_slist *list)
{
	int		i;
	t_stack	*stack;

	i = 0;
	stack = list->stack_b;
	while (i < list->q_size + list->last_q_size - 3)
	{
		inst_decoder(PB, list);
		if (stack->stack[stack->minp] < list->q_borders[2][0])
			inst_decoder(RB, list);
		i++;
	}
}

void	move_inner(t_slist *list)
{
	int		i;
	t_stack	*stack;

	i = 0;
	stack = list->stack_a;
	while (i < list->q_size * 2)
	{
		if (stack->stack[stack->minp] >= list->q_borders[1][0]
			&& stack->stack[stack->minp] <= list->q_borders[1][1])
		{
			inst_decoder(PB, list);
			inst_decoder(RB, list);
		}
		else if (stack->stack[stack->minp] >= list->q_borders[2][0]
			&& stack->stack[stack->minp] <= list->q_borders[2][1])
			inst_decoder(PB, list);
		else
		{
			inst_decoder(RA, list);
			i--;
		}
		i++;
	}
}

// void	sort_outer(t_slist *list)
// {
// 	int	up;
// 	int	down;

// 	up = list->q_borders[0][1];
// 	down = list->q_borders[3][0];
// 	while (up >= list->q_borders[0][0] && down <= list->q_borders[3][1])
// 	{
// 		if (nearest_between(list, up, down))
// 		{
// 			r_or_rr(list->stack_b, up, list, XB);
// 			inst_decoder(PA, list);
// 			up--;
// 		}
// 		else
// 		{
// 			r_or_rr(list->stack_b, down, list, XB);
// 			inst_decoder(PA, list);
// 			inst_decoder(RA, list);
// 			down++;
// 		}
// 	}
// }

// void	sort_inner(t_slist *list)
// {
// 	int	up;
// 	int	down;

// 	up = list->q_borders[1][1];
// 	down = list->q_borders[2][0];
// 	while (up >= list->q_borders[1][0] && down <= list->q_borders[2][1])
// 	{
// 		if (nearest_between(list, up, down))
// 		{
// 			r_or_rr(list->stack_b, up, list, XB);
// 			inst_decoder(PA, list);
// 			up--;
// 		}
// 		else
// 		{
// 			r_or_rr(list->stack_b, down, list, XB);
// 			inst_decoder(PA, list);
// 			inst_decoder(RA, list);
// 			down++;
// 		}
// 	}
// }
void	sort_quartile(t_slist *list)
{
	(void) list;
}
