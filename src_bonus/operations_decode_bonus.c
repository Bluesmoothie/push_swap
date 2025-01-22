/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_decode_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:07:04 by ygille            #+#    #+#             */
/*   Updated: 2025/01/22 15:11:51 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	decode_swap(char *operations)
{
	if (operations[1] == 'a')
		return (SA);
	else if (operations[1] == 'b')
		return (SB);
	else if (operations[1] == 's')
		return (SS);
	return (-1);
}

int	decode_push(char *operations)
{
	if (operations[1] == 'a')
		return (PA);
	else if (operations[1] == 'b')
		return (PB);
	return (-1);
}

int	decode_rotate(char *operations)
{
	if (operations[1] == 'a')
		return (RA);
	else if (operations[1] == 'b')
		return (RB);
	else if (operations[1] == 'r')
		return (RR);
	return (-1);
}

int	decode_reverse_rotate(char *operations)
{
	if (operations[2] == 'a')
		return (RRA);
	else if (operations[2] == 'b')
		return (RRB);
	else if (operations[2] == 'r')
		return (RRR);
	return (-1);
}
