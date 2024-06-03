/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:52:15 by nde-chab          #+#    #+#             */
/*   Updated: 2024/06/03 17:22:14 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*ft_creat_line(char *str, char *rest)
{
	char	*line;
	int		i;

	i = 0;
	if (str[0] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line[0] = '\0';
	line = ft_strncpy(line, str, i);
	rest = ft_strncpy(rest,str + i, BUFFER_SIZE);
	free(str);
	return (line);
}

char	*ft_creat_buffer(int fd, char *rest)
{
	int		i;
	char	buffer[BUFFER_SIZE + 1];
	char	*str;

	str = malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	i = 1;
	if (rest[0] != '\0')
		return (str = ft_strjoin(str, rest), ft_creat_line(str, rest));
	while (ft_str_return(str) == 0 && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		buffer[i] = '\0';
		str = ft_strjoin(str, buffer);
	}
	return (ft_creat_line(str, rest));
}

char	*get_next_line(int fd)
{
	static char	rest[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0))
		return (NULL);
	return (ft_creat_buffer(fd, rest));
}
