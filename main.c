/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:08:01 by okrich            #+#    #+#             */
/*   Updated: 2023/01/01 12:25:34 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;

	check_param(av[1], &mlx);
	if (ac == 1 || mlx.param == 'n')
		return (print_err(), 0);
	init_value(&mlx, ac, av);
	init_cnct(&mlx);
	render(&mlx);
	mlx_hook(mlx.mlx_win, ON_KEYPRESS, 0, ft_do, &mlx);
	mlx_hook(mlx.mlx_win, ON_DESTROY, 0, ft_exit, &mlx);
	mlx_hook(mlx.mlx_win, ON_MOUSEMOVE, 0, mouse_cord, &mlx);
	mlx_mouse_hook(mlx.mlx_win, mouse_hook, &mlx);
	mlx_loop(mlx.mlx);
}
