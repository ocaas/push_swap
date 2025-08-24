/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 22:36:24 by olopez-s          #+#    #+#             */
/*   Updated: 2025/08/21 22:37:13 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include "../libft/libft.h"

int	stcksize(t_stack *stack)
{
	int	c;

	c = 0;
	while (stack)
	{
		c++;
		if(c > 10000000)
			exit(2);
		stack = stack->next;
	}
	return (c);
}