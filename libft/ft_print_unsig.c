/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:36:30 by ssalorin          #+#    #+#             */
/*   Updated: 2024/05/22 13:36:49 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_unsig(unsigned int n)
{
	int	print_len;
	int	check;

	print_len = 0;
	if (n >= 10)
	{
		check = ft_print_unsig(n / 10);
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
