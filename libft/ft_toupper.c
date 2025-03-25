/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:28:13 by ssalorin          #+#    #+#             */
/*   Updated: 2024/04/17 08:40:40 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	unsigned char	mychar;

	mychar = c;
	if (mychar >= 'a' && mychar <= 'z')
		return (mychar - 32);
	else
		return (c);
}
