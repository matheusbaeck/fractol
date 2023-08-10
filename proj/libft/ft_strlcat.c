/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:49:35 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/02/28 18:51:41 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	start;

	i = 0;
	start = ft_strlen(dst);
	if (dstsize <= 0)
		return (ft_strlen(src) + dstsize);
	while (start + i < (dstsize - 1))
	{
		dst[start + i] = src[i];
		i++;
		if (!(src[i]))
		{
			dst[start + i] = src[i];
			return (ft_strlen(dst));
		}
	}
	if ((start + i) < dstsize)
		dst[start + i] = '\0';
	if (start > dstsize)
		return (ft_strlen(src) + dstsize);
	return (ft_strlen(src) + start);
}
