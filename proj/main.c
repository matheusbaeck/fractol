/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math42 <math42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:10:34 by math42            #+#    #+#             */
/*   Updated: 2023/08/25 15:09:27 by math42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

int	handle_keypress(int keysym, t_data *data)
{
	double zoom_speed = 0.1;
	double move_speed = 0.1;
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
    if (keysym == XK_w | keysym == XK_Up)
    {
		(*data).cart.yo += ((*data).cart.yo - (*data).cart.yf) * move_speed;
		(*data).cart.yf += ((*data).cart.yo - (*data).cart.yf) * move_speed;
    }
	if (keysym == XK_s | keysym == XK_Down)
    {
		(*data).cart.yo -= ((*data).cart.yo - (*data).cart.yf) * move_speed;
		(*data).cart.yf -= ((*data).cart.yo - (*data).cart.yf) * move_speed;
    }
	if (keysym == XK_d | keysym == XK_Left)
    {
		(*data).cart.xo += ((*data).cart.xo - (*data).cart.xf) * move_speed;
		(*data).cart.xf += ((*data).cart.xo - (*data).cart.xf) * move_speed;
    }
	if (keysym == XK_a | keysym == XK_Right)
    {
		(*data).cart.xo -= ((*data).cart.xo - (*data).cart.xf) * move_speed;
		(*data).cart.xf -= ((*data).cart.xo - (*data).cart.xf) * move_speed;
    }
	if (keysym == XK_Page_Down)
    {
		(*data).cart.xo -= ((*data).cart.xo - (*data).cart.xf) * zoom_speed;
		(*data).cart.xf += ((*data).cart.xo - (*data).cart.xf) * zoom_speed;
		(*data).cart.yo -= ((*data).cart.yo - (*data).cart.yf) * zoom_speed;
		(*data).cart.yf += ((*data).cart.yo - (*data).cart.yf) * zoom_speed;
    }
	if (keysym == XK_Page_Up)
    {
		(*data).cart.xo += ((*data).cart.xo - (*data).cart.xf) * 0.1;
		(*data).cart.xf -= ((*data).cart.xo - (*data).cart.xf) * 0.1;
		(*data).cart.yo += ((*data).cart.yo - (*data).cart.yf) * 0.1;
		(*data).cart.yf -= ((*data).cart.yo - (*data).cart.yf) * 0.1;
    }
	return (0);
}

void	set_cartesian_plan(t_cartesian *cart, t_cartesian temp)
{
	*cart = temp;
}

int	init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "my window");
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
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "my window");
	if (data.win_ptr == NULL)
		return (free(data.win_ptr), MLX_ERROR);

	/* Setup hooks */ 
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	set_cartesian_plan(&data.cart, (t_cartesian){-2, 2, -3, 3});

	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);

	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
