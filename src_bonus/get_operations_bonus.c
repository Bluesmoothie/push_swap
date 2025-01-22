/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_operations_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:45:10 by ygille            #+#    #+#             */
/*   Updated: 2025/01/22 13:51:30 by ygille           ###   ########.fr       */
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
