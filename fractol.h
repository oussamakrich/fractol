/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:09:01 by okrich            #+#    #+#             */
/*   Updated: 2022/12/30 13:33:23 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <math.h>
# include <stdio.h>
#include <sys/_types/_ssize_t.h>
# include <unistd.h>
# include <stdlib.h>
# include "minilibx_macos/mlx.h"
# include <stdarg.h>

#define HEIGHT 800
#define WIDTH 800

typedef struct	s_data {
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}				t_img;

typedef struct win{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	char	param;
	double	cr;
	double	ci;
	double	mv_x;
	double	mv_y;
	int		move;
	ssize_t max_itr;
	int		rng;
	double	i_min;
	double  i_max;
	double	r_min;
	double  r_max;
	t_img	*img;
}t_mlx;

//FIX: dont pushhhhhhhhh
void my_ex();
//FIX: dontttt pusssssshhh
// utils :

void	ft_putchar(unsigned char c, int *count);
void	ft_putstr(char *str, int *count);

int	check_param(char *param, t_mlx *mlx);
int	ft_format(va_list ag, char c, int *count);
int	ft_printf(const char *s, ...);

int	ft_atoi(char *str);
void	print_err(void);

void	zoom_in();
void	zoom_out();

// draw :

int	render(t_mlx *mlx);
double map(int	pnt, int max, double f2, double t2);

// window && img :

void	destroy_cnct(t_mlx *mlx);

int	init_cnct(t_mlx *mlx);
void	put_pixel_to_img(t_img *data, int x, int y, int color);

// eventes :

int	mouse_cord(int x, int y, t_mlx *mlx);
int	ft_exit(t_mlx *mlx);
int	ft_do(int key, t_mlx *mlx);

#endif
