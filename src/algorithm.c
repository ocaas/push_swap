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
	return (i - 1);
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

static int	first_pos(t_stack *a, int lim)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->index <= lim)
			return (i);
		i++;
		a = a->next;
	}
	return (-1);
}

static int	rra_dist(t_stack *a, int lim)
{
	int	seen;
	int	trail;

	seen = 0;
	trail = 0;
	while (a)
	{
		if (a->index <= lim)
		{
			seen = 1;
			trail = 0;
		}
		else if (seen)
			trail++;
		a = a->next;
	}
	if (!seen)
		return (-1);
	return (trail + 1);
}

static int	rotate_nearest_a(t_stack **a, int lim)
{
	int	f;
	int	r;
	int	k;

	f = first_pos(*a, lim);
	r = rra_dist(*a, lim);
	if (f < 0 && r < 0)
		return (0);
	if (r >= 0 && (f < 0 || r < f))
	{
		k = r;
		while (k-- > 0)
			rra(a);
	}
	else
	{
		k = f;
		while (k-- > 0)
			ra(a);
	}
	return (1);
}

void	ft_sort_groups(t_stack **a, t_stack **b, int n_arg)
{
	int	range;
	int	i;

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
		else if (!rotate_nearest_a(a, i + range))
			i += range;
	}
}

static int	ft_biggest_index(t_stack *s)
{
	int	big;
	int	pos;
	int	i;

	big = s->index;
	pos = 0;
	i = 0;
	while (s)
	{
		if (s->index > big)
		{
			big = s->index;
			pos = i;
		}
		s = s->next;
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
		if (pos <= size / 2)
			while (pos-- > 0)
				rb(b);
		else
			while (pos++ < size)
				rrb(b);
		pa(a, b);
	}
}

