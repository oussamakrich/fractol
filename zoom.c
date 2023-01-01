/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:14:37 by okrich            #+#    #+#             */
/*   Updated: 2023/01/01 12:47:12 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_mlx *mlx, double xx, double yy)
{
	mlx->r_max += xx;
	mlx->r_min += xx;
	mlx->i_max += yy;
	mlx->i_min += yy;
	mlx->r_max *= 0.5;
	mlx->r_min *= 0.5;
	mlx->i_max *= 0.5;
	mlx->i_min *= 0.5;
	mlx->max_itr += 5;
}

void	zoom_out(t_mlx *mlx, double xx, double yy)
{
	mlx->r_max /= 0.5;
	mlx->r_min /= 0.5;
	mlx->i_max /= 0.5;
	mlx->i_min /= 0.5;
	mlx->r_max -= xx;
	mlx->r_min -= xx;
	mlx->i_max -= yy;
	mlx->i_min -= yy;
	mlx->max_itr -= 5;
}
