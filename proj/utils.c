/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 00:33:49 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/10/25 01:51:19 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_cartesian_plan(t_cartesian *cart, t_cartesian temp)
{
	*cart = temp;
}

void	set_fractol(t_fractol *frctl, t_fractol temp)
{
	*frctl = temp;
}

int	render_axis(t_data *dt)
{
	double	xy[2];
	int		i;
	int		j;

	j = -1;
	while (++j < WINDOW_HEIGHT)
	{
		i = -1;
		while (++i < WINDOW_WIDTH)
		{
			dt->frctl.scale = set_xy(&dt->cart, xy, i, j);
			if ((xy[0] < 0 + dt->frctl.scale && xy[0] >= 0) || (xy[1] < 0
					+ dt->frctl.scale && xy[1] >= 0))
				img_pix_put(&dt->img, i, j, RED_PIXEL);
			if (sqrt(pow(xy[0], 2) + pow(xy[1], 2)) < 2 + dt->frctl.scale
				&& sqrt(pow(xy[0], 2) + pow(xy[1], 2)) > 2)
				img_pix_put(&dt->img, i, j, RED_PIXEL);
		}
	}
	return (0);
}

int	handle_hooks(int keysym, t_data *data)
{
	handle_keypress(keysym, data);
	handle_keypress_two(keysym, data);
	handle_keypress_three(keysym, data);
	handle_keypress_four(keysym, data);
	handle_keypress_five(keysym, data);
	handle_keypress_six(keysym, data);
	handle_keyrelease(keysym, data);
	return (0);
}

int	handle_mouse_hooks(int button, int x, int y, t_data *data)
{
	handle_mouse(button, x, y, data);
	handle_mouse_two(button, x, y, data);
	return (0);
}