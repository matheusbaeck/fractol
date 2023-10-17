/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:10:34 by math42            #+#    #+#             */
/*   Updated: 2023/10/05 20:32:13 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

int	handle_keypress(int keysym, t_data *data)
{
	(*data).cart.x_var = fabs((*data).cart.xo - (*data).cart.xf);
	(*data).cart.y_var = fabs((*data).cart.yo - (*data).cart.yf);
	if ((*data).cart.x_var < (*data).cart.y_var)
		(*data).cart.y_var = (*data).cart.x_var;
	else
		(*data).cart.x_var = (*data).cart.y_var;
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
	{
		(*data).frctl.axis = 1;
		data->frctl.click_alowed = 1;
	}
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
	if (keysym == XK_t)
	{
		data->frctl.colour_hue = (data->frctl.colour_hue + 1);
		printf("hue %i\n", data->frctl.colour_hue);
	}
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
		data->frctl.colour_saturation = (data->frctl.colour_saturation + 1) % 100;
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
	if (keysym == XK_n)
	{
		if (data->frctl.pow > 1)
			data->frctl.pow = (data->frctl.pow - 1);
		else
			data->frctl.pow = 1;
		printf("value %i\n", data->frctl.pow);
	}
	if (keysym == XK_m)
	{
		data->frctl.pow = (data->frctl.pow + 1);
		printf("value %i\n", data->frctl.pow);
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
	if (button == 1 && data->frctl.click_alowed)
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

int	get_entry(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	else if (argc == 2)
	{
		if (!(ft_strncmp(argv[1], "Mandelbrot", 11) || ft_strncmp(argv[1], "Mandelbrot3", 12) || ft_strncmp(argv[1], "Julia", 6)))
			return (printf("fractal not found, try one of the following \n\nMandelbrot\nMandelbrot3\n Julia <param1> <param2>\n"), 1);
	}
	else if (argc != 4)
		return (printf("wrong entry\n\n"), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!get_entry(arc, argv))
		return (0);
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
	if (argc != 4)
		set_freactol(&data.frctl, (t_fractol){{0, 0}, {0, 0}, 3, 0.1, 0.1, 1, 0, 5, 80, 80, 0, 2});
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, 2, 0, &handle_keypress, &data);
	mlx_hook(data.win_ptr, 3, 0, &handle_keyrelease, &data);
	mlx_mouse_hook(data.win_ptr, &handle_mouse, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
