/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 08:28:43 by anurtiag          #+#    #+#             */
/*   Updated: 2024/02/02 12:26:09 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*max_number(t_dllist *list, int limiter)
{
	t_node	*tmp;
	t_node	*node;
	int		max;
	int		i;

	node = list->first;
	i = -1;
	tmp = NULL;
	max = INT_MIN;
	while (list->size > ++i)
	{
		if (node->num > max && node->num < limiter)
		{
			max = node->num;
			tmp = node;
		}
		node = node->next;
	}
	return (tmp);
}

t_node	*min_number(t_dllist *list, int limiter)
{
	t_node	*tmp;
	t_node	*node;
	int		min;
	int		i;

	node = list->first;
	i = -1;
	tmp = NULL;
	min = INT_MAX;
	while (list->size > ++i)
	{
		if (node->num < min && node->num > limiter)
		{
			min = node->num;
			tmp = node;
		}
		node = node->next;
	}
	return (tmp);
}

int	is_sorted(t_dllist *list)
{
	t_node	*node;
	int		i;

	node = list->first;
	i = -1;
	while (list->size - 1 > ++i)
	{
		if (node->num > node->next->num)
			return (FALSE);
		node = node->next;
	}
	return (TRUE);
}

int	rptd_num(t_dllist *list)
{
	t_node	*next;
	t_node	*node;
	int		i;
	int		j;

	i = -1;
	if (list->size < 2)
		return (1);
	next = list->first->next;
	node = list->first;
	while (++i < list->size)
	{
		j = i;
		while (++j < list->size)
		{
			if (node->num == next->num)
			{
				return (0);
			}
			next = next->next;
		}
		node = node->next;
		next = node->next;
	}
	return (1);
}

void	below_midlist(t_node *node, int size)
{
	if ((node->pos) <= ((size - 1) / 2))
		node->index = TRUE;
	else
		node->index = FALSE;
}
