/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:00:55 by ygille            #+#    #+#             */
/*   Updated: 2025/01/20 17:01:57 by ygille           ###   ########.fr       */
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
	inst_decoder(PB, list);
	if (list->stack_a->size == 5)
		inst_decoder(PB, list);
	process_small(list);
	calc_mov(list);
	if (list->stack_a->size == 5)
		calc_mov(list);
	r_or_rr(list->stack_a, list->sorted[0], list, XA);
}

/*
** Process a stack with more than 5 to 100 elements
*/
void	process_big(t_slist *list)
{
	replace_numbers(list);
	print_state(list);
	calc_q_size(list);
	print_quartile_info(list);
	move_outer(list);
	move_inner(list);
}
