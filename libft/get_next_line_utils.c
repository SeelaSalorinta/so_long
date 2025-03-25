/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:02:32 by ssalorin          #+#    #+#             */
/*   Updated: 2024/12/04 15:14:33 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free(char **remainder)
{
	free(*remainder);
	*remainder = NULL;
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	mychar;
	int				i;

	mychar = c;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != mychar)
		i++;
	if (s[i] == mychar)
		return ((char *)s + i);
	return (0);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!dest || !src)
		return (NULL);
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
