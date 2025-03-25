/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:37:10 by ssalorin          #+#    #+#             */
/*   Updated: 2024/10/09 13:41:41 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_s(char *s)
{
	int	i;
	int	print_len;
	int	check;

	i = 0;
	print_len = 0;
	if (s == NULL)
	{
		check = ft_print_s("(null)");
		if (check == -1)
			return (-1);
		return (check);
	}
	while (s[i])
	{
		check = ft_print_char(s[i]);
		if (check == -1)
			return (-1);
		print_len += check;
		i++;
	}
	return (print_len);
}
