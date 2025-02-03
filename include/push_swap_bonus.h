/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:08:55 by ygille            #+#    #+#             */
/*   Updated: 2025/02/03 16:28:31 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"
# include "get_next_line.h"

//operations_bonus.c
char	*get_operations(void);
void	apply_operations(t_slist *list, char *operations);
void	apply_error(char *operations, t_slist *list);

//operations_decode_bonus.c
int		decode_swap(char *operations);
int		decode_push(char *operations);
int		decode_rotate(char *operations);
int		decode_reverse_rotate(char *operations);

#endif