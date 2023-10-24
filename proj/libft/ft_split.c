/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 02:27:30 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/02/12 02:27:30 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_piece_split(const char *s, size_t start, int c)
{
	unsigned int	len_piece;
	char			*str;

	len_piece = 0;
	while (((unsigned char)s[len_piece + start])
		&& ((unsigned char)s[len_piece + start]) != ((unsigned char) c))
		len_piece++;
	str = ft_calloc((len_piece + 1), sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, &s[start], len_piece + 1);
	return (str);
}

static unsigned int	ft_count_split(const char *s, int c)
{
	unsigned int	selector;
	unsigned int	count;
	unsigned int	index;

	index = 0;
	count = 0;
	selector = 0;
	while (s[index])
	{
		if (((unsigned char) s[index]) == ((unsigned char) c))
			selector = 0;
		else
		{
			if (selector == 0)
				count++;
			selector++;
		}
		index++;
	}
	return (count);
}

static int	ft_free(char **str, unsigned int count)
{
	while (--count > 1)
		free(str[count]);
	free(str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char			**str;
	unsigned int	index;
	unsigned int	count;

	str = (char **)ft_calloc(ft_count_split(s, c) + 1, sizeof(char *));
	if (!str)
		return (0);
	count = 0;
	index = 0;
	while (s[index])
	{
		if (s[index] == c)
			index++;
		else
		{
			str[count] = ft_piece_split(s, index, c);
			if (!(str[count]) && !(ft_free(str, count)))
				return (0);
			index += ft_strlen(str[count]);
			count++;
		}
	}
	return (str);
}
