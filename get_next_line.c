/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:54:56 by ubuntu            #+#    #+#             */
/*   Updated: 2024/05/31 15:24:58 by ubuntu           ###   ########.fr       */
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
		return (NULL);
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
	char	str[BUFFER_SIZE];
	char	*dest;
	int		size;
	int		n_byte;
	int		tot_size;

	size = BUFFER_SIZE;
	n_byte = read(fd, str, BUFFER_SIZE);
	tot_size = n_byte;
	dest = malloc(sizeof(char) * BUFFER_SIZE + 1);
	dest[0] = '\0';
	while (n_byte > 0)
	{
		if (tot_size > size)
		{
			size *= 2;
			dest = ft_realoc(dest, size);
			if (!dest)
				return (NULL);
		}
		ft_strncat(dest, str, n_byte);
		n_byte = read(fd, str, BUFFER_SIZE);
		tot_size = tot_size + n_byte;
	}
	return (dest);
}
