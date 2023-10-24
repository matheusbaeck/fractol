/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:10:34 by math42            #+#    #+#             */
/*   Updated: 2023/10/25 01:58:11 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_entry(int argc, char **argv)
{
	if (argc < 2)
		return (printf("Mandelbrot\nMandelbrot3\nJulia <param1> <param2>\n"),
			1);
	else if (argc == 2)
	{
		if (!(!ft_strncmp(argv[1], "Mandelbrot", 11)
				|| !ft_strncmp(argv[1], "Mandelbrot3", 12)
				|| !ft_strncmp(argv[1], "Julia", 6)))
			return (printf("Mandelbrot\nMandelbrot3\nJulia <param1> <param2>\n")
				, 1);
	}
	else if (argc != 4)
		return (printf("wrong entry\n\n"), 1);
	return (0);
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

void	set_hooks(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->win_ptr, 3, 0, &handle_hooks, data);
	mlx_mouse_hook(data->win_ptr, &handle_mouse_hooks, data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (get_entry(argc, argv) != 0)
		return (0);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, argv[1]);
	if (data.win_ptr == NULL)
		return (free(data.win_ptr), MLX_ERROR);
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	set_cartesian_plan(&data.cart, (t_cartesian){-2, 2, -3, 3, 4, 6});
	if (argc != 4)
		set_fractol(&data.frctl, (t_fractol){
		{0, 0}, {0, 0}, 3, 0.1, 0.1, 1, 0, 5, 80, 80, 0, 2});
	else
		set_fractol(&data.frctl, (t_fractol){
		{ft_atoi(argv[2]), ft_atoi(argv[3])},
		{0, 0}, 3, 0.1, 0.1, 1, 0, 5, 80, 80, 0, 2});
	set_hooks(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
