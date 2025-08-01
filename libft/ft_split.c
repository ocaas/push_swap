/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 02:34:07 by olopez-s          #+#    #+#             */
/*   Updated: 2025/06/14 20:18:45 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **matrix, int cont)
{
	int	i;

	i = 0;
	while (i < cont)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

static int	ft_words(char *s, char c)
{
	int	i;
	int	flag;
	int	cont;

	i = 0;
	flag = 0;
	cont = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 0)
		{
			flag = 1;
			cont++;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	return (cont);
}

static int	ft_word_len(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		i;
	int		j;
	int		num_words;

	i = 0;
	j = 0;
	num_words = ft_words((char *)s, c);
	matrix = (char **)malloc((num_words + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			matrix[j] = ft_substr(s, i, ft_word_len((char *)s + i, c));
			if (!matrix[j])
				return (ft_free(matrix, num_words), NULL);
			i += ft_word_len((char *)s + i, c);
			j++;
		}
		else
			i++;
	}
	return (matrix[j] = NULL, matrix);
}
