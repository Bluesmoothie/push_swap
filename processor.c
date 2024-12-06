/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:00:55 by ygille            #+#    #+#             */
/*   Updated: 2024/12/06 19:51:02 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	process_mid(t_slist *list)
{
	inst_decoder(PB, list);
	inst_decoder(PB, list);
	process_small(list);
	calc_mov(list);
	calc_mov(list);
}

void	process_big(t_slist *list)
{
	(void) list;
}

void	process_rbig(t_slist *list)
{
	(void) list;
}