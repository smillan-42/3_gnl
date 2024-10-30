/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smillan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:49:13 by smillan-          #+#    #+#             */
/*   Updated: 2024/10/30 16:49:14 by smillan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	encontrar(char const *s, char c, int i, int k)
{
	size_t	sol;

	sol = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			if (k)
			{
				k = 0;
				sol++;
			}
			i++;
		}
		k = 1;
	}
	return (sol);
}

static void	*free_mem(char **cad, int aux)
{
	while (aux >= 0)
	{
		free(cad[aux]);
		aux--;
	}
	free(cad);
	return (NULL);
}

char	**crear_mini(char const *s, char c, char **cad, int aux)
{
	int	i;
	int	j;
	int	stat;

	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			return (cad[aux] = NULL, cad);
		j = i;
		while (c != s[i] && s[i] != '\0')
			i++;
		cad[aux] = (char *)malloc((i - j + 1) * sizeof(char));
		if (!cad[aux])
			return (free_mem(cad, aux));
		stat = j;
		while (i > j++)
			cad[aux][j - stat - 1] = s[j - 1];
		cad[aux][j - stat - 1] = '\0';
		aux++;
	}
	cad[aux] = NULL;
	return (cad);
}

char	**ft_split(char const *s, char c)
{
	char	**cad;
	size_t	num_cad;

	if (!s)
		return (NULL);
	num_cad = encontrar(s, c, 0, 1) + 1;
	cad = (char **)malloc(num_cad * sizeof(char *));
	if (!cad)
		return (NULL);
	cad = crear_mini(s, c, cad, 0);
	return (cad);
}
