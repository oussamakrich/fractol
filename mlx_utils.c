/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:18:59 by okrich            #+#    #+#             */
/*   Updated: 2022/12/28 19:22:07 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_cnct(t_mlx *mlx)
{
	//FIX : check NULL
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, HEIGHT, WIDTH, "fractol");
	mlx->mlx_img = mlx_new_image(mlx->mlx, HEIGHT, WIDTH);
	mlx->img->addr = mlx_get_data_addr(mlx->mlx_img, &mlx->img->bpp, &mlx->img->ll, &mlx->img->endian);
	return (0);
}

void	destroy_cnct(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->mlx_img);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	free(mlx->mlx);
	free(mlx->img);
	free(mlx);
}

void	put_pixel_to_img(t_img *data, int x, int y, int color)
{
	char	*dst;
	char	*prv;

	prv = dst;
	dst = data->addr + (y * data->ll + x * (data->bpp / 8));
	*(int *)dst = color;
}
