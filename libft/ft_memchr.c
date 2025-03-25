/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:11:00 by ssalorin          #+#    #+#             */
/*   Updated: 2024/05/08 17:49:36 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		mychar;
	const char	*s2;

	i = 0;
	mychar = c;
	s2 = (const char *)s;
	while (i < n)
	{
		if (s2[i] == mychar)
			return ((void *)s2 + i);
		i++;
	}
	return (0);
}
