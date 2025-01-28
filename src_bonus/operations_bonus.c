/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:45:10 by ygille            #+#    #+#             */
/*   Updated: 2025/01/28 13:17:43 by ygille           ###   ########.fr       */
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
	if (!operations)
		return ;
	while (operations[i] != '\0')
	{
		op_code = -1;
		if (operations[i] == 's')
			op_code = decode_swap(&operations[i]);
		else if (operations[i] == 'p')
			op_code = decode_push(&operations[i]);
		else if (operations[i] == 'r' && operations[i + 1] != 'r')
			op_code = decode_rotate(&operations[i]);
		else if (operations[i] == 'r' && operations[i + 1] == 'r')
			op_code = decode_reverse_rotate(&operations[i]);
		if (op_code == -1)
			error(list, 1);
		inst_decoder(op_code, list);
		i = i + 3;
		if (op_code > 33)
			i++;
	}
}
