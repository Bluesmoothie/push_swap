/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:17:13 by ygille            #+#    #+#             */
/*   Updated: 2024/12/04 17:32:37 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*stack;
	int i;
	//int	*sorted;

	if (argc < 2)
		return (1);
	stack = parse_args(argc, argv);
	i = 0;
	while (i < argc - 1)
	{
		ft_printf("%d\n", stack[i]);
		i++;
	}
	return (0);
}

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
