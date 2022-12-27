/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:56:41 by okrich            #+#    #+#             */
/*   Updated: 2022/12/27 19:21:33 by okrich           ###   ########.fr       */
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




void	put_pixel_to_img(t_img data, int x, int y, int color)
{
	char	*dst;
	char	*prv;

	prv = dst;
	dst = data.addr + (y * data.ll + x * (data.bpp / 8));
	*(int *)dst = color;
}

void	zoom_in(t_mlx *mlx)
{
	 // printf("%f\n", mlx->zome_in);
	mlx->zome_in =  mlx->zome_in ;  	
	render(mlx);
}

// void	zoom_out(t_mlx *mlx)
// {
// 	// printf("out - %f\n", mlx->zome_in);
// 	mlx->zome_in = mlx->zome_in ;
// 	//render(mlx);
// }
