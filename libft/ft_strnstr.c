/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:26:45 by ssalorin          #+#    #+#             */
/*   Updated: 2024/04/19 09:53:50 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	if (needle[b] == '\0')
	{
		return ((char *)haystack);
	}
	while (haystack[a] && a < len)
	{
		while (haystack[a + b] == needle[b] && haystack[a + b] && (a + b) < len)
		{
			if (needle[b + 1] == '\0')
			{
				return ((char *)haystack + a);
			}
			b++;
		}
		a++;
		b = 0;
	}
	return (0);
}
