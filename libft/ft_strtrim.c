/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:33:30 by ssalorin          #+#    #+#             */
/*   Updated: 2024/05/14 13:37:32 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_setstart(char const *s1, char const *set)
{
	int	i;
	int	x;
	int	counter;

	i = 0;
	x = 0;
	counter = 0;
	while (set[x] && s1[i])
	{
		if (set[x] == s1[i])
		{
			x = 0;
			counter++;
			i++;
		}
		else
			x++;
	}
	return (counter);
}

static int	ft_setend(char const *s1, char const *set)
{
	int	i;
	int	counter;
	int	s1l;

	i = 0;
	counter = 0;
	s1l = ft_strlen(s1) - 1;
	while (set[i] && s1l > 0)
	{
		if (set[i] == s1[s1l])
		{
			i = 0;
			counter++;
			s1l--;
		}
		else
			i++;
	}
	return (ft_strlen(s1) - counter);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		new_end;
	int		len;
	char	*trimmed;

	i = 0;
	start = ft_setstart(s1, set);
	new_end = ft_setend(s1, set) - start;
	len = 0;
	if (new_end > 0)
		len = new_end;
	trimmed = malloc(sizeof(char) * (len + 1));
	if (!trimmed)
		return (NULL);
	if (new_end != 0)
	{
		while (i < new_end)
			trimmed[i++] = s1[start++];
	}
	trimmed[i] = '\0';
	return (trimmed);
}
