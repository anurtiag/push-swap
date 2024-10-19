/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:01:24 by anurtiag          #+#    #+#             */
/*   Updated: 2024/02/02 12:26:59 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_dllist *list, int mode)
{
	int	tmp;

	tmp = 0;
	if (list->size < 2)
		return ;
	tmp = list->first->num;
	list->first->num = list->first->next->num;
	list->first->next->num = tmp;
	if (mode == A)
		ft_printf("sa\n");
	else if (mode == B)
		ft_printf("sb\n");
}

void	double_swap(t_dllist *stack_a, t_dllist *stack_b)
{
	swap(stack_a, NOTHING);
	swap(stack_b, NOTHING);
}

void	push_node(t_dllist *src_list, t_dllist *dst_list, int mode)
{
	t_node	*tmp;

	if (src_list->size < 1)
		return ;
	tmp = src_list->first;
	ft_rmvdll_node(src_list);
	ft_dll_new(dst_list, tmp->num, mode, NULL);
	free(tmp);
	if (src_list->size == 0)
	{
		freedll(src_list);
		src_list->first = NULL;
		src_list->last = NULL;
		src_list->cheapest = NULL;
	}
	if (mode == A)
		ft_printf("pa\n");
	else if (mode == B)
		ft_printf("pb\n");
}

void	rotate(t_dllist *list, int mode)
{
	t_node	*node;

	if (list->size < 2)
		return ;
	node = list->first;
	list->first = node->next;
	list->last = node;
	if (mode == A)
		ft_printf("ra\n");
	else if (mode == B)
		ft_printf("rb\n");
}

void	double_rotate(t_dllist *stack_a, t_dllist *stack_b)
{
	rotate(stack_a, NOTHING);
	rotate(stack_b, NOTHING);
	ft_printf("rr\n");
}
