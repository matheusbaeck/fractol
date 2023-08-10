/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:21:34 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/02/17 00:01:00 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	char	un;

	if (nb != -2147483648)
	{
		if (nb >= 0)
		{
			un = (nb % 10) + '0';
			nb = (nb / 10);
			if (nb != 0)
				ft_putnbr_fd(nb, fd);
			write (fd, &un, 1);
		}
		else
		{
			write(fd, "-", 1);
			ft_putnbr_fd(nb * (-1), fd);
		}
	}
	else
		write(fd, "-2147483648", 11);
}
