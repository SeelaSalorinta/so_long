/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:21:04 by ssalorin          #+#    #+#             */
/*   Updated: 2024/05/08 16:28:23 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	mychar;
	size_t			i;

	mychar = c;
	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = mychar;
		i++;
	}
	return (b);
}
