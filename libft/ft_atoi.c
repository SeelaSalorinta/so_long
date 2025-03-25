/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:45:41 by ssalorin          #+#    #+#             */
/*   Updated: 2024/05/16 09:42:48 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			a;
	int			sign;
	long long	nbr;

	a = 0;
	sign = 1;
	nbr = 0;
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == 32)
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			sign = -sign;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		if (sign == 1 && (nbr > (LONG_MAX - (str[a] - '0')) / 10))
			return (-1);
		else if (sign == -1 && (-nbr < (LONG_MIN + (str[a] - '0')) / 10))
			return (0);
		nbr = nbr * 10 + (str[a] - '0');
		a++;
	}
	return (sign * nbr);
}
