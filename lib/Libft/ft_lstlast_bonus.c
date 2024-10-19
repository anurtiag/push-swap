/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:59:45 by anurtiag          #+#    #+#             */
/*   Updated: 2024/02/03 11:21:36 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list	*lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	else
	{
		while (lst)
		{
			if (!lst->next)
				return (lst);
			lst = lst->next;
			i++;
		}
	}
	return (lst);
}
