/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:21:01 by okrich            #+#    #+#             */
/*   Updated: 2022/12/31 22:30:35 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putchar(unsigned char c, int *count)
{
	int	i;

	i = write(1, &c, 1);
	if (i == -1)
		*count = -1;
	else
		*count = *count + 1;
}

void	ft_putstr(char *str, int *count)
{
	int	i;

	if (str == NULL)
		str = "(null)";
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], count);
		i++;
	}
}

int	ft_format(va_list ag, char c, int *count)
{
	if (c == '\0')
		return (1);
	else if (c == 'c')
		ft_putchar(va_arg(ag, int), count);
	else if (c == 's')
		ft_putstr(va_arg(ag, char *), count);
	else
		ft_putchar(c, count);
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	ag;

	i = 0;
	count = 0;
	va_start(ag, s);
	while (s[i])
	{
		if (s[i] != '%')
			ft_putchar(s[i], &count);
		else
		{
			i++;
			if (ft_format(ag, s[i], &count))
				break ;
		}
		i++;
	}
	va_end(ag);
	return (count);
}
