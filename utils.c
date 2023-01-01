/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:56:41 by okrich            #+#    #+#             */
/*   Updated: 2023/01/01 12:27:02 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	check_param(char *param, t_mlx *mlx)
{
	if (param == NULL)
		mlx->param = 'n';
	else if (ft_strcmp(param, "julia") == 0)
		mlx->param = 'j';
	else if (ft_strcmp(param, "mandelbrot") == 0)
		mlx->param = 'm';
	else if (ft_strcmp(param, "burning") == 0)
		mlx->param = 'b';
	else
		mlx->param = 'n';
}

int	ft_atoi(char *str)
{
	int	res;

	res = 0;
	if (*str == '-')
		return (-1);
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		if (res > 100)
			return (-1);
		str++;
	}
	return (res);
}

void	print_err(void)
{
	ft_printf("the argument is invalid, you must chose :\n\t");
	ft_printf("1- julia 0-100 0-100\n\t");
	ft_printf("2- manelbort\n\t3- burning");
	exit(1);
}

void	init_value(t_mlx *mlx, int ac, char **av)
{
	int	par1;
	int	par2;

	mlx->move = 0;
	mlx->max_itr = 100;
	mlx->rng = 0;
	mlx->i_min = -2;
	mlx->i_max = 2;
	mlx->r_min = -2;
	mlx->r_max = 2;
	mlx->mv_y = 0;
	mlx->mv_x = 0;
	if (mlx->param == 'j' && ac != 4)
		print_err();
	if (mlx->param == 'j' && (is_not_digit(av[2]) || is_not_digit(av[3])))
		print_err();
	else if (mlx->param == 'j')
	{
		par1 = ft_atoi(av[2]);
		par2 = ft_atoi(av[3]);
		if (par1 < 0 || par1 > 100 || par2 < 0 || par2 > 100)
			print_err();
		mlx->cr = map(par1, 100, mlx->r_min, mlx->r_max);
		mlx->ci = map(par2, 100, mlx->i_min, mlx->i_max);
	}
}
