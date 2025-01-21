/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:17:13 by ygille            #+#    #+#             */
/*   Updated: 2025/01/21 20:28:04 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_slist	*list;
#if BONUS_MODE
		return (bonus(argc, argv));
#endif
	if (argc < 2)
		return (1);
	list = list_init();
	if (!list)
		error(NULL, 1);
	if (argc > 2)
		parse_args(argc, argv, list);
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

/*
** Free the list and exit
** display an error message if error is not 0
*/
void	error(t_slist *list, int error)
{
	if (list)
	{
		if (list->stack_a)
			free_stack(list->stack_a);
		if (list->stack_b)
			free_stack(list->stack_b);
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

/*
** Initialize the list structure
*/
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
