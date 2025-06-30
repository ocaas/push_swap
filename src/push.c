/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 04:32:21 by olopez-s          #+#    #+#             */
/*   Updated: 2025/06/25 18:23:54 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"


static void	ft_push(t_stack **from, t_stack **to)
{
	t_stack	*temp;

	if (!from || !(*from))
		return ;
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
}

void	pa(t_stack **a, t_stack **b)
{
	ft_push(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **a, t_stack **b)
{
	ft_push(a, b);
	ft_putstr_fd("pb\n", 1);
}
