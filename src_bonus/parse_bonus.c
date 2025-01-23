/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:26:49 by ygille            #+#    #+#             */
/*   Updated: 2025/01/23 14:09:06 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*
** Parse the arguments and fill the stack
*/
void	*parse_args(int argc, char **argv, t_slist *list)
{
	t_stack	*stack;
	int		i;

	list->stack_a = init_stack(argc - 1, list);
	stack = list->stack_a;
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

/*
** Verify if the argument is a number and if it is not already in the stack
*/
int	verify_arg(char *arg, t_stack *stack)
{
	int		i;
	long	num;

	i = 0;
	if (ft_strlen(arg) > 11 || ft_strlen(arg) == 0)
		return (1);
	if (arg[i] == '-' && ft_isdigit(arg[i + 1]))
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	num = ft_atol(arg);
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	i = 0;
	while (i <= stack->maxp && stack->maxp > 0)
	{
		if (stack->stack[i] == ft_atoi(arg))
			return (1);
		i++;
	}
	return (0);
}

/*
** Parse the arguments and fill the stack
** when the arguments are in a single string
*/
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
	if (i == 0)
	{
		free_split(split);
		error(list, 1);
	}
	stack = fill_stack(split, i, list);
	*argc = i + 1;
	return (stack);
}

/*
** Fill the stack with split
*/
t_stack	*fill_stack(char **split, int size, t_slist *list)
{
	t_stack	*stack;
	int		i;

	list->stack_a = init_stack(size, list);
	stack = list->stack_a;
	i = 0;
	while (i < size)
	{
		if (verify_arg(split[i], stack))
		{
			free_split(split);
			error(list, 1);
		}
		stack->stack[i] = ft_atoi(split[i]);
		if (i == 0 || stack->stack[i] > stack->maxval)
			stack->maxval = stack->stack[i];
		if (i == 0 || stack->stack[i] < stack->minval)
			stack->minval = stack->stack[i];
		stack->maxp = i;
		i++;
		stack->size = i;
	}
	free_split(split);
	return (stack);
}

/*
** Initialize the stack structure
*/
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
