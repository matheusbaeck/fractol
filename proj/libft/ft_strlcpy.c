/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math42 <math42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:51:24 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/09/10 13:39:02 by math42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize <= 0)
		return (ft_strlen(src));
	if (!(src[i]))
	{
		dst[i] = src[i];
		return (ft_strlen(dst));
	}
	while (i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
		if (!(src[i]))
		{
			dst[i] = '\0';
			return (ft_strlen(dst));
		}
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
