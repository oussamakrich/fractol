/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:18:59 by okrich            #+#    #+#             */
/*   Updated: 2022/12/31 22:46:51 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_cnct(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		exit(1);
	mlx->mlx_win = mlx_new_window(mlx->mlx, HEIGHT, WIDTH, "fractol");
	if (mlx->mlx_win == NULL)
		exit(1);
	mlx->mlx_img = mlx_new_image(mlx->mlx, HEIGHT, WIDTH);
	if (mlx->mlx_img == NULL)
	{
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		exit(1);
	}
	mlx->img.addr = mlx_get_data_addr(mlx->mlx_img, &mlx->img.bpp,
			&mlx->img.ll, &mlx->img.endian);
	return (0);
}

void	destroy_cnct(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->mlx_img);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
}

void	put_pixel_to_img(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->ll + x * (img->bpp / 8));
	*(int *)dst = color;
}

int	is_not_digit(char *str)
{
	if (*str == '+')
		str++;
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}
