/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u2pct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:27:41 by pperol            #+#    #+#             */
/*   Updated: 2022/01/07 11:37:12 by pperol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(int c);
int		ft_putstr(const char *s);

int	ft_unbrlen(unsigned int nb)
{
	int		len;

	len = 0;
	while (nb > 9)
	{
		nb = nb / 10;
		len++;
	}
	len++;
	return (len);
}

char	*ft_uitoa(unsigned int nb)
{
	char	*num;
	int		i;
	int		len;

	i = 0;
	len = ft_unbrlen(nb);
	num = malloc(sizeof(char) * (len + 1));
	i = len - 1;
	num[len] = '\0';
	while (nb > 9)
	{
		num[i--] = nb % 10 + '0';
		nb /= 10;
	}
	num[i] = nb % 10 + '0';
	return (num);
}

int	ft_unsigned(unsigned int nb)
{
	char	*num;

	num = ft_uitoa(nb);
	ft_putstr(num);
	free(num);
	return (ft_unbrlen(nb));
}

int	ft_hexlen(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb > 15)
	{
		len++;
		nb /= 16;
	}
	len++;
	return (len);
}

int	ft_dec2hex(unsigned int nb, char format)
{
	int	len;

	len = ft_hexlen(nb);
	if (nb > 15)
	{
		ft_dec2hex(nb / 16, format);
		ft_dec2hex(nb % 16, format);
	}
	else if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		if (format == 'x')
			ft_putchar(nb - 10 + 'a');
		if (format == 'X')
			ft_putchar(nb - 10 + 'A');
	}
	return (len);
}
