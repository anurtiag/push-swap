/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 07:03:52 by anurtiag          #+#    #+#             */
/*   Updated: 2024/03/08 12:03:56 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_dll_new(t_dllist *list, int content, int mode, char **nums)
{
	t_node		*node;
	int			*nbr;

	nbr = NULL;
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		errors(STDR_ERROR, mode, list, nums);
	node->num = content;
	if (!list->first)
	{
		node->next = node;
		node->prev = node;
		list->first = node;
		list->last = node;
	}
	else
	{
		node->next = list->first;
		node->prev = list->last;
		list->last->next = node;
		list->first = node;
		node->next->prev = node;
	}
	list->size++;
}

void	ft_add_dll_node(t_dllist *list, int content, int mode, char **nums)
{
	t_node	*next;

	next = (t_node *)malloc(sizeof(t_node));
	if (!next)
		errors(STDR_ERROR, mode, list, nums);
	next->num = content;
	list->last->next = next;
	next->next = NULL;
	next->prev = list->last;
	list->last = next;
	list->first->prev = list->last;
	list->last->next = list->first;
	list->size++;
}

t_dllist	*make_list(char **nums, int mode)
{
	t_dllist	*list;
	int			control;
	int			i;

	i = 0;
	list = NULL;
	control = TRUE;
	list = (t_dllist *)malloc(sizeof(t_dllist));
	if (!list)
		errors(STDR_ERROR, mode, NULL, nums);
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
	while (nums[i])
	{
		if (!list->first)
			ft_dll_new(list, ft_atoi_ps(nums[i], &control), mode, nums);
		else
			ft_add_dll_node(list, ft_atoi_ps(nums[i], &control), mode, nums);
		i++;
	}
	if (list && list->size > 0)
		if (rptd_num(list) == 0 || control == FALSE)
			errors(STDR_ERROR, mode, list, nums);
	return (list);
}

void	freedll(t_dllist *list)
{
	t_node	*node;
	t_node	*tmp;
	int		i;

	i = -1;
	node = list->first;
	tmp = node;
	while (++i < list->size)
	{
		node = node->next;
		free(tmp);
		tmp = NULL;
		tmp = node;
	}
	free(list);
	list = NULL;
}

void	ft_rmvdll_node(t_dllist *list)
{
	t_node	*tmp;

	tmp = list->first->next;
	tmp->prev = list->last;
	list->last->next = tmp;
	list->first = tmp;
	list->size--;
}
