/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:26:49 by ygille            #+#    #+#             */
/*   Updated: 2024/12/03 19:26:56 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse_args(int argc, char **argv)
{
	int	*stack;
	int	i;

	stack = malloc(sizeof(int) * (argc - 1));
	if (!stack)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		if (verify_arg(argv[i + 1]))
		{
			free(stack);
			return (NULL);
		}
		stack[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (stack);
}

int	verify_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) && arg[i] != '-')
			return (1);
		i++;
	}
	return (0);
}
