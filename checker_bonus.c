/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 07:00:57 by anurtiag          #+#    #+#             */
/*   Updated: 2024/02/02 11:59:15 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	wrong_move(char	*line, t_dllist *stack_a, t_dllist *stack_b)
{
	if (stack_b)
		freedll (stack_b);
	free (line);
	errors (STDR_ERROR, 0, stack_a, NULL);
}

void	make_movements(char	*line, t_dllist *stack_a, t_dllist *stack_b)
{
	if (ft_strncmp(line, "sa", 2) == 0)
		swap(stack_a, NOTHING);
	else if (ft_strncmp(line, "sb", 2) == 0)
		swap(stack_b, NOTHING);
	else if (ft_strncmp(line, "ss", 2) == 0)
		double_swap(stack_a, stack_b);
	else if (ft_strncmp(line, "rra", 3) == 0)
		reverse_rotate(stack_a, NOTHING);
	else if (ft_strncmp(line, "rrb", 3) == 0)
		reverse_rotate(stack_b, NOTHING);
	else if (ft_strncmp(line, "rrr", 3) == 0)
		double_reverse_rotate(stack_a, stack_b);
	else if (ft_strncmp(line, "ra", 2) == 0)
		rotate(stack_a, NOTHING);
	else if (ft_strncmp(line, "rb", 2) == 0)
		rotate(stack_b, NOTHING);
	else if (ft_strncmp(line, "rr", 2) == 0)
		double_rotate(stack_a, stack_b);
	else if (ft_strncmp(line, "pa", 2) == 0)
		push_node(stack_b, stack_a, NOTHING);
	else if (ft_strncmp(line, "pb", 2) == 0)
		push_node(stack_a, stack_b, NOTHING);
	else
		wrong_move(line, stack_a, stack_b);
	free(line);
}

int	main(int argc, char **argv)
{
	t_dllist	*stack_a;
	t_dllist	*stack_b;
	char		*null;
	char		*line;

	null = NULL;
	line = NULL;
	stack_a = prmt_handle(argc, argv);
	stack_b = make_list(&null, 0);
	while (1)
	{
		line = get_next_line(0);
		if (line)
			make_movements(line, stack_a, stack_b);
		else
			break ;
	}
	if (is_sorted(stack_a))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	freedll(stack_a);
	return (0);
}
