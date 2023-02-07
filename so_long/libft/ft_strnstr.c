/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:42:06 by pperol            #+#    #+#             */
/*   Updated: 2022/03/15 08:50:43 by pperol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	init;
	size_t	i;
	size_t	j;

	init = 0;
	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] && init < len)
	{
		while (haystack[i] == needle[j] && (init + i) < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack + i - j);
			i++;
			j++;
		}
		i = 0;
		j = 0;
		haystack++;
		init++;
	}
	return (NULL);
}
