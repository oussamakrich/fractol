/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:08:01 by okrich            #+#    #+#             */
/*   Updated: 2022/12/27 19:17:16 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx_macos/mlx.h"
#include <stdlib.h>

int	init_cnct(t_mlx *mlx)
{
	//FIX : check NULL
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, HEIGHT, WIDTH, "fractol");
	mlx->mlx_img = mlx_new_image(mlx->mlx, HEIGHT, WIDTH);
	mlx->img.addr = mlx_get_data_addr(mlx->mlx_img, &mlx->img.bpp, &mlx->img.ll, &mlx->img.endian);
	return (0);
}


int	mouse_hook(int key, t_mlx *mlx)
{
	if (key == 5)
		zoom_in(&mlx);
	// else if (key == 5)
	// 	zoom_out(&mlx);
	// printf ("%d\n", key);
	return (0);
}

int	ft_atoi(char *str)
{
	int	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	int		param;

	// mlx = malloc(sizeof(t_mlx));
	param = check_param(av[1]);
	if (ac == 1 || param == 1)
	{
		ft_printf("the argument is invalid, you must chose :");
		ft_printf("\n\t1- julia\n\t2- mandelbort");
		return (0);
	}
	init_cnct(&mlx);
	// mlx.zome_in = 1;
	// mlx.zoom_out = 1;
	if (param == 3)
		mlx.param = 'm';
	else if (param == 2)
	{
		mlx.param = 'j';
		mlx.move = 0;
		mlx.mv_x = 0;
		mlx.mv_y = 0;
		mlx.xj = map(ft_atoi(av[2]) ,0 , 100, -2 + mlx.mv_x, 2 + mlx.mv_x);
		mlx.yj = map(ft_atoi(av[3]), 0, 100, -2 + mlx.mv_y, 2 + mlx.mv_y);
	}
	render(&mlx);
	mlx_hook(mlx.mlx_win,6,0,mouse_cord, &mlx);
	 mlx_mouse_hook(mlx.mlx_win, mouse_hook, &mlx);
	mlx_hook(mlx.mlx_win, 2, 0, ft_do, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0, ft_exit, &mlx);


	mlx_loop(mlx.mlx);
}
