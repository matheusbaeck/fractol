/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 00:31:06 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/10/25 00:53:53 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_variation_xy(t_data *data)
{
	data->cart.x_var = fabs(data->cart.xo - data->cart.xf);
	data->cart.y_var = fabs(data->cart.yo - data->cart.yf);
	if (data->cart.x_var < data->cart.y_var)
		data->cart.y_var = data->cart.x_var;
	else
		data->cart.x_var = data->cart.y_var;
}

int	handle_keypress(int keysym, t_data *data)
{
	get_variation_xy(data);
	if (keysym == XK_w || keysym == XK_Down)
	{
		data->cart.yo += data->cart.y_var * data->frctl.m_speed;
		data->cart.yf += data->cart.y_var * data->frctl.m_speed;
	}
	if (keysym == XK_s || keysym == XK_Up)
	{
		data->cart.yo -= data->cart.y_var * data->frctl.m_speed;
		data->cart.yf -= data->cart.y_var * data->frctl.m_speed;
	}
	if (keysym == XK_d || keysym == XK_Left)
	{
		data->cart.xo -= data->cart.x_var * data->frctl.m_speed;
		data->cart.xf -= data->cart.x_var * data->frctl.m_speed;
	}
	if (keysym == XK_Page_Down)
	{
		data->cart.xo -= data->cart.x_var * data->frctl.z_speed;
		data->cart.xf += data->cart.x_var * data->frctl.z_speed;
		data->cart.yo -= data->cart.y_var * data->frctl.z_speed;
		data->cart.yf += data->cart.y_var * data->frctl.z_speed;
	}
	return (0);
}

int	handle_keypress_two(int keysym, t_data *data)
{
	get_variation_xy(data);
	if (keysym == XK_Page_Up)
	{
		data->cart.xo += data->cart.x_var * data->frctl.z_speed;
		data->cart.xf -= data->cart.x_var * data->frctl.z_speed;
		data->cart.yo += data->cart.y_var * data->frctl.z_speed;
		data->cart.yf -= data->cart.y_var * data->frctl.z_speed;
	}
	if (keysym == XK_c)
	{
		data->cart.xo = data->cart.x_var / 2;
		data->cart.xf = (data->cart.x_var / 2) * -1;
		data->cart.yo = data->cart.y_var / 2;
		data->cart.yf = (data->cart.y_var / 2) * (-1);
	}
	if (keysym == XK_space)
	{
		data->cart.xo = -2;
		data->cart.xf = 2;
		data->cart.yo = -3;
		data->cart.yf = 3;
	}
	return (0);
}

int	handle_keypress_three(int keysym, t_data *data)
{
	if (keysym == XK_k)
	{
		data->frctl.resol += 1;
		printf("resolution %d\n", data->frctl.resol);
	}
	if (keysym == XK_l)
	{
		data->frctl.resol -= 1;
		printf("resolution %d\n", data->frctl.resol);
	}
	if (keysym == XK_x)
	{
		data->frctl.axis = 1;
		data->frctl.click_alowed = 1;
	}
	if (keysym == XK_t)
	{
		data->frctl.colour_hue = (data->frctl.colour_hue + 1);
		printf("hue %i\n", data->frctl.colour_hue);
	}
	return (0);
}

int	handle_keypress_four(int keysym, t_data *data)
{
	if (keysym == XK_y)
	{
		if (data->frctl.colour_hue > 1)
			data->frctl.colour_hue = data->frctl.colour_hue - 1;
		else
			data->frctl.colour_hue = 0;
		printf("hue %i\n", data->frctl.colour_hue);
	}
	if (keysym == XK_u)
	{
		data->frctl.colour_saturation = (data->frctl.colour_saturation
				+ 1) % 100;
		printf("saturation %i\n", data->frctl.colour_saturation);
	}
	if (keysym == XK_i)
	{
		if (data->frctl.colour_saturation > 1)
			data->frctl.colour_saturation = (data->frctl.colour_saturation - 1);
		else
			data->frctl.colour_saturation = 100;
		printf("saturation %i\n", data->frctl.colour_saturation);
	}
	return (0);
}
