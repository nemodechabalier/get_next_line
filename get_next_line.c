/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:52:15 by nde-chab          #+#    #+#             */
/*   Updated: 2024/06/04 19:36:08 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_creat_line(char *str, char *rest, int n)
{
	char	*line;
	int		i;

	i = 0;
	if (!str || (str[0] == '\0' && n == 0))
		return (free(str), NULL);
	while (str[i] && str[i] != '\n')
		i++;
	i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (free(str), NULL);
	line[0] = '\0';
	line = ft_bzero(line, i + 1);
	line = ft_strncpy(line, str, i);
	if (i < ft_strlen(str))
		rest = ft_strncpy(rest, str + i, BUFFER_SIZE);
	free(str);
	return (line);
}

char	*ft_creat_buffer(int fd, char *rest)
{
	int		i;
	char	*buffer;
	char	*str;

	str = malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return(free(str),NULL);
	str[0] = 0;
	ft_bzero(buffer, BUFFER_SIZE + 1);
	i = 1;
	if (rest[0] != '\0')
		str = ft_strjoin(str, rest);
	rest = ft_bzero(rest, BUFFER_SIZE + i);
	while (ft_str_return(str) == 0 && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		str = ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
		ft_bzero(buffer, BUFFER_SIZE + 1);
	}
	return (free(buffer),ft_creat_line(str, rest, i));
}

char	*get_next_line(int fd)
{
	static char	rest[BUFFER_SIZE + 1] = {0};

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0))
		return (NULL);
	return (ft_creat_buffer(fd, rest));
}
