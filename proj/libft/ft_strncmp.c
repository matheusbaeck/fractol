/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:59:00 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/02/08 21:59:19 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	if (n <= 0)
	{
		return (0);
	}
	index = 0;
	while (s1[index] && s2[index] && s1[index] == s2[index]
		&& index < (n - 1))
		index++;
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
