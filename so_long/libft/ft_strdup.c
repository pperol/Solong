/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperol <pperol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 08:50:16 by pperol            #+#    #+#             */
/*   Updated: 2021/12/10 15:17:34 by pperol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(s);
	dup = ft_calloc(1, size + 1);
	if (dup)
	{
		ft_memcpy(dup, s, size);
		return (dup);
	}
	return (0);
}
