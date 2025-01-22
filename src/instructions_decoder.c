/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_decoder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:40:48 by ygille            #+#    #+#             */
/*   Updated: 2025/01/22 13:34:13 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Decode the instruction and apply it
*/
void	inst_decoder(int inst, t_slist *list)
{
	if (inst == SA)
		inst_swap(list->stack_a);
	else if (inst == SB)
		inst_swap(list->stack_b);
	else if (inst == SS)
		inst_swap_both(list);
	else if (inst == PA)
		inst_push(list->stack_b, list->stack_a);
	else if (inst == PB)
		inst_push(list->stack_a, list->stack_b);
	else if (inst == RA)
		inst_rotate(list->stack_a);
	else if (inst == RB)
		inst_rotate(list->stack_b);
	else if (inst == RR)
		inst_rotate_both(list);
	else if (inst == RRA)
		inst_rev_rotate(list->stack_a);
	else if (inst == RRB)
		inst_rev_rotate(list->stack_b);
	else if (inst == RRR)
		inst_rev_rotate_both(list);
	inst_print(inst);
}

void	inst_swap_both(t_slist *list)
{
	inst_swap(list->stack_a);
	inst_swap(list->stack_b);
}

void	inst_rotate_both(t_slist *list)
{
	inst_rotate(list->stack_a);
	inst_rotate(list->stack_b);
}

void	inst_rev_rotate_both(t_slist *list)
{
	inst_rev_rotate(list->stack_a);
	inst_rev_rotate(list->stack_b);
}

/*
** Print the instruction code
*/
void	inst_print(int inst)
{
	if (inst == SA)
		ft_printf("sa\n");
	else if (inst == SB)
		ft_printf("sb\n");
	else if (inst == SS)
		ft_printf("ss\n");
	else if (inst == PA)
		ft_printf("pa\n");
	else if (inst == PB)
		ft_printf("pb\n");
	else if (inst == RA)
		ft_printf("ra\n");
	else if (inst == RB)
		ft_printf("rb\n");
	else if (inst == RR)
		ft_printf("rr\n");
	else if (inst == RRA)
		ft_printf("rra\n");
	else if (inst == RRB)
		ft_printf("rrb\n");
	else if (inst == RRR)
		ft_printf("rrr\n");
}
