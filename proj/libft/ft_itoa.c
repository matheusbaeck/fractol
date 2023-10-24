/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math42 <math42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:36:50 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/04/05 21:10:13 by math42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <string.h>

static int	ft_powten(int pow_n)
{
	int	n;

	n = 10;
	if (pow_n < 0)
		return (0);
	if (pow_n == 0)
		return (1);
	if (pow_n == 1)
		return (10);
	while (pow_n > 1)
	{
		n *= 10;
		pow_n--;
	}
	return (n);
}

static void	ft_inttoa(char *str, int n, size_t pow_n, int sign)
{
	size_t	str_i;
	char	append;
	int		pow;
	int		n_split;

	str_i = 0;
	if (n == 0)
		str[0] = '0';
	if (sign < 0)
		str_i++;
	while (pow_n > 0)
	{
		pow = ft_powten(pow_n - 1);
		n_split = ((n * sign) - ((n % (pow)) * sign));
		append = (n_split / (pow)) + '0';
		n = n - (n_split * sign);
		str[str_i] = (char)append;
		pow_n--;
		str_i++;
	}
	str[str_i] = '\0';
}

char	*ft_itoa(int n)
{
	size_t	pow_n;
	int		n_count;
	int		sign;
	char	*str;

	pow_n = 0;
	n_count = n;
	while (n_count != 0 && ++pow_n)
		n_count = n_count / 10;
	sign = 1;
	if (n <= 0)
	{
		sign = -1;
		str = malloc((pow_n + 2) * sizeof(char));
		if (!(str))
			return (0);
		str[0] = '-';
	}
	else
		str = malloc((pow_n + 1) * sizeof(char));
	if (!(str))
		return (0);
	ft_inttoa(str, n, pow_n, sign);
	return (str);
}
