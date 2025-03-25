/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:26:10 by ssalorin          #+#    #+#             */
/*   Updated: 2024/10/04 14:19:23 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_copyline(char *remainder, int line_len)
{
	char	*line;
	int		i;

	i = 0;
	line = malloc(sizeof(char) * (line_len + 1));
	if (!line)
		return (NULL);
	while (i < line_len)
	{
		line[i] = remainder[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_make_line(char **remainder)
{
	int		i;
	char	*temp;
	char	*line;

	i = 0;
	if (!*remainder || !**remainder)
		return (ft_free(remainder));
	while (remainder[0][i] && remainder[0][i] != '\n')
		i++;
	if (remainder[0][i] == '\n')
		i++;
	line = ft_copyline(*remainder, i);
	if (!line)
		return (ft_free(remainder));
	temp = ft_strdup(*remainder + i);
	if (!temp)
	{
		free(line);
		return (ft_free(remainder));
	}
	free(*remainder);
	*remainder = temp;
	return (line);
}

static char	*ft_save_remainder(char **remainder, char *buffer, int bytes_read)
{
	char	*temp;
	int		i;

	i = 0;
	while (remainder[0][i])
		i++;
	temp = malloc(sizeof(char) * (i + bytes_read + 1));
	if (!temp)
		return (NULL);
	ft_strcpy(temp, *remainder);
	ft_strcat(temp, buffer);
	free(*remainder);
	*remainder = temp;
	return (*remainder);
}

static char	*ft_read_to_remainder(char **remainder, int fd, char *buffer)
{
	int	bytes_read;

	bytes_read = 0;
	while (!ft_strchr(*remainder, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (ft_free(remainder));
		}
		if (bytes_read == 0)
			return ("");
		buffer[bytes_read] = '\0';
		if (!*remainder)
			*remainder = ft_strdup(buffer);
		else
			ft_save_remainder(remainder, buffer, bytes_read);
		if (!*remainder)
		{
			free(buffer);
			return (ft_free(remainder));
		}
	}
	return (*remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder[OPEN_MAX] = {0};
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&remainder[fd]));
	if (!ft_read_to_remainder(&remainder[fd], fd, buffer))
		return (NULL);
	free(buffer);
	return (ft_make_line(&remainder[fd]));
}
