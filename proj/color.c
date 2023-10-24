/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 01:46:45 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/10/25 01:50:11 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_rgb(t_color *color)
{
	if (color->h >= 0 && color->h < 1)
	{
		color->r = color->c;
		color->g = color->x;
		color->b = 0;
	}
	if (color->h >= 1 && color->h < 2)
	{
		color->r = color->x;
		color->g = color->c;
		color->b = 0;
	}
	else if (color->h >= 2 && color->h < 3)
	{
		color->r = 0;
		color->g = color->c;
		color->b = color->x;
	}
}

void	get_rgb_two(t_color *color)
{
	if (color->h >= 3 && color->h < 4)
	{
		color->r = 0;
		color->g = color->x;
		color->b = color->c;
	}
	else if (color->h >= 4 && color->h < 5)
	{
		color->r = color->x;
		color->g = 0;
		color->b = color->c;
	}
	else
	{ // h >= 5 && h < 6
		color->r = color->c;
		color->g = 0;
		color->b = color->x;
	}
}

int	hsv_to_rgb(int hue, int saturation, int value)
{
	t_color	color;
	int		red;
	int		green;
	int		blue;

	color.h = (double)hue / 60.0;
	color.s = (double)saturation / 100.0;
	color.v = (double)value / 100.0;
	color.c = color.v * color.s;
	color.x = color.c * (1 - fabs(fmod(color.h, 2) - 1));
	color.m = color.v - color.c;
	if (color.h < 3)
		get_rgb(&color);
	else
		get_rgb_two(&color);
	red = (int)((color.r + color.m) * 255.0);
	green = (int)((color.g + color.m) * 255.0);
	blue = (int)((color.b + color.m) * 255.0);
	return ((color.red << 16) | (color.green << 8) | color.blue);
}