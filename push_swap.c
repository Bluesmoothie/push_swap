/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:17:13 by ygille            #+#    #+#             */
/*   Updated: 2024/12/06 17:57:41 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	list->stack_b->maxp = list->stack_a->maxp;
	list->stack_b->minp = list->stack_b->maxp + 1;
	list->sorted = sort(list->stack_a, list);
	if (!is_sorted(list))
		choose_process(list);
	error(list, 0);
	return (0);
}

void	error(t_slist *list, int error)
{
	if (list)
	{
		if (list->stack_a)
		{
			if (list->stack_a->stack)
				free(list->stack_a->stack);
			free(list->stack_a);
		}
		if (list->stack_b)
		{
			if (list->stack_b->stack)
				free(list->stack_b->stack);
			free(list->stack_b);
		}
		if (list->sorted)
			free(list->sorted);
		free(list);
	}
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

void	print_state(t_slist *list)
{
	int		i;
	char	a;
	char	b;

	i = 0;
	ft_printf("a    b    s\n\n");
	while (i <= list->stack_a->maxp)
	{
		if (i >= list->stack_a->minp)
			a = list->stack_a->stack[i] + '0';
		else
			a = 'X';
		if (i >= list->stack_b->minp)
			b = list->stack_b->stack[i] + '0';
		else
			b = 'X';
		ft_printf("%c    %c    %d\n", a, b, list->sorted[i]);
		i++;
	}
	ft_printf("\n");
}
