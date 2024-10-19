/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:31:56 by anurtiag          #+#    #+#             */
/*   Updated: 2024/02/03 11:23:17 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = (ft_strlen (str));
	str += i;
	while (i > 0)
	{
		if (*str == (unsigned char)c)
			return (str);
		str--;
		i--;
	}
	if (*str == (unsigned char)c)
		return (str);
	return (NULL);
}
