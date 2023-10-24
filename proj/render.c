/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:32:28 by math42            #+#    #+#             */
/*   Updated: 2023/10/25 01:55:57 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_pix_put(t_img *img, int x, int y, unsigned int color)
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

double	set_xy(t_cartesian *cart, double *xy, int i, int j)
{
	double	scale;
	double	add;

	add = 0;
	if (WINDOW_HEIGHT < WINDOW_WIDTH)
		scale = (cart->yf - cart->yo) / WINDOW_HEIGHT;
	else
		scale = (cart->xf - cart->xo) / WINDOW_WIDTH;
	add = ((cart->xf - cart->xo) - (scale * WINDOW_WIDTH)) / 2;
	xy[0] = cart->xo + add + scale * i;
	add = ((cart->yf - cart->yo) - (scale * WINDOW_HEIGHT)) / 2;
	xy[1] = cart->yo + add + scale * j;
	return (scale);
}

int	fnz(double zo[2], double c[2], int n, int pow)
{
	double	z[2];
	double	temp[3];
	int		i;
	int		j;

	z[0] = zo[0];
	z[1] = zo[1];
	i = -1;
	while (++i < n && (z[0] * z[0]) + (z[1] * z[1]) < 4)
	{
		temp[0] = z[0];
		temp[1] = z[1];
		j = pow;
		while (--j >= 1)
		{
			temp[2] = z[0];
			z[0] = (z[0] * temp[0] - z[1] * temp[1]);
			z[1] = (temp[2] * temp[1]) + (temp[0] * z[1]);
		}
		z[0] += c[0];
		z[1] += c[1];
	}
	if (i < n)
		return (i);
	return (0);
}

int	render_fractol(t_data *dt)
{
	double		xy[2];
	int			mod;
	int			i;
	int			j;

	j = -1;
	while (++j < WINDOW_HEIGHT)
	{
		i = -1;
		while (++i < WINDOW_WIDTH)
		{
			dt->frctl.scale = set_xy(&dt->cart, xy, i, j);
			mod = fnz(dt->frctl.z, xy, dt->frctl.resol, dt->frctl.pow);
			if (mod != 0)
				img_pix_put(&dt->img, i, j,
					hsv_to_rgb((mod * dt->frctl.colour_hue) % 360,
						dt->frctl.colour_saturation, dt->frctl.colour_value));
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
	render_fractol(data);
	if (data->frctl.axis == 1)
		render_axis(data);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}
