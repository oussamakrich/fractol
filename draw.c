/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:34:53 by okrich            #+#    #+#             */
/*   Updated: 2022/12/27 19:14:14 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	color = get_color(n);
	return (color);
}

int	render(t_mlx *mlx)
{
	int x;
	int y;
	int	color;
	double xx;
	double yy;
		
	x = 0;
	while (x <= WIDTH)
	{
		y = 0;
		while (y <= HEIGHT)
		{
			xx = map(x , 0, WIDTH , -2 + mlx->mv_x  ,2 + mlx->mv_x );
			yy = map(y , 0, HEIGHT , -2 + mlx->mv_y, 2 + mlx->mv_y  );
			if (mlx->param == 'm')
				color = color_at(xx, yy, xx , yy);
			else                   
				color = color_at(xx, yy, mlx->xj , mlx->yj);
			put_pixel_to_img(mlx->img, x, y, color);	
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->mlx_img, 0 , 0);
	return (1);
}
