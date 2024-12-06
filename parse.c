/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:26:49 by ygille            #+#    #+#             */
/*   Updated: 2024/12/06 13:55:38 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*parse_args(int argc, char **argv, t_slist *list)
{
	t_stack	*stack;
	int		i;

	stack = init_stack(argc - 1, list);
	i = 0;
	while (i < argc - 1)
	{
		if (verify_arg(argv[i + 1], stack))
			error(list, 1);
		stack->stack[i] = ft_atoi(argv[i + 1]);
		if (i == 0 || stack->stack[i] > stack->maxval)
			stack->maxval = stack->stack[i];
		if (i == 0 || stack->stack[i] < stack->minval)
			stack->minval = stack->stack[i];
		stack->maxp = i;
		i++;
		stack->size = i;
	}
	return (stack);
}

int	verify_arg(char *arg, t_stack *stack)
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
	while (i < stack->size)
	{
		if (stack->stack[i] == ft_atoi(arg))
			return (1);
		i++;
	}
	return (0);
}

t_stack	*alt_parse_args(int	*argc, char *arg, t_slist *list)
{
	char	**split;
	t_stack	*stack;
	int		i;

	split = ft_split(arg, ' ');
	if (!split)
		error(list, 1);
	i = 0;
	while (split[i])
		i++;
	stack = fill_stack(split, i, list);
	free(split);
	*argc = i + 1;
	return (stack);
}

t_stack	*fill_stack(char **split, int size, t_slist *list)
{
	t_stack	*stack;
	int		i;

	stack = init_stack(size, list);
	i = 0;
	while (i < size)
	{
		if (verify_arg(split[i], stack))
			error(list, 1);
		stack->stack[i] = ft_atoi(split[i]);
		free(split[i]);
		if (i == 0 || stack->stack[i] > stack->maxval)
			stack->maxval = stack->stack[i];
		if (i == 0 || stack->stack[i] < stack->minval)
			stack->minval = stack->stack[i];
		stack->maxp = i;
		i++;
		stack->size = i;
	}
	return (stack);
}

t_stack	*init_stack(int size, t_slist *list)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		error(list, 1);
	stack->stack = malloc(sizeof(int) * size);
	if (!stack->stack)
		error(list, 1);
	stack->size = size;
	stack->minp = 0;
	stack->maxp = 0;
	stack->maxval = 0;
	stack->minval = 0;
	return (stack);
}
