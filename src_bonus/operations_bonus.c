/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:45:10 by ygille            #+#    #+#             */
/*   Updated: 2025/01/22 14:06:21 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*get_operations(void)
{
	char	*operations;
	char	*str;
	char	*tmp;

	str = get_next_line(0);
	operations = NULL;
	while (str)
	{
		tmp = operations;
		operations = ft_strjoin(operations, str);
		free (tmp);
		free(str);
		str = get_next_line(0);
	}
	return (operations);
}

void	apply_operations(t_slist *list, char *operations)
{
	int	i;
	int	op_code;

	i = 0;
	while (operations[i])
	{
		op_code = -1;
		if (operations[i] == 's')
		{
			if (operations[i + 1] == 'a')
				op_code = SA;
			else if (operations[i + 1] == 'b')
				op_code = SB;
			else if (operations[i + 1] == 's')
				op_code = SS;
		}
		else if (operations[i] == 'p')
		{
			if (operations[i + 1] == 'a')
				op_code = PA;
			else if (operations[i + 1] == 'b')
				op_code = PB;
		}
		else if (operations[i] == 'r')
		{
			if (operations[i + 1] == 'a')
				op_code = RA;
			else if (operations[i + 1] == 'b')
				op_code = RB;
			else if (operations[i + 1] == 'r' && operations[i + 2] == '\n')
				op_code = RR;
		}
		else if (operations[i] == 'r' && operations[i + 1] == 'r')
		{
			if (operations[i + 2] == 'a')
				op_code = RRA;
			else if (operations[i + 2] == 'b')
				op_code = RRB;
			else if (operations[i + 2] == 'r')
				op_code = RRR;
		}
		if (op_code == -1)
			error(list, 1);
	}
}
