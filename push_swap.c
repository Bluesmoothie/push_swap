/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:17:13 by ygille            #+#    #+#             */
/*   Updated: 2024/12/05 13:04:06 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_state(int *stack_a, int *stack_b, int *sorted, int max_pos);

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	*sorted;

	if (argc < 2)
		return (1);
	if (argc > 2)
		stack_a = parse_args(argc, argv);
	else
		stack_a = alt_parse_args(argv[1]);
	stack_b = malloc(sizeof(int) * (argc - 1));
	if (!stack_b)
		error();
	sorted = sort(stack_a, argc - 1);
	print_state(stack_a, stack_b, sorted, argc - 2);
	process(stack_a, stack_b, sorted, argc - 2);
	return (0);
}

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	print_state(int *stack_a, int *stack_b, int *sorted, int max_pos)
{
	int	i;

	i = 0;
	ft_printf("a     b     s\n\n");
	while (i <= max_pos)
	{
		ft_printf("%d     %d     %d\n", stack_a[i], stack_b[i], sorted[max_pos - i]);
		i++;
	}
}