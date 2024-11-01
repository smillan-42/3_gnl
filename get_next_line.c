#include "get_next_line.h"

char	*pillar_linea(char *memory, int fd)
{
	char	*buf;
	int		byte;

	byte = 1;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (byte > 0)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte > 0)
		{
			buf[byte] = '\0';
			memory = ft_strjoin(memory, buf);
			if (ft_strchr(memory, '\n', 0))
			    break ;
		}
		if (byte  == -1)
            return (free(memory), free(buf), NULL);
	}
	free(buf);
	return (memory);
}

char	*dame_linea(char *memory)
{
	int	n;
	char	*line;

	if (!memory || memory[0] == '\0')
		return (NULL);
	n = contar_elementos(memory);
	line = (char *)malloc((n + 1));
	if (!line)
		return (NULL);
	line  = ft_substr(memory, 0, (size_t)(n+1));
	return (line);
}

char	*buena_memoria(char *memory)
{
	int	n;
	char	*new_memory;

	n = contar_elementos(memory);
	if (!memory || memory[0] == '\0' || memory[n] == '\0')
		return (NULL);
	new_memory = ft_substr(memory, n+1, ft_strlen(memory));
	free(memory);
	return (new_memory);
}

char	*get_next_line(int fd)
{
	char	*line;
	static char	*memory;

	if (fd < 0)
		return (NULL);
	if ((memory && !ft_strchr(memory, '\n', 0)) || !memory)
		memory = pillar_linea(memory, fd);
	line = dame_linea(memory);
	if (!line)
		return (free(line), free(memory), NULL);
	memory = buena_memoria(memory);
	return (line);
}
