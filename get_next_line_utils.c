#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}


char	*ft_strjoin(char *s1, char *s2)
{
	char	*strjoin;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (!s1 )
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	strjoin = (char *)malloc((ft_strlen(s2) + ft_strlen(s1) + 1));
	if (strjoin == NULL)
		return (free(s1), NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		strjoin[i] = s1[i];
	while (s2[j])
		strjoin[i++] = s2[j++];
	strjoin[i] = '\0';	
	return (free(s1), strjoin);
}

int	ft_strchr(char *s, int c, size_t min)
{
	size_t	i;

	i = ft_strlen(s);
	while (i > min)
	{
		if (s[i] == (unsigned char)c)
			return (1); // encuentra c
		i--;
	}
	if (s[min] == (unsigned char)c)
		return (1);
	return (0); // No encuentra c
}

/*----------------------------------------------------*/

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

void	ft_copy(char *dst, char *src, size_t start, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && src[start + i] != '\0')
	{
		dst[i] = src[i + start];
		i++;
	}
	dst[size] = '\0';
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	tam;
	char	*ptr;

	tam = ft_strlen(s);
	if (s == NULL )
		return (NULL);
	if (start > tam)
		len = 0;
	else if (tam < start + len)
		len = tam - start;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	ft_copy(ptr, s, start, len);
	return (ptr);
}
