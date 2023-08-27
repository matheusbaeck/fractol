/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math42 <math42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:10:34 by math42            #+#    #+#             */
/*   Updated: 2023/08/27 21:27:07 by math42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

int	handle_keypress(int keysym, t_data *data)
{
	(*data).cart.x_var = (*data).cart.xo - (*data).cart.xf;
	(*data).cart.y_var = (*data).cart.yo - (*data).cart.yf;
	if (keysym == XK_w || keysym == XK_Down)
	{
		(*data).cart.yo += (*data).cart.y_var * (*data).frctl.m_speed;
		(*data).cart.yf += (*data).cart.y_var * (*data).frctl.m_speed;
	}
	if (keysym == XK_s || keysym == XK_Up)
	{
		(*data).cart.yo -= (*data).cart.y_var * (*data).frctl.m_speed;
		(*data).cart.yf -= (*data).cart.y_var * (*data).frctl.m_speed;
	}
	if (keysym == XK_d || keysym == XK_Left)
	{
		(*data).cart.xo -= (*data).cart.x_var * (*data).frctl.m_speed;
		(*data).cart.xf -= (*data).cart.x_var * (*data).frctl.m_speed;
	}
	if (keysym == XK_a || keysym == XK_Right)
	{
		(*data).cart.xo += (*data).cart.x_var * (*data).frctl.m_speed;
		(*data).cart.xf += (*data).cart.x_var * (*data).frctl.m_speed;
	}
	if (keysym == XK_Page_Down)
	{
		(*data).cart.xo -= (*data).cart.x_var * (*data).frctl.z_speed;
		(*data).cart.xf += (*data).cart.x_var * (*data).frctl.z_speed;
		(*data).cart.yo -= (*data).cart.y_var * (*data).frctl.z_speed;
		(*data).cart.yf += (*data).cart.y_var * (*data).frctl.z_speed;
	}
	if (keysym == XK_Page_Up)
	{
		(*data).cart.xo += (*data).cart.x_var * (*data).frctl.z_speed;
		(*data).cart.xf -= (*data).cart.x_var * (*data).frctl.z_speed;
		(*data).cart.yo += (*data).cart.y_var * (*data).frctl.z_speed;
		(*data).cart.yf -= (*data).cart.y_var * (*data).frctl.z_speed;
	}
	if (keysym == XK_k)
	{
		(*data).frctl.resol += 1;
		printf("resolution %d\n", (*data).frctl.resol);
	}
	if (keysym == XK_l)
	{
		(*data).frctl.resol -= 1;
		printf("resolution %d\n", (*data).frctl.resol);
	}
	if (keysym == XK_x)
		(*data).frctl.axis = 1;
	if (keysym == XK_c)
	{
		(*data).cart.xo = (*data).cart.x_var / 2;
		(*data).cart.xf = ((*data).cart.x_var / 2) * -1;
		(*data).cart.yo = (*data).cart.y_var / 2;
		(*data).cart.yf = ((*data).cart.y_var / 2) * (-1);
	}
	if (keysym == XK_space)
	{
		(*data).cart.xo = -2;
		(*data).cart.xf = 2;
		(*data).cart.yo = -3;
		(*data).cart.yf = 3;
	}
	if (keysym == XK_p)
	{
		if (data->frctl.colour_range < __INT_MAX__ - 10)
			data->frctl.colour_range+= 10;
		else
			data->frctl.colour_add = 0;
	}
	if (keysym == XK_i)
	{
		if (data->frctl.colour_range < __INT_MAX__ / 2)
			data->frctl.colour_range*= 2;
		else
			data->frctl.colour_add = 1;
	}
	if (keysym == XK_o)
	{
		if (data->frctl.colour_add < __INT_MAX__ - 1)
			data->frctl.colour_add++;
		else
			data->frctl.colour_add = 0;
	}
	if (keysym == XK_u)
	{
		if (data->frctl.colour_add < __INT_MAX__ / 2)
			data->frctl.colour_add*= 2;
		else
			data->frctl.colour_add = 1;
	}
	return (0);
}

int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (keysym == XK_x)
	{
		(*data).frctl.axis = 0;
	}
	return (0);
}

int	handle_mouse(int button, int x, int y, t_data *data)
{
	double	balance;
	double	scale;

	(*data).cart.x_var = (*data).cart.xf - (*data).cart.xo;
	(*data).cart.y_var = (*data).cart.yf - (*data).cart.yo;
	if (button == 4)
	{
		scale = data->frctl.scale / ((*data).cart.x_var / (double) WINDOW_WIDTH);
		balance = ++x / (double) WINDOW_WIDTH;
		(*data).cart.xo -= (*data).cart.x_var * (*data).frctl.z_speed * balance * scale;
		(*data).cart.xf += (*data).cart.x_var * (*data).frctl.z_speed * (1 - balance) * scale;
		scale = data->frctl.scale / ((*data).cart.y_var / (double) WINDOW_HEIGHT);
		balance = ++y / (double) WINDOW_HEIGHT;
		(*data).cart.yo -= (*data).cart.y_var * (*data).frctl.z_speed * balance * scale;
		(*data).cart.yf += (*data).cart.y_var * (*data).frctl.z_speed * (1 - balance) * scale;
	}
	if (button == 5)
	{
		scale = data->frctl.scale / ((*data).cart.x_var / (double) WINDOW_WIDTH);
		balance = ++x / (double) WINDOW_WIDTH;
		(*data).cart.xo += (*data).cart.x_var * (*data).frctl.z_speed * balance * scale;
		(*data).cart.xf -= (*data).cart.x_var * (*data).frctl.z_speed * (1 - balance) * scale;
		scale = data->frctl.scale / ((*data).cart.y_var / (double) WINDOW_HEIGHT);
		balance = ++y / (double) WINDOW_HEIGHT;
		(*data).cart.yo += (*data).cart.y_var * (*data).frctl.z_speed * balance * scale;
		(*data).cart.yf -= (*data).cart.y_var * (*data).frctl.z_speed * (1 - balance) * scale;
	}
	if (button == 1)
	{
		set_xy(&(data)->cart, data->frctl.z, x, y);
	}
	return (0);
}

void	set_cartesian_plan(t_cartesian *cart, t_cartesian temp)
{
	*cart = temp;
}

void	set_freactol(t_fractol *frctl, t_fractol temp)
{
	*frctl = temp;
}

int	init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "my window");
	if (data->win_ptr == NULL)
		return (free(data->win_ptr), MLX_ERROR);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr,
		WINDOW_WIDTH, WINDOW_HEIGHT, "my window");
	if (data.win_ptr == NULL)
		return (free(data.win_ptr), MLX_ERROR);
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	set_cartesian_plan(&data.cart, (t_cartesian){-2, 2, -3, 3, 4, 6});
	set_freactol(&data.frctl, (t_fractol){{0, 0}, {0, 0}, 3, 0.1, 0.1, 1, 0, 100, 0});
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
	mlx_mouse_hook(data.win_ptr, &handle_mouse, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
