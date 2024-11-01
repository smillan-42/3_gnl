/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smillan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:33:48 by smillan-          #+#    #+#             */
/*   Updated: 2024/10/30 16:48:44 by smillan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*pillar_linea(char *memory, int fd);
char	*dame_linea(char *memory);
char	*ft_strjoin(char *s1, char *s2);
int	ft_strchr(char *s, int c, size_t min);
size_t	ft_strlen(char *s);
int	contar_elementos(char *memory);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
