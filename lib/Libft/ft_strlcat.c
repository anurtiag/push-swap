/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 07:15:03 by anurtiag          #+#    #+#             */
/*   Updated: 2024/02/03 11:22:56 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_l;
	size_t	src_l;
	size_t	i;

	dst_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	i = dst_l;
	if (dst_l >= dstsize)
		return (dstsize + src_l);
	while (dst_l < dstsize - 1 && *src)
		*(dst + dst_l++) = *src++;
	*(dst + dst_l) = '\0';
	return (i + src_l);
}
