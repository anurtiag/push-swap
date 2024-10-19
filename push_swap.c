/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:51:12 by anurtiag          #+#    #+#             */
/*   Updated: 2024/02/02 12:24:36 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_of_three(t_dllist	*list, int mode)
{
	t_node	*max;

	max = max_number(list, INT_MAX);
	if (list->first == max)
		rotate(list, mode);
	else if (list->first->next == max)
		reverse_rotate(list, mode);
	if (list->first->num > list->first->next->num)
		swap(list, mode);
}

void	push_to_b(t_dllist *stack_a, t_dllist *stack_b)
{
	t_node	*node;

	node = NULL;
	push_node(stack_a, stack_b, B);
	push_node(stack_a, stack_b, B);
	while (stack_a->size > 3 && !is_sorted(stack_a))
	{
		set_pos(stack_a);
		set_pos(stack_b);
		cheapest_cal(stack_a, stack_b);
		put_nodes_first(stack_a->cheapest, stack_a, \
		stack_a->cheapest->target, stack_b);
		push_node(stack_a, stack_b, B);
	}
	stack_of_three(stack_a, A);
	node = max_number(stack_b, INT_MAX);
	set_pos(stack_b);
	set_pos(stack_a);
	put_node_first(stack_b, node, B);
}

void	push_to_a(t_dllist *stack_a, t_dllist *stack_b, t_node *node)
{
	while (stack_b->size != 0)
	{
		node = stack_b->first;
		node->target = min_number(stack_a, node->num);
		if (node->target == NULL)
			node->target = min_number(stack_a, INT_MIN);
		put_node_first(stack_a, node->target, A);
		push_node(stack_b, stack_a, A);
		set_pos(stack_a);
		set_pos(stack_b);
	}
}

void	push_swap(t_dllist *stack_a, t_dllist *stack_b)
{
	t_node	*node;

	node = NULL;
	if (stack_a->size == 4)
	{
		push_node(stack_a, stack_b, B);
		stack_of_three(stack_a, A);
	}
	else if (stack_a->size > 4)
		push_to_b(stack_a, stack_b);
	push_to_a(stack_a, stack_b, node);
	if (!is_sorted(stack_a))
	{
		node = min_number(stack_a, INT_MIN);
		put_node_first(stack_a, node, A);
	}
}

int	main(int argc, char **argv)
{
	t_dllist	*stack_a;
	t_dllist	*stack_b;
	char		*null;

	null = NULL;
	stack_a = prmt_handle(argc, argv);
	stack_b = make_list(&null, 0);
	if (!is_sorted(stack_a))
	{
		if (stack_a->size == 2)
			swap(stack_a, A);
		else if (stack_a->size == 3)
			stack_of_three(stack_a, A);
		else
			push_swap(stack_a, stack_b);
	}
	freedll(stack_a);
	return (0);
}
