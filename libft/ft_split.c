/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:43:59 by ssalorin          #+#    #+#             */
/*   Updated: 2024/12/30 15:17:27 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_stra(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else if (s[i] == c)
			i++;
	}
	return (count);
}

static void	ft_copy(char **strings, char const *s, int len, int x)
{
	int	i;

	i = 0;
	while (i < len)
	{
		strings[x][i] = s[i];
		i++;
	}
	strings[x][i] = '\0';
}

static void	*ft_free_array(char **strings, int x)
{
	while (x >= 0)
	{
		free(strings[x]);
		x--;
	}
	free(strings);
	return (NULL);
}

static char	**ft_mal(char **strings, char const *s, char c, int i)
{
	int	len;
	int	x;

	len = 0;
	x = 0;
	while (s[i] && x < ft_stra(s, c))
	{
		while (s[i + len] && s[i + len] != c)
			len++;
		if (len != 0)
		{
			strings[x] = (char *)malloc(sizeof(char) * (len + 1));
			if (!strings[x])
				return (ft_free_array(strings, x));
			ft_copy(strings, &s[i], len, x);
			x++;
			i = i + len;
			len = 0;
		}
		else
			i++;
	}
	return (strings);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		i;
	int		samount;

	i = 0;
	if (!s)
		return (NULL);
	samount = ft_stra(s, c);
	if (samount == 0)
		return (NULL);
	strings = (char **)malloc(sizeof(char *) * (samount + 1));
	if (!strings)
		return (NULL);
	strings = ft_mal(strings, s, c, i);
	if (!strings)
		return (NULL);
	strings[samount] = NULL;
	return (strings);
}
