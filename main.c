/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:08:01 by okrich            #+#    #+#             */
/*   Updated: 2022/12/28 22:11:01 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx_macos/mlx.h"
#include <stdlib.h>


int	mouse_hook(int key, int x, int y, t_mlx *mlx)
{
	if (key == 5)
	{
		mlx->zome += 0.3;
		mlx->max_itr += 1;
		render(mlx);
	}
	else if (key == 4)
	{
		mlx->zome -= 0.3;
		mlx->max_itr += 1;
		render(mlx);
	}
	return (0);
}


void	init_value(t_mlx *mlx, char **av)
{
	mlx->move = 0;
	mlx->mv_x = 0;
	mlx->mv_y = 0;
	mlx->zome = 1;
	mlx->max_itr = 80;
	mlx->rng = 0;
	if (mlx->param == 'j')
	{
		mlx->cr = map(ft_atoi(av[2]), 100, -2 + mlx->mv_x, 2 + mlx->mv_x);
		mlx->ci = map(ft_atoi(av[3]), 100, -2 + mlx->mv_y, 2 + mlx->mv_y);
	}
}
void my_ex()
{
	system("leaks a.out");
}

int	main(int ac, char **av)
{
	t_mlx	*mlx;
	int		param;

	mlx = malloc(sizeof(t_mlx));
	mlx->img = malloc(sizeof(t_img));
	param = check_param(av[1], mlx);
	if (ac == 1 || mlx->param == 'n')
		return (free(mlx->img), free(mlx), print_err(), 0);
	init_cnct(mlx);
	init_value(mlx, av);
	render(mlx);
	mlx_hook(mlx->mlx_win, 2, 0, ft_do, mlx);
	mlx_hook(mlx->mlx_win, 17, 0, ft_exit, mlx);
	mlx_mouse_hook(mlx->mlx_win, mouse_hook, mlx);
	if (mlx->param == 'j')
		mlx_hook(mlx->mlx_win,6,0,mouse_cord, mlx);
	mlx_loop(mlx->mlx);
}
