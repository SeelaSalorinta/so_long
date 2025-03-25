/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:22:22 by ssalorin          #+#    #+#             */
/*   Updated: 2024/05/09 12:58:54 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = n * -1;
	}
	while (n >= 10)
	{
		count++;
		n = n / 10;
	}
	if (n < 10)
		count++;
	return (count);
}

static char	*ft_finish(char *string, int i, int len, int n)
{
	string[len] = '\0';
	len--;
	while (len >= i)
	{
		string[len] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (string);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*string;

	i = 0;
	len = ft_count(n);
	if (n == -2147483648)
		len = 11;
	string = malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	if (n == -2147483648)
	{
		string[i++] = '-';
		string[i++] = '2';
		n = 147483648;
	}
	if (n < 0)
	{
		string[i++] = '-';
		n = n * -1;
	}
	return (ft_finish(string, i, len, n));
}
