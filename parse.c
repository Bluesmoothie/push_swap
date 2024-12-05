/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:26:49 by ygille            #+#    #+#             */
/*   Updated: 2024/12/05 15:35:31 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse_args(int argc, char **argv)
{
	int	*stack;
	int	i;

	stack = malloc(sizeof(int) * (argc - 1));
	if (!stack)
		error();
	i = 0;
	while (i < argc - 1)
	{
		if (verify_arg(argv[i + 1], stack, i))
		{
			free(stack);
			error();
		}
		stack[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (stack);
}

int	verify_arg(char *arg, int *stack, int size)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) && arg[i] != '-')
			return (1);
		i++;
	}
	if (ft_atol(arg) > INT_MAX || ft_atol(arg) < INT_MIN)
		return (1);
	i = 0;
	while (i < size)
	{
		if (stack[i] == ft_atoi(arg))
			return (1);
		i++;
	}
	return (0);
}

int	*alt_parse_args(int	*argc, char *arg)
{
	char	**split;
	int		*stack;
	int		i;

	split = ft_split(arg, ' ');
	if (!split)
		error();
	i = 0;
	while (split[i])
		i++;
	stack = fill_stack(split, i);
	if (!stack)
	{
		free(split);
		error();
	}
	free(split);
	*argc = i + 1;
	return (stack);
}

int	*fill_stack(char **split, int size)
{
	int *stack;
	int i;

	stack = malloc(sizeof(int) * size);
	if (!stack)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (verify_arg(split[i], stack, i))
		{
			free(stack);
			return (NULL);
		}
		stack[i] = ft_atoi(split[i]);
		free(split[i]);
		i++;
	}
	return (stack);
}
