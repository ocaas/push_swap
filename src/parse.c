/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 06:27:22 by olopez-s          #+#    #+#             */
/*   Updated: 2025/06/16 04:07:46 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

char	**ft_split_args(char **av)
{
	int		i;
	char	**split_args;
	int		j;
	int		k;
	char	**temp;

	i = 1;
	split_args = malloc(sizeof(char *) * (ft_content(av) + 1));
	if (!split_args)
		return (0);
	while (av[i])
	{
		temp = ft_split(av[i], ' ');
		while (temp[k])
		{
			split_args[j] = temp[k];
			j++;
			k++;
		}
		k = 0;
		free (temp);
		i++;
	}
	split_args[j] = NULL;
	return (split_args);
}

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


// no int max or int min (in atoi)		tik
//no spaces , there has to be numbers	tik
//at least one number 
//no letters 
// no tenga dos signos solo uno 
// overflow								tik
//no same two numbers
//stack is ramdomized
// convert strings into ints