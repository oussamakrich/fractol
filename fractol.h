/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:09:01 by okrich            #+#    #+#             */
/*   Updated: 2022/12/26 21:37:47 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "minilibx_macos/mlx.h"
# include <stdarg.h>

#define HEIGHT 500
#define WIDTH 500

struct moves 
{
	int move;
};

typedef struct win{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	double	xj;
	double	yj;
}t_mlx;

typedef struct	s_data {
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}				t_img;

void	ft_putchar(unsigned char c, int *count);
void	ft_putstr(char *str, int *count);

void	zoom_in();
void	zoom_out();
int	ft_format(va_list ag, char c, int *count);
int	ft_printf(const char *s, ...);

int	check_param(char *param);
int	init_cnct(t_mlx *mlx);

int	render_mandel(t_mlx *mlx);
int	render_julia(t_mlx *mlx);

double map(double	pnt, double	f1, double t1, double f2, double t2);


void	put_pixel_to_img(t_img data, int x, int y, int color);

int	ft_exit(t_mlx *mlx);
int	ft_do(int key, t_mlx *mlx);

#endif
