/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:50:41 by ssalorin          #+#    #+#             */
/*   Updated: 2024/04/17 08:54:43 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	unsigned char	mychar;

	mychar = c;
	if (mychar >= 'A' && mychar <= 'Z')
		return (mychar + 32);
	else
		return (c);
}
