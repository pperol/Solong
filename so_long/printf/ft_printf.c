/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:16:22 by pperol            #+#    #+#             */
/*   Updated: 2022/01/07 14:55:45 by pperol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(int c);
int		ft_putstr(const char *s);
int		ft_ptrlen(unsigned long nb);
int		ft_putptr(unsigned long nb);
int		ft_nbrlen(int nb);
int		ft_putnbr(int nb);
int		ft_unbrlen(unsigned int nb);
char	*ft_uitoa(unsigned int nb);
int		ft_unsigned(unsigned int nb);
int		ft_hexlen(unsigned int nb);
int		ft_dec2hex(unsigned int nb, char format);

int	ft_format(const char format, va_list args)
{
	int	ret;

	ret = 0;
	if (format == 'c')
		ret = ft_putchar(va_arg(args, int));
	else if (format == 's')
		ret = ft_putstr(va_arg(args, const char *));
	else if (format == 'p')
	{
		ft_putstr("0x");
		ret = ft_putptr(va_arg(args, unsigned long));
	}	
	else if (format == 'd' || format == 'i')
		ret = ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		ret = ft_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		ret = ft_dec2hex(va_arg(args, int), 'x');
	else if (format == 'X')
		ret = ft_dec2hex(va_arg(args, int), 'X');
	else if (format == '%')
		ret = ft_putchar('%');
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	ret;

	va_list(args);
	i = 0;
	ret = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ret += ft_format(str[i + 1], args);
			i++;
		}
		else
			ret += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (ret);
}
