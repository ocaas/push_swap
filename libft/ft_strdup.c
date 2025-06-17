/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 05:50:25 by olopez-s          #+#    #+#             */
/*   Updated: 2025/06/17 05:57:45 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int	i;
	
	i = 0;
	dup = malloc(sizeof(char) * ft_strlen(s) + 1);
	if(!dup)
		return(NULL);
	while(s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return(dup);
}