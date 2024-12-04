/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:17:13 by ygille            #+#    #+#             */
/*   Updated: 2024/12/04 18:05:22 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*stack;
	int i;
	int	*sorted;

	if (argc < 2)
		return (1);
	stack = parse_args(argc, argv);
	sorted = sort(stack, argc - 1);
	i = 0;
	while (i < argc - 1)
	{
		ft_printf("%d    %d\n", stack[i], sorted[i]);
		i++;
	}
	return (0);
}

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
