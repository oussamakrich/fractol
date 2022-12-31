/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:09:01 by okrich            #+#    #+#             */
/*   Updated: 2022/12/31 22:39:56 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <mlx.h>

# define HEIGHT 800
# define WIDTH 800

# define ON_KEYPRESS 2
# define ON_MOUSEMOVE 6
# define ON_DESTROY 17
# define ESC 53
# define SPACE 49
# define LEFT 123
# define REIGHT 124
# define UP 126 
# define DOWN 125
# define SCROLL_UP 4 
# define SCROLL_DOWN 5
# define S 1

typedef struct s_data {
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
	int		mv_x;
	int		mv_y;
	int		move;
	int		max_itr;
	int		rng;
	double	i_min;
	double	i_max;
	double	r_min;
	double	r_max;
	int		i;
	t_img	img;
}t_mlx;

void	ft_putchar(unsigned char c, int *count);
void	ft_putstr(char *str, int *count);
void	init_value(t_mlx *mlx, int ac, char **av);
void	check_param(char *param, t_mlx *mlx);

int		is_not_digit(char *str);
int		ft_format(va_list ag, char c, int *count);
int		ft_printf(const char *s, ...);
int		ft_atoi(char *str);

void	print_err(void);
void	zoom_in(t_mlx *mlx, double xx, double yy);
void	zoom_out(t_mlx *mlx, double xx, double yy);
void	render(t_mlx *mlx);
void	destroy_cnct(t_mlx *mlx);
void	put_pixel_to_img(t_img *data, int x, int y, int color);

double	map(int pnt, int screen, double min, double max);

int		init_cnct(t_mlx *mlx);
int		mouse_hook(int key, int x, int y, t_mlx *mlx);
int		mouse_cord(int x, int y, t_mlx *mlx);
int		ft_exit(t_mlx *mlx);
int		ft_do(int key, t_mlx *mlx);

#endif
