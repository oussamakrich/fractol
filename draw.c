/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:34:53 by okrich            #+#    #+#             */
/*   Updated: 2022/12/28 19:25:37 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>
#include <sys/_types/_ssize_t.h>

double map(int	pnt, int max, double r1, double r2)
{
	double	x;
	double	step;

	step = (r2 - r1) / max; 
	x = r1 + pnt * step;
	return (x);
}

int	*get_ref(void)
{
	int *ref;

	ref = malloc(sizeof(int) * 8);
	ref[0] = 0xADEFD3;
	ref[1] = 0xE6E6FA;
	ref[2] = 0x87CEEB;
	ref[3] = 0xFF7F50;
	ref[4] = 0xFA8072;
	ref[5] = 0x40E0D0;
	ref[6] = 0x98FB98;
	ref[7] = 0xFF69B4; 

	return (ref);
}

int	get_color(ssize_t itr, ssize_t max, int rng)
{
	int color;
	int shft;
	int	*ref;
	
	ref = get_ref(); 
	if (itr == max)
		color = 0x000000;
	else if (itr < 2)
		color = ref[rng];
	else 
	{
		shft = itr / 5;
		color = ref[rng] >> shft | (0xA300FF & ref[rng]) << shft;
	}
	free(ref);
	return (color);
}

// int	get_color(int itr)
// {
// 	int color;
// 	int shft;
// 	
// 	if (itr == 100)
// 		color = 0x000000;
// 	else if (itr < 2)
// 		color = 0xADEFD3;
// 	else 
// 	{
// 		shft = itr / 5;
// 		color = 0xA300FF >> shft | 0xADEFD3 << shft;
// 	}
//
// 	return (color);
// }

int	color_at(double a, double b, t_mlx *mlx)
{
	ssize_t n;
	double	zr;
	double	zi;
	int	color;

	n = 0;
	while (n < mlx->max_itr)
	{
		zr = (a * a) - (b * b) + mlx->cr;
		zi = 2 * a * b + mlx->ci;
		if (mlx->param == 'b')
			zi = 2 * fabs(a * b) + mlx->ci;
		a = zr;
		b = zi;
		if (zr * zr + zi * zi > 4) 
			break ;
		n++;
	}
	color = get_color(n, mlx->max_itr , mlx->rng);
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
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			xx = map(x , WIDTH * mlx->zome, -2 + mlx->mv_x , 2 + mlx->mv_x  );
			yy = map(y , HEIGHT * mlx->zome, -2 + mlx->mv_y , 2 + mlx->mv_y  );
			if (mlx->param == 'm' || mlx->param == 'b')
			{
				mlx->cr = xx;
				mlx->ci = yy;
				color = color_at(xx, yy, mlx);
			}
			else                   
				color = color_at(xx, yy, mlx);
			put_pixel_to_img(mlx->img, x, y, color);	
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->mlx_img, 0 , 0);
	return (1);
}
