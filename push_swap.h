/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:17:10 by ygille            #+#    #+#             */
/*   Updated: 2024/12/04 18:03:51 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <ft_printf.h>
# include <limits.h>

//push_swap.c
void	error(void);

//parse.c
int		*parse_args(int argc, char **argv);
int		verify_arg(char *arg, int *stack, int size);

//ft_atol.c
long	ft_atol(const char *nptr);

//sort.c
int		*sort(int *stack, int size);
int		*dup_stack(int *stack, int size);

#endif