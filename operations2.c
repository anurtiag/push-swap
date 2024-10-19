/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:30:02 by anurtiag          #+#    #+#             */
/*   Updated: 2024/01/22 14:51:23 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_printf("rrr\n");
}

void	put_node_first(t_dllist *list, t_node *node, int mode)
{
	while (node != list->first)
	{
		if (node->index == TRUE)
			rotate(list, mode);
		if (node->index == FALSE)
			reverse_rotate(list, mode);
	}
}

void	put_nodes_first(t_node *node_a, t_dllist *stack_a, \
t_node *node_b, t_dllist *stack_b)
{
	if (node_a->index == node_b->index)
	{
		while (node_a != stack_a->first && node_b != stack_b->first)
		{
			if (node_a->index == TRUE)
				double_rotate(stack_a, stack_b);
			if (node_a->index == FALSE)
				double_reverse_rotate(stack_a, stack_b);
		}
	}
	if (stack_a->first != node_a)
		put_node_first(stack_a, node_a, A);
	if (stack_b->first != node_b)
		put_node_first(stack_b, node_b, B);
}
