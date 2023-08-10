/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:50:27 by marvin            #+#    #+#             */
/*   Updated: 2023/01/17 10:50:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			len;
	unsigned int	start;
	char			*s2;

	start = 0;
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && start < len)
		start += 1;
	if (start == len)
	{
		s2 = ft_calloc(1, sizeof(char));
		return (s2);
	}
	while (ft_strrchr(set, s1[len - 1]) && len > 0)
	{
		len -= 1;
	}
	len -= start;
	s2 = ft_substr(s1, start, len);
	return (s2);
}
