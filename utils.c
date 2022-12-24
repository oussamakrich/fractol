/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:56:41 by okrich            #+#    #+#             */
/*   Updated: 2022/12/24 20:06:00 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_exit(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}

int	ft_do(int key, t_mlx *mlx)
{
	if (key == 53)
		ft_exit(mlx);
	return(0);
}

void	put_pixel_to_img(t_data data, int x, int y, int color)
{
	char *dst;

	dst = data.addr + (y * data.line_length + x * (data.bits_per_pixel / 8));
	*dst = color;
}
