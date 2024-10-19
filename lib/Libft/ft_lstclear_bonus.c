/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:28:34 by anurtiag          #+#    #+#             */
/*   Updated: 2024/02/03 11:21:18 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list	**lst, void (*del)(void *))
{
	t_list	*node;

	if (!lst || !del)
		return ;
	if (*lst)
	{
		while (*lst)
		{
			node = (*lst);
			*lst = (*lst)->next;
			del(node->content);
			free(node);
		}
		return ;
	}
}
