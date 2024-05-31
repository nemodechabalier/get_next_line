/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:54:56 by ubuntu            #+#    #+#             */
/*   Updated: 2024/05/31 17:11:33 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strncat(char *buffer, char *src, int n_byte)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i])
		i++;
	while (src[j] && j < n_byte)
	{
		buffer[i + j] = src[j];
		j++;
	}
	buffer[i + j] = '\0';
	return (buffer);
}

char	*ft_realoc(char *src, int size)
{
	char	*buffer;
	int		i;

	i = 0;
	buffer = malloc(sizeof(char) * (size + 1));
	if (!buffer)
	{
		if (src)
			free(src);
		return (NULL);
	}
	if (!src)
	{
		buffer[0] = '\0';
		return (buffer);
	}
	while (src[i])
	{
		buffer[i] = src[i];
		i++;
	}
	buffer[i] = '\0';
	free(src);
	return (buffer);
}

char	*get_next_line_all(int fd)
{
	char	str[BUFFER_SIZE];
	char	*buffer;
	int		size;
	int		n_byte;
	int		tot_size;

	buffer = NULL;
	tot_size = 0;
	size = BUFFER_SIZE / 2;
	n_byte = 1;
	while (n_byte > 0)
	{
		n_byte = read(fd, str, BUFFER_SIZE);
		str[n_byte] = '\0';
		tot_size = tot_size + n_byte;
		if (tot_size > size || !buffer)
		{
			size *= 2;
			buffer = ft_realoc(buffer, size);
			if (!buffer)
				return (NULL);
		}
		ft_strncat(buffer, str, n_byte);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (get_next_line_all(fd));
}