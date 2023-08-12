/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math42 <math42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:32:28 by math42            #+#    #+#             */
/*   Updated: 2023/08/12 17:35:35 by math42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

double	fnz(double z[2], double c[2], int n)
{
	int		i;
	double	temp;
	double	mod;

	mod = sqrt(pow(z[0], 2) + pow(z[1], 2));
	i = -1;
	while (++i < n && mod < 2)
	{
		temp = z[0];
		z[0] = (pow(z[0], 2) - pow(z[1], 2)) + c[0];
		z[1] = (2 * temp * z[1]) + c[1];
		mod = sqrt(pow(z[0], 2) + pow(z[1], 2));
	}
	if (i < n)
	{
		return (mod + 1);
	}
	return (0);
}

int	render_mandelbrot(t_img *img)
{
	int		i;
	int		j;
	double	x;
	double	y;
	double	c[2];
	double	z[2];
	double	temp;

	j = 0;
	while (j < WINDOW_WIDTH)
	{
		y = ((double) 4 / WINDOW_HEIGHT) * ((WINDOW_HEIGHT / 2) - j);
		i = 0;
		while (i < WINDOW_HEIGHT)
		{
			x = ((double) 6 / WINDOW_WIDTH) * (i - (WINDOW_WIDTH / 2));
			c[0] = x;
			c[1] = y;
			z[0] = 0;
			z[1] = 0;
			if (sqrt(pow(c[0], 2) + pow(c[1], 2)) < 2) //fnz(1, c, 100) == 0
			{
				temp = fnz(z, c, 256);
				if (temp != 0)
					img_pix_put(img, i, j, 10 * pow((int)(temp * 100), 2));
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_mandelbrot(&data->img);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->img.mlx_img, 0, 0);

	return (0);
}
