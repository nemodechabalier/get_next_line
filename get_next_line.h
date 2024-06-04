/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:52:13 by ubuntu            #+#    #+#             */
/*   Updated: 2024/06/04 19:28:04 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char					*get_next_line(int fd);
char					*ft_strncpy(char *buffer, char *src, int size);
char					*ft_strjoin(char *s1, char *s2);
int						ft_str_return(char *str);
char					*ft_bzero(char *s, size_t n);
int						ft_strlen(char *str);

typedef unsigned char	t_byte;

#endif