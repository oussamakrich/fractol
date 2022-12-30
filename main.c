/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:08:01 by okrich            #+#    #+#             */
/*   Updated: 2022/12/30 19:52:07 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//FIX: don't push
#include "minilibx_macos/mlx.h"
#include <stdlib.h>


int	mouse_hook(int key, int x, int y, t_mlx *mlx)
{
	double	pos_x;
	double	pos_y;
	double	r_range;
	double	i_range;

	printf(" i_min : %f i_max : %f\n",mlx->i_min, mlx->i_max);
	// i_range = fabs(mlx->i_max - mlx->i_min);
	// r_range = fabs(mlx->r_max - mlx->r_min);
	//
	// pos_x = map(x, WIDTH, mlx->r_min , mlx->r_max );
	// pos_y = map(y, HEIGHT, mlx->i_min, mlx->i_max );
	// mlx->i_min = pos_y - i_range / 2;
	// mlx->i_max = pos_y + i_range / 2;
	// mlx->r_min = pos_x - r_range / 2;
	// mlx->r_max = pos_x + r_range / 2;
	if (key == 5)
	{
		// mlx->i_min -= pos_y;
		// mlx->i_max -= pos_y;
		// mlx->r_min -= pos_x;
		// mlx->r_max -= pos_y;
		mlx->i_max *= 0.5;
		mlx->i_min *= 0.5;
		mlx->r_max *= 0.5;
		mlx->r_min *= 0.5;
		mlx->max_itr += 1;
		// render(mlx);
	}
	else if (key == 4)
	{	
		mlx->i_max /= 0.5;
		mlx->i_min /= 0.5;
		mlx->r_max /= 0.5;
		mlx->r_min /= 0.5;
		// mlx->i_min += pos_y;
		// mlx->i_max += pos_y;
		// mlx->r_min += pos_x;
		// mlx->r_max += pos_y;
		mlx->max_itr += 1;
		// render(mlx);
	}
	render(mlx);
	return (0);
}


void	init_value(t_mlx *mlx, int ac, char **av)
{
	mlx->move = 0;
	mlx->max_itr = 100;
	mlx->rng = 0;
	mlx->i_min = -2;
	mlx->i_max = 2;
	mlx->r_min = -2;
	mlx->r_max = 2;
	if (mlx->param == 'j' && ac <= 2)
	{
		destroy_cnct(mlx);
		print_err();
		exit(1);
	}
	else if (mlx->param == 'j')
	{
		mlx->cr = map(ft_atoi(av[2]), 100, mlx->r_min, mlx->r_max);
		mlx->ci = map(ft_atoi(av[3]), 100, mlx->i_min, mlx->i_max);
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
	init_value(mlx, ac, av);
	render(mlx);
	mlx_hook(mlx->mlx_win, 2, 0, ft_do, mlx);
	mlx_hook(mlx->mlx_win, 17, 0, ft_exit, mlx);
	mlx_mouse_hook(mlx->mlx_win, mouse_hook, mlx);
	if (mlx->param == 'j')
		mlx_hook(mlx->mlx_win ,6 , 0, mouse_cord, mlx);
	// atexit(my_ex);
	mlx_loop(mlx->mlx);
}
