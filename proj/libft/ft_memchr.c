/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:10:21 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/02/12 07:57:49 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	index;

	index = 0;
	if (n == 0)
		return (0);
	while (index < (n - 1)
		&& ((unsigned char *)s)[index] != (unsigned char)c)
	{
		index++;
	}
	s += index;
	if (*((unsigned char *)s) == (unsigned char)c)
		return ((void *)s);
	else
		return (0);
}
