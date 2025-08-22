/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 03:31:35 by olopez-s          #+#    #+#             */
/*   Updated: 2025/08/21 05:50:45 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include "../libft/libft.h"

void	three_nums(t_stack **stack)
{
	int	one;
	int	two;
	int	three;

	one = (*stack)->content;
	two = (*stack)->next->content;
	three = (*stack)->next->next->content;
	if (one < two && two > three && one < three)
		sa(stack);
	else if (one > two && one > three)
	{
		ra(stack);
		if (one > two)
			sa(stack);
	}
	else if (one < two && two > three)
	{
		rra(stack);
		if (one > three)
			sa(stack);
	}
}

int	smallest(t_stack *stack)
{
	int	i;
	int	s;
	int	p;

	p = 0;
	i = 0;
	s = stack->content;
	while (stack)
	{
		if (s > stack->content)
		{
			s = stack->content;
			p = i;
		}
		i++;
		stack = stack->next;
	}
	return (p);
}

void	four_nums(t_stack **a, t_stack **b)
{
	int	pst;

	pst = smallest(*a);
	if (pst == 3)
		rra(a);
	else if (pst == 1 || pst == 2)
	{
		while (pst)
		{
			ra(a);
			pst--;
		}
	}
	pb(a, b);
	three_nums(a);
	pa(a, b);
}

void	five_nums(t_stack **a, t_stack **b)
{
	int	pst;

	pst = smallest(*a);
	if (pst == 1 || pst == 2)
	{
		while (pst)
		{
			ra(a);
			pst--;
		}
	}
	else if (pst >= 3)
	{
		while (pst < 5)
		{
			rra(a);
			pst++;
		}
	}
	pb(a, b);
	four_nums(a, b);
	pa(a, b);
}

void	six_nums(t_stack **a, t_stack **b)
{
	int post;

	post = smallest(*a);
	if(post >= 1 && post <= 3)
	{
		while(post)
		{
			ra(a);
			post--;
		}
	}
	else if (post >= 4 && post <= 5)
	{
		while(post < 6)
		{
			rra(a);
			post++;
		}
	}
	pb(a, b);
	five_nums(a, b);
	pa(a, b);
}
	
