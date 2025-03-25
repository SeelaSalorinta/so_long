/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:58:19 by ssalorin          #+#    #+#             */
/*   Updated: 2024/05/09 12:00:47 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*s11;
	const char	*s22;

	i = 0;
	s11 = (const char *)s1;
	s22 = (const char *)s2;
	while (i < n)
	{
		if (s11[i] != s22[i])
			return (((unsigned char *)s11)[i] - ((unsigned char *)s22)[i]);
		i++;
	}
	return (0);
}
