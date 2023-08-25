/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math42 <math42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:32:28 by math42            #+#    #+#             */
/*   Updated: 2023/08/25 14:56:19 by math42           ###   ########.fr       */
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

void	set_xy(t_cartesian *cart, double *xy, int i, int j)
{
	double	a;
	double	b;

	a = (cart->xf - cart->xo) / WINDOW_WIDTH;
	b = (cart->yf - cart->yo) / WINDOW_HEIGHT;
	xy[0] = cart->xo + a * i;
	xy[1] = cart->yo + b * j;
}

int	render_mandelbrot(t_data *dt)
{
	double		xy[2];
	double		mod;
	int			i;
	int			j;

	j = -1;
	while (++j < WINDOW_HEIGHT)
	{
		i = -1;
		while (++i < WINDOW_WIDTH)
		{
			set_xy(&dt->cart, xy, i, j);
			if (sqrt(pow(xy[0], 2) + pow(xy[1], 2)) < 2)
			{
				mod = fnz((double [2]){0, 0}, xy, 16);
				if (mod != 0)
					img_pix_put(&dt->img, i, j, ((int)mod) * 100);
				else
					img_pix_put(&dt->img, i, j, 0);
			}
			else
				img_pix_put(&dt->img, i, j, 0);
		}
	}
	return (0);
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_mandelbrot(data);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->img.mlx_img, 0, 0);

	return (0);
}
