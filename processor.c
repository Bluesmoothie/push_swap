/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:00:55 by ygille            #+#    #+#             */
/*   Updated: 2025/01/14 22:36:50 by ygille           ###   ########.fr       */
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
	process_wchunk(list, 5);
}

void	process_rbig(t_slist *list)
{
	process_wchunk(list, 11);
}

void	process_wchunk(t_slist *list, int chunk_num)
{
	int	i;
	int	chunk_size;

	i = 1;
	calc_chunck(list, chunk_num);
	while (i <= chunk_num)
	{
		if (i != chunk_num)
			chunk_size = chunk_nums_gen(list, i);
		else
			chunk_size = last_chunk_nums_gen(list, i);
		// print_chunk(list->chunck_nums, chunk_size);
		if (chunk_size)
		{
			// ft_printf("chunk move %d\n", i);
			chunk_move(list, chunk_size);
			// print_state(list);
			// ft_printf("chunk sort %d\n", i);
			sort_chunk(list, chunk_size);
			// print_state(list);
			// ft_printf("chunk process %d\n", i);
			process_chunk(list, i, chunk_size);
			// print_state(list);
			free(list->sorted_chunk);
			list->sorted_chunk = NULL;
		}
		free(list->chunck_nums);
		list->chunck_nums = NULL;
		i++;
	}
	if (list->stack_a->stack[0] != list->sorted[0])
		r_or_rr(list->stack_a, list->sorted[0], list, XA);
	// print_state(list);
}
