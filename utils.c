/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:56:41 by okrich            #+#    #+#             */
/*   Updated: 2022/12/28 19:19:22 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>


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

int	check_param(char *param, t_mlx *mlx)
{
	if (param == NULL)
		return (1);
	else if (ft_strcmp(param, "julia") == 0)
		mlx->param = 'j';
	else if (ft_strcmp(param, "mandelbrot") == 0)
		mlx->param = 'm';
	else if (ft_strcmp(param, "burning") == 0)
		mlx->param = 'b';
	else
		mlx->param = 'n';
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

void	print_err(void)
{
	ft_printf("the argument is invalid, you must chose :");
	ft_printf("\n\t1- julia\n\t2- manelbort\n\t3- burning ship");
}



