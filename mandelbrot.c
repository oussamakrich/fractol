/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:34:53 by okrich            #+#    #+#             */
/*   Updated: 2022/12/22 13:25:13 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx_macos/mlx.h"
#include <stdlib.h>
#include <math.h>

double map(double	p, double	f1, double t1, double f2, double t2)
{
	double x;

	x = f2 + (p - f1) * ((t2 - f2) / (t1 - f1));
	return (x);
}

int	color_at(double a, double b)
{
	int	n;
	double	ab;
	double	abi;
	double	ca;
	double	cb;
	int	color;

	ca = a;
	cb = b;
	n = 0;
	while (n < 100)
	{
		ab = (a * a) - (b * b);
		abi = 2 * a * b;
		a = ab + ca;
		b = abi + cb;
		if ((a * a) + (b * b) > 4)
			break ;
		n++;
	}
	color = 0x000000;
	if (n == 100)
		color = 0xffffff;
	return (color);
}

int	render(t_mlx *mlx)
{
	int x;
	int y;
		
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			double xx = map(x, 0, WIDTH, -2, 2);
			double yy = map(y, 0, HEIGHT, -2, 2);
			int color = color_at(xx, yy);
			mlx_pixel_put(mlx->mlx, mlx->mlx_win, x, y, color);
			y++;
		}
		x++;
	}
	return 1;
}
