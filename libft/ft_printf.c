/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:46:55 by ssalorin          #+#    #+#             */
/*   Updated: 2024/06/20 16:23:29 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_format(va_list a_list, const char format);
static int	ft_check_is_minus(va_list a_list);

int	ft_printf(const char *str, ...)
{
	int		i;
	int		print_len;
	int		check;
	va_list	a_list;

	i = 0;
	print_len = 0;
	va_start(a_list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			check = ft_format(a_list, str[i + 1]);
			i++;
		}
		else
			check = ft_print_char(str[i]);
		if (check == -1)
			return (ft_check_is_minus(a_list));
		print_len += check;
		i++;
	}
	va_end(a_list);
	return (print_len);
}

static int	ft_format(va_list a_list, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_print_char(va_arg(a_list, int));
	else if (format == 'p')
		print_len += ft_print_ptr(va_arg(a_list, unsigned long long));
	else if (format == 's')
		print_len += ft_print_s(va_arg(a_list, char *));
	else if (format == 'd' || format == 'i')
		print_len += ft_print_nbr(va_arg(a_list, int));
	else if (format == 'u')
		print_len += ft_print_unsig(va_arg(a_list, unsigned int));
	else if (format == 'x' || format == 'X')
		print_len += ft_print_hex(va_arg(a_list, unsigned int), format);
	else if (format == '%')
		print_len += ft_print_char('%');
	return (print_len);
}

static int	ft_check_is_minus(va_list a_list)
{
	va_end(a_list);
	return (-1);
}
