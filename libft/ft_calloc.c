/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:36:07 by ssalorin          #+#    #+#             */
/*   Updated: 2024/05/14 13:44:08 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	if (count != 0 && (SIZE_MAX / count) < size)
		return (NULL);
	s = (void *)malloc(count * size);
	if (!s)
		return (NULL);
	ft_bzero(s, (count * size));
	return (s);
}
