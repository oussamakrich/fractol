/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:54:20 by okrich            #+#    #+#             */
/*   Updated: 2023/01/01 13:00:00 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_move(t_mlx *mlx, int key)
{
	double	dr;
	double	di;

	dr = mlx->r_max - mlx->r_min;
	di = mlx->i_max - mlx->i_min;
	if (key == LEFT)
	{
		mlx->r_min -= dr * 0.5;
		mlx->r_max -= dr * 0.5;
	}
	else if (key == REIGHT)
	{
		mlx->r_min += dr * 0.5;
		mlx->r_max += dr * 0.5;
	}
	else if (key == UP)
	{
		mlx->i_min += di * 0.5;
		mlx->i_max += di * 0.5;
	}
	else if (key == DOWN)
	{
		mlx->i_min -= di * 0.5;
		mlx->i_max -= di * 0.5;
	}
}

int	ft_do(int key, t_mlx *mlx)
{
	if (key == ESC)
		ft_exit(mlx);
	else if (key == SPACE)
		mlx->move = !mlx->move;
	else if (key >= LEFT && key <= UP)
		ft_move(mlx, key);
	else if (key == S)
	{
		mlx->rng += 1;
		if (mlx->rng == 8)
			mlx->rng = 0;
	}
	render(mlx);
	return (0);
}

int	ft_exit(t_mlx *mlx)
{
	destroy_cnct(mlx);
	exit(0);
	return (0);
}

int	mouse_cord(int x, int y, t_mlx *mlx)
{
	mlx->mv_x = x;
	mlx->mv_y = y;
	if (mlx->move == 1 && x < WIDTH && y < HEIGHT && x > 0 && y > 0)
	{
		mlx->cr = map(x, WIDTH, mlx->r_min, mlx->r_max);
		mlx->ci = map(y, HEIGHT, mlx->i_min, mlx->i_max);
		render(mlx);
	}
	return (0);
}

int	mouse_hook(int key, int x, int y, t_mlx *mlx)
{
	double	xx;
	double	yy;

	x = mlx->mv_x;
	y = mlx->mv_y;
	xx = map(x, WIDTH, mlx->r_min, mlx->r_max);
	yy = map(y, HEIGHT, mlx->i_min, mlx->i_max);
	if (key == 5)
	{
		zoom_in(mlx, xx, yy);
		render(mlx);
	}
	if (key == 4)
	{
		zoom_out(mlx, xx, yy);
		render(mlx);
	}
	return (0);
}
