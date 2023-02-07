/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr2di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:24:56 by pperol            #+#    #+#             */
/*   Updated: 2022/01/07 14:48:14 by pperol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(int c);
int		ft_putstr(const char *s);

int	ft_ptrlen(unsigned long nb)
{
	unsigned int	len;

	len = 0;
	while (nb > 15)
	{
		len++;
		nb = nb / 16;
	}
	return (len + 1);
}

int	ft_putptr(unsigned long nb)
{
	if (nb > 15)
	{
		ft_putptr(nb / 16);
		ft_putptr(nb % 16);
	}
	else
	{
		if (nb < 10)
			ft_putchar(nb + '0');
		else
			ft_putchar(nb - 10 + 'a');
	}
	return (ft_ptrlen(nb) + 2);
}

int	ft_nbrlen(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		len++;
		nb = -nb;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		len++;
	}
	len++;
	return (len);
}

int	ft_putnbr(int nb)
{
	int	len;

	len = ft_nbrlen(nb);
	if (nb == -2147483648)
		ft_putstr("-2147483648");
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb + '0');
	return (len);
}
