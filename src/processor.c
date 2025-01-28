/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:00:55 by ygille            #+#    #+#             */
/*   Updated: 2025/01/28 17:02:10 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Process a stack with 3 elements
*/
void	process_small(t_slist *list)
{
	int	minp;
	int	*s;

	minp = list->stack_a->minp;
	s = list->stack_a->stack;
	if (s[minp + 1] < s[minp] && s[minp] < s[minp + 2])
		inst_decoder(SA, list);
	else if (s[minp + 2] < s[minp + 1] && s[minp + 1] < s[minp])
	{
		inst_decoder(SA, list);
		inst_decoder(RRA, list);
	}
	else if (s[minp + 1] < s[minp + 2] && s[minp + 2] < s[minp])
		inst_decoder(RA, list);
	else if (s[minp] < s[minp + 2] && s[minp + 2] < s[minp + 1])
	{
		inst_decoder(SA, list);
		inst_decoder(RA, list);
	}
	else if (s[minp + 2] < s[minp] && s[minp] < s[minp + 1])
		inst_decoder(RRA, list);
}

/*
** Process a stack with 5 or 4 elements
*/
void	process_mid(t_slist *list)
{
	replace_numbers(list);
	inst_decoder(PB, list);
	if (list->stack_a->size == 5)
		inst_decoder(PB, list);
	process_small(list);
	sort_mid(list);
}

/*
** Process a stack with more than 5 elements
*/
void	process_big(t_slist *list)
{
	replace_numbers(list);
	calc_q_size(list);
	move_inner(list);
	move_outer(list);
	process_small(list);
	sort_quartile(list);
}

/*
** Sort the stack_b and put the numbers back in the stack_a
*/
void	sort_mid(t_slist *list)
{
	t_insert	to_insert;

	while (list->stack_a->minp != 0)
	{
		to_insert = mid_calc_less_op(list);
		r_or_rr(list->stack_b, to_insert.value, list, XB);
		r_or_rr(list->stack_a, to_insert.spot, list, XA);
		inst_decoder(PA, list);
	}
	r_or_rr(list->stack_a, 0, list, XA);
}

/*
** Calculate the best move to insert a number from the stack_b
*/
t_insert	mid_calc_less_op(t_slist *list)
{
	int			i;
	t_insert	insert;
	t_insert	tmp;

	i = list->stack_b->minp;
	insert.cost = -1;
	while (i <= list->stack_b->maxp)
	{
		tmp.value = list->stack_b->stack[i];
		tmp.spot = find_spot(list->stack_a, tmp.value);
		tmp.cost = best_move(list->stack_a, tmp.spot)
			+ best_move(list->stack_b, tmp.value);
		if (insert.cost == -1)
			insert = tmp;
		else if (tmp.cost < insert.cost)
			insert = tmp;
		i++;
	}
	return (insert);
}
