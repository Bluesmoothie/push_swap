/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:17:13 by ygille            #+#    #+#             */
/*   Updated: 2024/12/06 14:02:13 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_state(int *stack_a, int *stack_b, int *sorted, int max_pos);

int	main(int argc, char **argv)
{
	t_slist	*list;

	if (argc < 2)
		return (1);
	list = list_init();
	if (!list)
		error(NULL, 1);
	if (argc > 2)
		list->stack_a = parse_args(argc, argv, list);
	else
		list->stack_a = alt_parse_args(&argc, argv[1], list);
	list->stack_b = init_stack(list->stack_a->size, list);
	list->sorted = sort(list->stack_a, list);
	if (!is_sorted(list))
		process(list);
	error(list, 0);
	return (0);
}

void	error(t_slist *list, int error)
{
	if (list->stack_a->stack)
		free(list->stack_a->stack);
	if (list->stack_b->stack)
		free(list->stack_b->stack);
	if (list->sorted)
		free(list->sorted);
	if (list->stack_a)
		free(list->stack_a);
	if (list->stack_b)
		free(list->stack_b);
	if (list)
		free(list);
	if (error)
	{
		ft_putstr_fd("Error\n", 2);
		exit(error);
	}
}

t_slist	*list_init(void)
{
	t_slist	*list;

	list = malloc(sizeof(t_slist));
	if (!list)
		error (NULL, 1);
	list->stack_a = NULL;
	list->stack_b = NULL;
	list->sorted = NULL;
	return (list);
}

// void	print_state(int *stack_a, int *stack_b, int *sorted, int max_pos)
// {
// 	int	i;

// 	i = 0;
// 	ft_printf("a     b     s\n\n");
// 	while (i <= max_pos)
// 	{
// 		ft_printf("%d     %d     %d\n", stack_a[i], stack_b[i], sorted[max_pos - i]);
// 		i++;
// 	}
// }