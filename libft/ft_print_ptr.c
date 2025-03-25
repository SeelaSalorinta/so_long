/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:34:53 by ssalorin          #+#    #+#             */
/*   Updated: 2024/10/04 14:26:04 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_put_ptr(unsigned long long n);

int	ft_print_ptr(unsigned long long ptr)
{
	int	print_len;
	int	check;

	print_len = 0;
	check = ft_print_s("0x");
	if (check == -1)
		return (-1);
	print_len += check;
	check = ft_put_ptr(ptr);
	if (check == -1)
		return (-1);
	print_len += check;
	return (print_len);
}

static int	ft_put_ptr(unsigned long long n)
{
	int	print_len;
	int	check;

	print_len = 0;
	if (n >= 16)
	{
		check = ft_put_ptr(n / 16);
		if (check == -1)
			return (-1);
		print_len += check;
		n = n % 16;
	}
	if (n < 16)
	{
		if (n >= 10 && n <= 15)
			check = ft_print_char(n - 10 + 'a');
		else
			check = ft_print_char(n + '0');
		if (check == -1)
			return (-1);
		print_len += check;
	}
	return (print_len);
}
