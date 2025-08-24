/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:26:44 by olopez-s          #+#    #+#             */
/*   Updated: 2025/08/21 22:31:43 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include "../libft/libft.h"

static int	ft_sqrt(int n)
{
	int	i;

	i = 0;
	while ((i * i) <= n)
		i++;
	i--;
	return (i);
}

void	ft_sort_groups(t_stack **a, t_stack **b, int n_arg)
{
	int	range;
	int	i;

	range = (ft_sqrt(n_arg) * 133) / 100;
	if(range < 1)
		range = 1;
	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if ((*a)->index <= i + range)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
}

static int	ft_biggest_index(t_stack *stack)
{
	int	biggest;
	int	pos;
	int	i;

	biggest = stack->index;
	pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->index > biggest)
		{
			biggest = stack->index;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}

static int	ft_stksize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	ft_sort_back(t_stack **a, t_stack **b)
{
	int	pos;
	int	size;

	while (*b)
	{
		pos = ft_biggest_index(*b);
		size = ft_stksize(*b);
		if (pos <= (size / 2))
		{
			while (pos-- > 0)
				rb(b);
		}
		else
		{
			while (pos++ < size)
				rrb(b);
		}
		pa(a, b);
	}
}
