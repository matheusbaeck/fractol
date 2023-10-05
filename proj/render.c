/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:32:28 by math42            #+#    #+#             */
/*   Updated: 2023/10/05 20:26:08 by mamagalh@st      ###   ########.fr       */
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

int hsv_to_rgb(int hue, int saturation, int value)
{
    double h = (double)hue / 60.0;
    double s = (double)saturation / 100.0;
    double v = (double)value / 100.0;
    double c = v * s;
    double x = c * (1 - fabs(fmod(h, 2) - 1));
    double m = v - c;
    double r, g, b;

    if (h >= 0 && h < 1)
	{
        r = c;
        g = x;
        b = 0;
    }
	else if (h >= 1 && h < 2)
	{
        r = x;
        g = c;
        b = 0;
    }
	else if (h >= 2 && h < 3)
	{
        r = 0;
        g = c;
        b = x;
    }
	else if (h >= 3 && h < 4)
	{
        r = 0;
        g = x;
        b = c;
    }
	else if (h >= 4 && h < 5)
	{
        r = x;
        g = 0;
        b = c;
    }
	else 
	{ // h >= 5 && h < 6
        r = c;
        g = 0;
        b = x;
    }

    int red = (int)((r + m) * 255.0);
    int green = (int)((g + m) * 255.0);
    int blue = (int)((b + m) * 255.0);

    return ((red << 16) | (green << 8) | blue);
}

int	render_mandelbrot(t_data *dt)
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
			mod = fnz(dt->frctl.z , xy, dt->frctl.resol, dt->frctl.pow);
			if (mod != 0)
				img_pix_put(&dt->img, i, j, hsv_to_rgb((mod * dt->frctl.colour_hue) % 360, dt->frctl.colour_saturation, dt->frctl.colour_value));
			else
				img_pix_put(&dt->img, i, j, 0);
		}
	}
	return (0);
}

int	render_axis(t_data *dt)
{
	double		xy[2];
	int			i;
	int			j;

	j = -1;
	while (++j < WINDOW_HEIGHT)
	{
		i = -1;
		while (++i < WINDOW_WIDTH)
		{
			dt->frctl.scale = set_xy(&dt->cart, xy, i, j);
			if ((xy[0] < 0 + dt->frctl.scale && xy[0] >= 0)
				|| (xy[1] < 0 + dt->frctl.scale && xy[1] >= 0))
				img_pix_put(&dt->img, i, j, RED_PIXEL);
			if (sqrt(pow(xy[0], 2) + pow(xy[1], 2)) < 2 + dt->frctl.scale
				&& sqrt(pow(xy[0], 2) + pow(xy[1], 2)) > 2)
				img_pix_put(&dt->img, i, j, RED_PIXEL);
		}
	}
	return (0);
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_mandelbrot(data);
	if (data->frctl.axis == 1)
		render_axis(data);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}
