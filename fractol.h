/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:09:01 by okrich            #+#    #+#             */
/*   Updated: 2022/12/22 13:49:18 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "minilibx_macos/mlx.h"
# include <stdarg.h>

#define HEIGHT 500
#define WIDTH 500

typedef struct win{
	void	*mlx;
	void	*mlx_win;
}t_mlx;

void	ft_putchar(unsigned char c, int *count);
void	ft_putstr(char *str, int *count);

int	ft_format(va_list ag, char c, int *count);
int	ft_printf(const char *s, ...);

int	check_param(char *param);
int	init_cnct(t_mlx *mlx, int height, int weight);

int	render(t_mlx *mlx, char *param);

#endif
