/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 02:34:07 by olopez-s          #+#    #+#             */
/*   Updated: 2025/06/02 13:28:10 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_arg_split(char **argv)
{
	int		i;
	int		j;
	int		k;
	char	**temp;
	char	**split_args;

	i = 1;
	k = 0;
	split_args = malloc(sizeof(char *) * (ft_count_arg(argv) + 1));
	if (!split_args)
		return (NULL);
	while (argv[i])
	{
		j = 0;
		temp = ft_split(argv[i], ' ');
		while (temp[j])
		{
			split_args[k] = ft_strdup(temp[j]);
			free(temp[j++]);
			k++;
		}
		free(temp);
		i++;
	}
	return (split_args[k] = NULL, split_args);
}

int	ft_arg_count(char **av)
{
	
}
