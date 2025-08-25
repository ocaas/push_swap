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

int	ft_stksize(t_stack *s)
{
	int	n;

	n = 0;
	while (s)
	{
		n++;
		s = s->next;
	}
	return (n);
}

/* static int	tail_in_window(t_stack *a, int lim)
{
	while (a && a->next)
		a = a->next;
	if (!a)
		return (0);
	return (a->index <= lim);
} */
static int	nearest_pos(t_stack *a, int lim)
{
	int		n;
	int		i;
	int		first;
	int		last;
	t_stack	*p;

	n = ft_stksize(a);
	first = -1;
	last = -1;
	i = 0;
	p = a;
	while (p)
	{
		if (p->index <= lim)
		{
			if (first < 0)
				first = i;
			last = i;
		}
		i++;
		p = p->next;
	}
	if (first < 0)
		return (-1000000);
	if (first <= n - 1 - last)
		return (first);
	return (-(n - last));
}

void	ft_sort_groups(t_stack **a, t_stack **b, int n_arg)
{
	int	range;
	int	i;
	int	pos;
	int	k;

	range = (ft_sqrt(n_arg) * 133) / 100;
	if (range < 1)
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
		{
			pos = nearest_pos(*a, i + range);
			if (pos == -1000000)
			{
				i += range; /* open next chunk when window empty */
				continue ;
			}
			if (pos >= 0)
			{
				k = pos;
				while (k-- > 0)
					ra(a);
			}
			else
			{
				k = -pos;
				while (k-- > 0)
					rra(a);
			}
		}
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


