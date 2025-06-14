/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:13:53 by olopez-s          #+#    #+#             */
/*   Updated: 2025/06/14 20:22:00 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	ft_content(char **av)
{
	int		i;
	char	**temp;
	int		t;
	int		c;

	i = 1;
	while (av[i])
	{
		temp = ft_split_args(av[i], ' ');
		while (temp[t])
		{
			c++;
			t++;
		}
		t = 0;
		free (temp);
		i++;
	}
	return (t);
}
