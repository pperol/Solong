/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:31:43 by pperol            #+#    #+#             */
/*   Updated: 2022/06/16 10:52:49 by pperol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(int i)
{
	write(1, "Error\n", 6);
	if (i == 0)
		exit (0);
	if (i == 1)
		write(1, "Bad map\n", 8);
	if (i == 2)
		write(1, "Map is missing\n", 15);
	if (i == 3)
		write(1, "Wrong number of arguments\n", 26);
	if (i == 4)
		write(1, "Fatal error\n", 13);
	if (i == 5)
		write(1, "is a directory\n", 15);
	if (i == 6)
		write(1, "is not rectangular\r", 19);
	if (i == 7)
		write(1, "map size is bigger than screen\r", 31);
	exit (0);
}

int	ft_check_rectangle(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n' && buf[i + 1] && buf[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_buf(char *buf)
{
	if (ft_strrchr(buf, 'C') == 0 || ft_strrchr(buf, 'E') == 0
		|| ft_strrchr(buf, 'P') == 0)
	{
		free(buf);
		return (1);
	}
	return (0);
}
