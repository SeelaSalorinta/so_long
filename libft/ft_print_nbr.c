/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:35:59 by ssalorin          #+#    #+#             */
/*   Updated: 2024/10/09 14:10:25 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_max(void)
{
	int	check;

	check = ft_print_s("-2147483648");
	if (check == -1)
		return (-1);
	return (check);
}

static int	ft_check_minus(int *n)
{
	int	check;

	check = 0;
	if (*n < 0)
	{
		check = ft_print_char('-');
		if (check == -1)
			return (-1);
		*n = -(*n);
	}
	return (check);
}

int	ft_print_nbr(int n)
{
	int	print_len;
	int	check;

	print_len = 0;
	if (n == -2147483648)
		return (ft_check_max());
	check = ft_check_minus(&n);
	if (check == -1)
		return (-1);
	print_len += check;
	if (n >= 10)
	{
		check = ft_print_nbr(n / 10);
		if (check == -1)
			return (-1);
		print_len += check;
		n = n % 10;
	}
	check = ft_print_char(n + '0');
	if (check == -1)
		return (-1);
	print_len += check;
	return (print_len);
}
