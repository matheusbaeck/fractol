/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_TWO.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 00:31:06 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/10/25 01:02:34 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keypress_five(int keysym, t_data *data)
{
	if (keysym == XK_o)
	{
		data->frctl.colour_value = (data->frctl.colour_value + 1) % 100;
		printf("value %i\n", data->frctl.colour_value);
	}
	if (keysym == XK_p)
	{
		if (data->frctl.colour_value > 1)
			data->frctl.colour_value = (data->frctl.colour_value - 1);
		else
			data->frctl.colour_value = 100;
		printf("value %i\n", data->frctl.colour_value);
	}
	return (0);
}

int	handle_keypress_six(int keysym, t_data *data)
{
	if (keysym == XK_n)
	{
		if (data->frctl.pow > 1)
			data->frctl.pow = (data->frctl.pow - 1);
		else
			data->frctl.pow = 1;
		printf("fractol pow %i\n", data->frctl.pow);
	}
	if (keysym == XK_m)
	{
		data->frctl.pow = (data->frctl.pow + 1);
		printf("fractol pow %i\n", data->frctl.pow);
	}
	return (0);
}

int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		free(data->mlx_ptr);
		exit(0);
	}
	if (keysym == XK_x)
	{
		(*data).frctl.axis = 0;
		data->frctl.click_alowed = 0;
	}
	return (0);
}

int	handle_mouse(int button, int x, int y, t_data *data)
{
	double	balance;
	double	scale;

	data->cart.x_var = data->cart.xf - data->cart.xo;
	data->cart.y_var = data->cart.yf - data->cart.yo;
	if (button == 4)
	{
		scale = data->frctl.scale / (data->cart.x_var / (double) WINDOW_WIDTH);
		balance = ++x / (double) WINDOW_WIDTH;
		data->cart.xo -= data->cart.x_var
			* (*data).frctl.z_speed * balance * scale;
		data->cart.xf += data->cart.x_var
			* (*data).frctl.z_speed * (1 - balance) * scale;
		scale = data->frctl.scale / (data->cart.y_var / (double) WINDOW_HEIGHT);
		balance = ++y / (double) WINDOW_HEIGHT;
		data->cart.yo -= data->cart.y_var
			* (*data).frctl.z_speed * balance * scale;
		data->cart.yf += data->cart.y_var
			* (*data).frctl.z_speed * (1 - balance) * scale;
	}
	return (0);
}

int	handle_mouse_two(int button, int x, int y, t_data *data)
{
	double	balance;
	double	scale;

	data->cart.x_var = data->cart.xf - data->cart.xo;
	data->cart.y_var = data->cart.yf - data->cart.yo;
	if (button == 5)
	{
		scale = data->frctl.scale / (data->cart.x_var / (double) WINDOW_WIDTH);
		balance = ++x / (double) WINDOW_WIDTH;
		data->cart.xo += data->cart.x_var
			* (*data).frctl.z_speed * balance * scale;
		data->cart.xf -= data->cart.x_var
			* (*data).frctl.z_speed * (1 - balance) * scale;
		scale = data->frctl.scale / (data->cart.y_var / (double) WINDOW_HEIGHT);
		balance = ++y / (double) WINDOW_HEIGHT;
		data->cart.yo += data->cart.y_var
			* (*data).frctl.z_speed * balance * scale;
		data->cart.yf -= data->cart.y_var
			* (*data).frctl.z_speed * (1 - balance) * scale;
	}
	if (button == 1 && data->frctl.click_alowed)
		set_xy(&(data)->cart, data->frctl.z, x, y);
	return (0);
}
