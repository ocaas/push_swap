/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 02:54:17 by olopez-s          #+#    #+#             */
/*   Updated: 2025/06/30 15:33:31 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static void	ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
}

void	ra(t_stack **a)
{
	ft_rotate (a);
	ft_putstr_fd ("ra\n", 1);
}

void	rb(t_stack **b)
{
	ft_rotate (b);
	ft_putstr_fd ("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	ft_rotate (a);
	ft_rotate (b);
	ft_putstr_fd ("rr\n", 1);
}
