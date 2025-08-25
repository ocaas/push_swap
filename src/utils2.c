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
/*
int	stksize(t_stack *s)
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

void	rotate_a_to_top(t_stack **a, int pos)
{
	int	size;

	if (!a || !*a)
		return ;
	size = stksize(*a);
	if (pos <= 0 || size <= 1)
		return ;
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(a);
	else
		while (pos++ < size)
			rra(a);
}

void	rotate_b_to_top(t_stack **b, int pos)
{
	int	size;

	if (!b || !*b)
		return ;
	size = stksize(*b);
	if (pos <= 0 || size <= 1)
		return ;
	if (pos <= size / 2)
		while (pos-- > 0)
			rb(b);
	else
		while (pos++ < size)
			rrb(b);
}
int	index_of_max(t_stack *b)
{
	int		i;
	int		best_i;
	int		best;
	t_stack	*p;

	if (!b)
		return (-1);
	i = 0;
	best_i = 0;
	best = b->content;
	p = b;
	while (p)
	{
		if (p->content > best)
		{
			best = p->content;
			best_i = i;
		}
		i++;
		p = p->next;
	}
	return (best_i);
}

int	b_insert_pos_desc(t_stack *b, int v)
{
	int		i;
	int		first;
	int		cur;
	int		nxt;

	if (!b)
		return (0);
	i = 0;
	first = b->content;
	while (b)
	{
		cur = b->content;
		nxt = (b->next) ? b->next->content : first;
		if (cur >= v && v >= nxt)
			return ((b->next) ? i + 1 : 0);
		if (cur < nxt && (v > cur || v < nxt))
			return ((b->next) ? i + 1 : 0);
		i++;
		b = b->next;
	}
	return (0);
}

int	nearest_in_window(t_stack *a, int win_end)
{
	int	front;
	int	back;
	int	i;
	int	n;
	t_stack	*p;

	n = stksize(a);
	front = -1;
	back = -1;
	i = 0;
	p = a;
	while (p)
	{
		if (p->index <= win_end)
		{
			if (front < 0)
				front = i;
			back = i;
		}
		i++;
		p = p->next;
	}
	if (front < 0)
		return (-1);
	if (front <= n - 1 - back)
		return (front);
	return (back);
}

void	ft_sort_groups(t_stack **a, t_stack **b, int n_arg)
{
	int	win_end;
	int	step;
	int	pos;
	int	ins;

	if (!a || !*a)
		return ;
	//window ~ 1.33 * sqrt(n) 
	step = (ft_sqrt(n_arg) * 133) / 100;
	if (step < 1)
		step = 1;
	win_end = step - 1;
	while (*a)
	{
		if ((*a)->index <= win_end)
		{
			ins = b_insert_pos_desc(*b, (*a)->content);
			rotate_b_to_top(b, ins);
			pb(a, b);
		}
		else
		{
			pos = nearest_in_window(*a, win_end);
			if (pos < 0)
				win_end += step;
			else
				rotate_a_to_top(a, pos);
		}
	}
}

void	ft_sort_back(t_stack **a, t_stack **b)
{
	int	pos;
	int	size;

	if (!b || !*b)
		return ;
	while (*b)
	{
		size = stksize(*b);
		pos = index_of_max(*b);
		if (pos <= size / 2)
			while (pos-- > 0)
				rb(b);
		else
			while (pos++ < size)
				rrb(b);
		pa(a, b);
	}
}
*/