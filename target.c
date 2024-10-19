/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 08:23:24 by anurtiag          #+#    #+#             */
/*   Updated: 2024/01/22 15:02:57 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cheapest_cal(t_dllist *stack_a, t_dllist *stack_b)
{
	int		i;
	t_node	*node;

	i = -1;
	node = stack_a->first;
	stack_a->cheapest = NULL;
	while (stack_a->size > ++i)
	{
		node->pos = i;
		below_midlist (node, stack_a->size);
		find_target(node, stack_b);
		cost_cal(node, stack_a->size, stack_b->size);
		if (!stack_a->cheapest || (node->cost < stack_a->cheapest->cost))
			stack_a->cheapest = node;
		node = node->next;
	}
}

void	cost_cal(t_node	*node, int node_list, int target_list)
{
	if (node->index == node->target->index)
	{
		if (node->index == TRUE)
		{
			if (node->pos > node->target->pos)
				node->cost = node->pos + 1;
			else
				node->cost = node->target->pos + 1;
		}
		else
		{
			if ((node_list - (node->pos)) \
			< (target_list - (node->target->pos)))
				node->cost = (target_list - (node->target->pos)) + 1;
			else
				node->cost = (node_list - (node->pos)) + 1;
		}
	}
	else
		diff_index_cost_cal(node, node_list, target_list);
}

void	diff_index_cost_cal(t_node	*node, int node_list, int target_list)
{
	if (node->index == TRUE)
		node->cost = node->pos + \
		(target_list - (node->target->pos)) + 1;
	else
		node->cost = ((node_list - node->pos) + \
		(node->target->pos)) + 1;
}

void	find_target(t_node *node, t_dllist *list)
{
	node->target = NULL;
	node->target = max_number(list, node->num);
	if (node->target == NULL)
		node->target = max_number(list, INT_MAX);
}

void	set_pos(t_dllist *list)
{
	t_node	*node;
	int		i;

	i = -1;
	node = list->first;
	while (list->size > ++i)
	{
		node->pos = i;
		below_midlist(node, list->size);
		node = node->next;
	}
}
