/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:31:34 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/01/16 22:20:25 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			size_s2;
	unsigned int	i;
	char			*s2;

	i = 0;
	if (!s || !f)
		return (0);
	size_s2 = ft_strlen(s);
	s2 = malloc(sizeof(char) * (size_s2 + 1));
	if (!(s2))
		return (0);
	while (i < size_s2)
	{
		s2[i] = f(i, s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
