/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:08:01 by okrich            #+#    #+#             */
/*   Updated: 2022/12/25 19:42:34 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx_macos/mlx.h"
#include <stdlib.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	check_param(char *param)
{
	if (param == NULL)
		return (1);
	else if (ft_strcmp(param, "julia") == 0)
		return (2);
	else if (ft_strcmp(param, "mandelbrot") == 0)
		return (3);
	return (1);
}


int	init_cnct(t_mlx *mlx)
{
	//FIX : check NULL
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, HEIGHT, WIDTH, "fractol");
	mlx->mlx_img = mlx_new_image(mlx->mlx, HEIGHT, WIDTH);
	return (0);
}


int	main(int ac, char **av)
{
	t_mlx	mlx;
	int		param;

	param = check_param(av[1]);
	if (ac != 2 || param == 1)
	{
		ft_printf("the argument is invalid, you must chose :");
		ft_printf("\n\t1- julia\n\t2- mandelbort");
		return (0);
	}
	init_cnct(&mlx);
	render(&mlx, av[1]);
	mlx_hook(mlx.mlx_win, 2, 0, ft_do, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0, ft_exit, &mlx);

	mlx_loop(mlx.mlx);
}
