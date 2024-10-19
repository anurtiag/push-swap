/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:08:32 by anurtiag          #+#    #+#             */
/*   Updated: 2024/02/03 11:21:48 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list	*lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	else
	{
		while (lst)
		{
			lst = lst->next;
			i++;
		}
	}
	return (i);
}
