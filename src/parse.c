/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 06:27:22 by olopez-s          #+#    #+#             */
/*   Updated: 2025/07/15 19:51:22 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include "../libft/libft.h"

char	**ft_split_args(char **av)
{
	int		i;
	char	**split_args;
	int		j;
	int		k;
	char	**temp;

	k = 0;
	i = 1;
	while (av[i])
	{
		split_args = malloc(sizeof(char *) * (ft_content(av) + 1));
		if (!split_args)
		{
			ft_free(split_args);
			return (NULL);
		}
		temp = ft_split(av[i], ' ');
		j = 0;
		while (temp[j])
		{
			split_args[k] = ft_strdup(temp[j]);
			j++;
			k++;
		}
		ft_free(temp);
		i++;
	}
	split_args[k] = NULL;
	return (split_args);
}

void	ft_free(char **a)
{
	int	i;

	i = 0;
	while(a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
}

/*
int	ft_spaces(char **av)
{
	int	i;

	i = 1;
	if(!av[i])
		return (1);
	while(av)
	{
		if(av[i] == ' ' || (av[i] >= 9 && av[i] <= 13))
			return (0);
		else
			return (1);
		i++;
	}
}
*/

// no int max or int min (in atoi)		tik
//no spaces , there has to be numbers	tik
//at least one number 
//no letters 
// no tenga dos signos solo uno 
// overflow								tik
//no same two numbers
//stack is ramdomized
// convert strings into ints