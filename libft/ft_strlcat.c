/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:14:36 by ssalorin          #+#    #+#             */
/*   Updated: 2024/04/17 14:00:41 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	x;
	size_t	i;

	x = ft_strlen(dst);
	i = 0;
	if (x > dstsize)
		return (ft_strlen(src) + dstsize);
	if (dstsize != 0 && x < dstsize)
	{
		while (i < (dstsize - x - 1) && src[i])
		{
			dst[x + i] = src[i];
			i++;
		}
		dst[x + i] = '\0';
	}
	while (src[i])
		i++;
	return (i + x);
}
