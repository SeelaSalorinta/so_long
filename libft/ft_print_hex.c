/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:33:56 by ssalorin          #+#    #+#             */
/*   Updated: 2024/05/22 13:34:24 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hex(unsigned int n, const char format)
{
	int	print_len;
	int	check;

	print_len = 0;
	if (n >= 16)
	{
		check = ft_print_hex(n / 16, format);
		if (check == -1)
			return (-1);
		print_len += check;
		n = n % 16;
	}
	if (n >= 10 && n <= 15)
	{
		if (format == 'x')
			check = ft_print_char(n - 10 + 'a');
		else
			check = ft_print_char(n - 10 + 'A');
	}
	else
		check = ft_print_char(n + '0');
	if (check == -1)
		return (-1);
	print_len += check;
	return (print_len);
}
