/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:31:02 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/02/12 07:50:38 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;
	int	index;

	index = 0;
	sign = 1;
	num = 0;
	while (((str[index] >= 9 && str[index] <= 13)
			|| str[index] == 32)
		&& str[index])
		index++;
	if (str[index] == '+')
		index++;
	else if (str[index] == '-')
	{
		sign *= -1;
		index++;
	}
	while (ft_isdigit(str[index]))
	{
		num *= 10;
		num += (str[index] - '0');
		index++;
	}
	return (num * sign);
}
