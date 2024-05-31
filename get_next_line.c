/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:54:56 by ubuntu            #+#    #+#             */
/*   Updated: 2024/05/31 15:57:52 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strncat(char *dest, char *src, int n_byte)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] && j < n_byte)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_realoc(char *src, int size)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * (size + 1));
	if (!dest)
	{
		if (src)
			free(src);
		return (NULL);
	}
	if (!src)
	{
		dest[0] = '\0';
		return (dest);
	}
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	free(src);
	return (dest);
}

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	char	str[BUFFER_SIZE];
	char	*dest;
	int		size;
	int		n_byte;
	int		tot_size;

	dest = NULL;
	size = BUFFER_SIZE / 2;
	n_byte = 1;
	while (n_byte > 0)
	{
		n_byte = read(fd, str, BUFFER_SIZE);
		tot_size = tot_size + n_byte;
		if (tot_size > size || !dest)
		{
			size *= 2;
			dest = ft_realoc(dest, size);
			if (!dest)
				return (NULL);
		}
		if (n_byte > 0)
			ft_strncat(dest, str, n_byte);
	}
	return (dest);
}
