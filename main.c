/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:08:01 by okrich            #+#    #+#             */
/*   Updated: 2022/12/26 21:36:43 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx_macos/mlx.h"
#include <stdlib.h>



struct moves mv;

int	init_cnct(t_mlx *mlx)
{
	//FIX : check NULL
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, HEIGHT, WIDTH, "fractol");
	mlx->mlx_img = mlx_new_image(mlx->mlx, HEIGHT, WIDTH);
	return (0);
}


int	ft_do(int key, t_mlx *mlx)
{
	if (key == 53)
		ft_exit(mlx);
	else if (key == 49)
		mv.move = !mv.move;
	return(0);
}

int	mouse_cord(int x, int y, t_mlx *mlx)
{
	static double	oxx;
	static double	oyy;

	if (mv.move == 1 && x < 500 && y < 500 && x > 0 && y > 0)
	{
		mlx->xj = map(x, 0, WIDTH, -2, 2);
		mlx->yj = map(y, 0, HEIGHT, -2, 2);
		oxx = mlx->xj;
		oyy = mlx->yj;
	}
	render_julia(mlx);
	return (1);
}

int	mouse_hook(int key, t_mlx *mlx)
{
	if (key == 4)
		zoom_in();
	else if (key == 5)
		zoom_out();
		
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

	param = check_param(av[1]);
	if (ac == 1 || param == 1)
	{
		ft_printf("the argument is invalid, you must chose :");
		ft_printf("\n\t1- julia\n\t2- mandelbort");
		return (0);
	}
	init_cnct(&mlx);
	if (param == 3)
		render_mandel(&mlx);
	else if (param == 2)
	{
		mlx.xj = map(ft_atoi(av[2]) ,0 , 100, -1 , 1);
		mlx.yj = map(ft_atoi(av[3]), 0, 100, -1, 1);
		render_julia(&mlx);
	}
	mlx_hook(mlx.mlx_win,6,0,mouse_cord, &mlx);
	mlx_mouse_hook(mlx.mlx_win, mouse_hook, &mlx);
	mlx_hook(mlx.mlx_win, 2, 0, ft_do, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0, ft_exit, &mlx);


	mlx_loop(mlx.mlx);
}
