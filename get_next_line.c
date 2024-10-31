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

void	*ft_calloc(size_t nelem, size_t elsize)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(nelem * elsize);
	if (ptr == NULL)
		return (NULL);
	while (i < (nelem * elsize))
		ptr[i++] = 0;
	return (ptr);
}

char	*free_buf(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(char *s, int c)
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


char	*ft_strjoin(char *s1, char *s2)
{
	char	*strjoin;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	strjoin = (char *)malloc((ft_strlen(s2) + ft_strlen(s1) + 1) * sizeof(char));
	if (strjoin == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i])
			strjoin[i] = s1[i];
	while (s2[j])
		strjoin[i++] = s2[j++];
	strjoin[ft_strlen(s1) + ft_strlen(s2)] = '\0';	
	free(s1);
	return (strjoin);
}



char	*pillar_linea(char *memory, int fd)
{
	char	*buf;
    int		byte;

	byte = 1;
	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	while (byte > 0)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte > 0)
		{
			buf[byte] = '\0';
			memory = ft_strjoin(memory, buf);
			if (ft_strchr(memory, '\n'))
			break ;
		}
		if (byte  == -1)
		{
			free(memory);
			free(buf);
			return (NULL);
		}
	}
	
	
	free(buf);
	return (memory);
}

int	contar_elementos(char *memory)
{
	int	i;

	i = 0;
	while (memory[i] != '\0')
	{
		if (memory[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}


char	*dame_linea(char *memory)
{
	int	n;
	char *line;

	if (!memory || memory[0] == '\0')
		return (NULL);
	n = contar_elementos(memory);
	line = (char *)malloc((n + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line  = ft_substr(memory, 0, (size_t)n);
	if (ft_strchr(memory, '\n'))
		memory = ft_substr(memory, n, ft_strlen(memory));
	else
		free(memory);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*memory;

	memory = NULL;
	if (fd < 0)
		return (NULL);
	if ((memory && !ft_strchr(memory, '\n')) || !memory)
		memory = pillar_linea(memory, fd);
	line = dame_linea(memory);
	if (!line)
		return (free_buf(&memory));
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Uso: %s <nombre_del_archivo>\n", argv[0]);
        return (1);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error al abrir el archivo");
        return (1);
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); // Liberar la memoria de la línea leída
    }

    close(fd);
    return (0);
}

*/