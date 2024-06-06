/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:52:15 by nde-chab          #+#    #+#             */
/*   Updated: 2024/06/06 14:27:03 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_creat_save(char *save)
{
	int		i;
	int		lenth;
	char	*rest;

	rest = NULL;
	i = 0;
	lenth = ft_strlen(save);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	if (i < lenth)
	{
		rest = ft_str_calloc(lenth - i + 1);
		if (!rest)
			return (NULL);
		rest = ft_strncpy(rest, save + i, lenth - i);
		free(save);
		return (rest);
	}
	else
		return (free(save), ft_str_calloc(1));
}

char	*ft_creat_line(char *save)
{
	int		i;
	char	*line;

	line = NULL;
	i = 0;
	if (save[0] == 0)
		return (free(save), NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	line = ft_str_calloc(i + 1);
	if (!line)
		return (free(save), NULL);
	line = ft_strncpy(line, save, i);
	return (line);
}

char	*ft_creat_buffer(int fd, char *save)
{
	char	*buffer;
	int		nb_bytes;

	nb_bytes = 1;
	buffer = ft_str_calloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!save)
	{
		save = ft_str_calloc(1);
		if (!save)
			return (free(buffer), NULL);
	}
	while (ft_str_return(save) == 0 && nb_bytes > 0)
	{
		nb_bytes = read(fd, buffer, BUFFER_SIZE);
		if (nb_bytes > 0)
		{
			buffer[nb_bytes] = 0;
			save = ft_strjoin(save, buffer);
			if (!save)
				return (free(buffer), NULL);
		}
	}
	return (free(buffer), save);
}

char	*get_next_line(int fd)
{
	static char	*save[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (save[fd])
			free(save[fd]);
		return (save[fd] = NULL, NULL);
	}
	save[fd] = ft_creat_buffer(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = ft_creat_line(save[fd]);
	if (!line)
		return (save[fd] = NULL, NULL);
	save[fd] = ft_creat_save(save[fd]);
	if (!save[fd])
		return (free(line), NULL);
	return (line);
}
