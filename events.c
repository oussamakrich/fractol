/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:54:20 by okrich            #+#    #+#             */
/*   Updated: 2022/12/27 19:05:07 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_do(int key, t_mlx *mlx)
{
	if (key == 53)
		ft_exit(mlx);
	else if (key == 49)
		mlx->move = !mlx->move;
	else if (key == 124)
		mlx->mv_x += 0.1;
	else if (key == 123)
		mlx->mv_x -= 0.1;
	else if (key == 126)
		mlx->mv_y += 0.1;
	else if (key == 125)
		mlx->mv_y -= 0.1;
	render(mlx);
	return(0);
}

int	ft_exit(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}

int	mouse_cord(int x, int y, t_mlx *mlx)
{
	if (mlx->move == 1 && x < 500 && y < 500 && x > 0 && y > 0)
	{
		mlx->xj = map(x, 0, WIDTH, -2, 2);
		mlx->yj = map(y, 0, HEIGHT, -2, 2);
		render(mlx);
		return (1);
	}
	return (0);
}
