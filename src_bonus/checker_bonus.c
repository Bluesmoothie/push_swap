/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:08:30 by ygille            #+#    #+#             */
/*   Updated: 2025/01/21 20:22:22 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	bonus(int argc, char *argv[])
{
	t_slist	*list;

	if (argc < 2)
		return (1);
	list = list_init();
	if (!list)
		error(NULL, 1);
	if (argc > 2)
		parse_args(argc, argv, list);
	else
		list->stack_a = alt_parse_args(&argc, argv[1], list);
	if (is_sorted(list))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	error(list, 0);
	return (0);
}
