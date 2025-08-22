/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 04:55:15 by olopez-s          #+#    #+#             */
/*   Updated: 2025/08/13 04:25:31 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static void	ft_reverse(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **a)
{
	ft_reverse (a);
	ft_putstr_fd ("rra\n", 1);
}

void	rrb(t_stack **b)
{
	ft_reverse (b);
	ft_putstr_fd ("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	ft_reverse (a);
	ft_reverse (b);
	ft_putstr_fd ("rrr\n", 1);
}
