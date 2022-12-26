/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:34:53 by okrich            #+#    #+#             */
/*   Updated: 2022/12/26 20:20:45 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx_macos/mlx.h"
#include <stdlib.h>
#include <math.h>

double map(double	pnt, double	f1, double t1, double f2, double t2)
{
	double	x;
	double	step;

	step = (t2 - f2) / (t1 - f1); 
	x = f2 + (pnt - f2) * step;
	return (x);
}

int	get_color(int itr)
{
	int color;
	int shft;
	
	if (itr == 100)
		color = 0x000000;
	else if (itr < 2)
		color = 0xADEFD3;
	else 
	{
		shft = itr / 5;
		color = 0xA300FF >> shft | 0xADEFD3 << shft;

	}

	return (color);
}

int	color_at(double a, double b, double ca, double cb)
{
	int	n;
	double	zr;
	double	zi;
	int	color;

	n = 0;
	while (n < 100)
	{
		zr = (a * a) - (b * b) + ca;
		zi = 2 * a * b + cb;
		a = zr;
		b = zi;
		if (zr * zr + zi * zi > 4) 
			break ;
		n++;
	}
	// color = 0xffffff;
	// if (n == 100)
	// 	color = 0x000000;
	color = get_color(n);
	return (color);
}

int	render_mandel(t_mlx *mlx)
{
	int x;
	int y;
	int	color;
	double xx;
	double yy;
	t_img	img;
		
	x = 0;
	img.addr = mlx_get_data_addr(mlx->mlx_img, &img.bpp, &img.ll, &img.endian);
	while (x <= WIDTH)
	{
		y = 0;
		while (y <= HEIGHT)
		{
			xx = map(x, 0, WIDTH, -2, 2);
			yy = map(y, 0, HEIGHT, -2, 2);
			color = color_at(xx, yy, xx , yy);
			put_pixel_to_img(img, x, y, color);	
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->mlx_img, 0 , 0);
	return (1);
}


int	render_julia(t_mlx *mlx)
{
	int x;
	int y;
	int	color;
	double xx;
	double yy;
	t_img	img;
		
	x = 0;
	img.addr = mlx_get_data_addr(mlx->mlx_img, &img.bpp, &img.ll, &img.endian);
	while (x <= WIDTH)
	{
		y = 0;
		while (y <= HEIGHT)
		{
			xx = map(x, 0, WIDTH, -2, 2);
			yy = map(y, 0, HEIGHT, -2, 2);
			color = color_at(xx, yy, mlx->xj , mlx->yj);
			put_pixel_to_img(img, x, y, color);	
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->mlx_img, 0 , 0);
	return (1);
}
