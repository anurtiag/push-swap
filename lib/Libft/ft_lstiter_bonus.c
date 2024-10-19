/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 08:04:36 by anurtiag          #+#    #+#             */
/*   Updated: 2024/02/03 11:21:32 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list	*lst, void (*f)(void *))
{
	if (!lst)
		return ;
	else
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
	return ;
}
