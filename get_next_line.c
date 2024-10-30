/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smillan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:49:00 by smillan-          #+#    #+#             */
/*   Updated: 2024/10/30 16:49:02 by smillan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == (unsigned char)c)
			return (1); // encuentra c
		i--;
	}
	if (s[0] == (unsigned char)c)
		return (1);
	return (0); // No encuentra c
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	a2;
	size_t	a1;
	int		i;

	i = 0;
	a2 = ft_strlen(s2);
	a1 = ft_strlen(s1);
	ptr = (char *)malloc(a2 + a1 + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[i - a1] != '\0')
	{
		ptr[i] = s2[i - a1];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*free_buf(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*pillar_linea(char *memory, int fd)
{
	char	*buf;
    int		byte;

	byte = 1;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free_buf(&buf));
	while (!ft_strchr(memory, '\n'))
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte > 0)
		{
			buf[byte] = '\0';
			memory = ft_strjoin(memory, buf);
		}
	}
	free(buf);
	if (byte  == -1)
		return (free_buf(&buf));
	return (memory);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*memory;

	if (fd < 0)
		return (NULL);
	if ((memory && !ft_strchr(memory, '\n')) || !memory)
		memory = pillar_linea(memory, fd);
	line = dame_linea()
}
