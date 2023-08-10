/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:47:27 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/02/11 19:23:05 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (((unsigned char)s[i]))
	{
		if (((unsigned char)s[i]) == ((unsigned char) c))
		{
			s += i;
			i = 1;
		}
		else
			i++;
	}
	if ((unsigned char)c == '\0')
		s += i;
	if (*s != (unsigned char)c)
		return (0);
	return ((char *) s);
}
