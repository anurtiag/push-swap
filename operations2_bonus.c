/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 07:08:05 by anurtiag          #+#    #+#             */
/*   Updated: 2024/02/02 12:00:27 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	reverse_rotate(t_dllist *list, int mode)
{
	t_node	*node;

	if (list->size < 2)
		return ;
	node = list->last;
	list->first = node;
	list->last = node->prev;
	if (mode == A)
		ft_printf("rra\n");
	else if (mode == B)
		ft_printf("rrb\n");
}

void	double_reverse_rotate(t_dllist *stack_a, t_dllist *stack_b)
{
	reverse_rotate(stack_a, NOTHING);
	reverse_rotate(stack_b, NOTHING);
}
