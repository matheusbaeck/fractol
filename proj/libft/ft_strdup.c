/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:30:07 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/02/08 18:29:33 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*s2;

	len = ft_strlen(s1);
	s2 = malloc((int)(len + 1) * sizeof(char));
	if (!(s2))
		return (0);
	i = 0;
	while (i <= len)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
