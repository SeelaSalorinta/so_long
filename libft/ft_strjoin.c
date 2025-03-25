/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:19:58 by ssalorin          #+#    #+#             */
/*   Updated: 2024/10/05 16:26:38 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	x;

	i = ft_strlen(s1);
	x = ft_strlen(s2);
	new = malloc(sizeof(char) * (i + x + 1));
	if (!new)
		return (NULL);
	i = 0;
	x = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[x])
	{
		new[i] = s2[x];
		i++;
		x++;
	}
	new[i] = '\0';
	return (new);
}
