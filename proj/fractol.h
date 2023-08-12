/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math42 <math42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 02:00:26 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/08/12 23:14:20 by math42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 400

enum	e_main_errors {
	// MAIN
	MLX_ERROR = 1,
	EXEC_FAIL = 3,
	// INIT_ALL
	FEW_ARGUMENTS = 11,
	MALLOC_FAIL_PARENT = 21,
	// INIT_PIPES
	MALLOC_FAIL_PTRCHILD = 131,
	MALLOC_FAIL_CHILD = 232,
	OPEN_PIPE = 332,
	OPEN_FILE = 432
};

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		cur_img;
}	t_data;

typedef struct s_cartesian	
{
	double	xo;
	double	xf;
	double	yo;
	double	yf;
	double	xy[2];
}	t_cartesian;

typedef struct s_fractol
{
	t_cartesian	cart;
	int			i;
	int			j;
}	t_fractol;

//RENDER
void	img_pix_put(t_img *img, int x, int y, int color);
double	fnz(double z[2], double c[2], int n);
int		render_mandelbrot(t_img *img, t_fractol ft);
int		render(t_data *data);

#endif
